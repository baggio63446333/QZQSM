#include <Arduino.h>
#include <GNSS.h>
#include <GNSSPositionData.h>
#include <QZQSM.h>
#include <RTC.h>
#include <SpresenseLteTwitter.h>
#include <mqueue.h>
#include <fcntl.h>

// APN data
#define LTE_APN       "apn"
#define LTE_USER_NAME "user"
#define LTE_PASSWORD  "password"

SpresenseLteTwitter twitter("YourToken");

#define GNSS_MSGQ "gnss_msgq"
char g_msg[1024];
struct gnss_msg_s
{
  char *pmsg;
};
mqd_t gnss_mqd;

const int HISTORY_COUNT = 20;
QZQSM s_history[HISTORY_COUNT];
int s_index = 0;

SpGnss Gnss;

int gnss_task(int argc, char *argv[])
{
  /* Initialize GNSS */
  if (Gnss.begin()) {
    Serial.println("begin error!");
  }

  /* select satellite system */
  Gnss.select(GPS);
  Gnss.select(QZ_L1CA);
  Gnss.select(QZ_L1S);

  /* set interval */
  Gnss.setInterval(1);

  /* Start GNSS */
  if (Gnss.start(COLD_START)) {
    Serial.println("start error!");
  }

  mqd_t mqd = mq_open(GNSS_MSGQ, O_WRONLY, 0666, NULL);

  while(1)
    {
      /* Check update. */
      if (Gnss.waitUpdate(1000)) {

        // LED Heartbeat
        static int toggle = 0;
        if (toggle++ % 2) {
          ledOn(LED0);
        } else {
          ledOff(LED0);
        }

        // Get time and position data with QZQSM
        SpNavData NavData;
        Gnss.getNavData(&NavData);

        // Check if UTC time is acquired
        SpGnssTime *time = &NavData.time;
        if (time->year >= 2000) {

          // Time fix
          ledOn(LED1);

          // Convert SpGnssTime to RtcTime
          RtcTime gps(time->year, time->month, time->day,
                      time->hour, time->minute, time->sec, time->usec * 1000);
          // Convert UTC to JST time
          gps += 9 * 60 * 60;

          // Compare with the current time
          RtcTime now = RTC.getTime();
          int diff = now - gps;
          if (abs(diff) >= 1) {
            RTC.setTime(gps);
          }
        }

        // Get DC reoprt
        void *handle = Gnss.getDCReport();
        if (handle) {

          // begin DC report
          ledOn(LED3);

          QZQSM report;

          RtcTime now = RTC.getTime();
          report.SetYear(now.year());

          report.Decode(((struct cxd56_gnss_dcreport_data_s*)handle)->sf);

          int reported = 0;
          int i;
          for (i = 0; i < HISTORY_COUNT; i++) {
            if (s_history[i] == report) {
              reported = 1;
              break;
            }
          }

          if (!reported) {
            /* New report */
            printf("================================ %04d/%02d/%02d %02d:%02d:%02d\n",
                   now.year(), now.month(), now.day(),
                   now.hour(), now.minute(), now.second());

            printf("%s\n", report.GetReport());

            // Send tweet message to another task
            memset(g_msg, 0, sizeof(g_msg));
            sprintf(g_msg, "%s", report.GetReport());
            struct gnss_msg_s msg;
            msg.pmsg = &g_msg[0];
            mq_send(mqd, (const char*)&msg, sizeof(msg), 0);

            s_history[s_index] = report;
            s_index++;
            s_index %= HISTORY_COUNT;
          }
          // end DC report
          ledOff(LED3);
        }
      }
    }
}

void setup()
{
  /* Initialize Serial */
  Serial.begin(115200);

  twitter.begin(LTE_APN, LTE_USER_NAME, LTE_PASSWORD);

  struct mq_attr mq_attr;

  mq_attr.mq_maxmsg  = 1;
  mq_attr.mq_msgsize = sizeof(struct gnss_msg_s);
  mq_attr.mq_flags   = 0;

  gnss_mqd = mq_open(GNSS_MSGQ, O_RDONLY | O_CREAT, 0666, &mq_attr);

  task_create("gnss_task", 100, 4096, gnss_task, NULL);

}

void loop()
{
  struct gnss_msg_s msg;
  for (;;)
    {
      mq_receive(gnss_mqd, (char*)&msg, sizeof(msg), NULL);
      printf("recv\n");
      if (twitter.post(msg.pmsg)) {
        ;
      }
      else {
        Serial.println("connection failed.");
      }
    }
}

