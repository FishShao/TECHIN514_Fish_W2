#include <Arduino.h>

const int pinVOUT1 = A1;
const int pinVOUT2 = A0;

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
}

void loop() {
  int raw1 = analogRead(pinVOUT1);
  int raw2 = analogRead(pinVOUT2);

  float volt1 = (raw1 / 4095.0) * 3.3;
  float volt2 = (raw2 / 4095.0) * 3.3;

  Serial.print("VOUT1 (D1): ");
  Serial.print(volt1, 2);
  Serial.print("V | VOUT2 (D0): ");
  Serial.print(volt2, 2);
  Serial.println("V");

  delay(500);
}
