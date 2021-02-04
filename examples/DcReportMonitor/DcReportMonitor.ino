#include <Arduino.h>
#include <GNSS.h>
#include <GNSSPositionData.h>
#include <QZQSM.h>
#include <RTC.h>

const int HISTORY_COUNT = 20;
QZQSM s_history[HISTORY_COUNT];
int s_index = 0;

SpGnss Gnss;

void setup()
{
  /* Initialize Serial */
  Serial.begin(115200);

  Serial.println("DcReportMonitor Example");

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
}

void loop()
{
  /* Check update. */
  if (Gnss.waitUpdate(1000)) {
    RtcTime now;

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
      now = RTC.getTime();
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

      now = RTC.getTime();
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
        char datetime[64];
        snprintf(datetime, sizeof(datetime),
                 "================================ %04d/%02d/%02d %02d:%02d:%02d",
                 now.year(), now.month(), now.day(),
                 now.hour(), now.minute(), now.second());
        Serial.println(datetime);
        Serial.println(report.GetReport());
        s_history[s_index] = report;
        s_index++;
        s_index %= HISTORY_COUNT;
      }

      // end DC report
      ledOff(LED3);
    }
  }
}
