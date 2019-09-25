#include <Arduino.h>
#include <QZQSM.h>

void setup()
{
  /* Initialize Serial */
  Serial.begin(115200);

  Serial.println("Please input NMEA sentence that begins with $QZQMS");
}

void loop()
{
  String nmea;
  QZQSM report;

  report.SetYear(2019);

  if (Serial.available() > 0) {
    nmea = Serial.readStringUntil('\n');
    Serial.println(nmea);
    Serial.println("================================");
    report.Decode(nmea.c_str());
    Serial.println(report.GetReport());
  }
}

