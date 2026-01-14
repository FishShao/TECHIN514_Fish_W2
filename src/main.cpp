#include <Arduino.h>
// 针对 XIAO-ESP32-C3 的定义
const int pinVOUT1 = A1; // 对应你的 D1
const int pinVOUT2 = A0; // 对应你的 D0

void setup() {
  // 串口监视器波特率
  Serial.begin(115200);
  
  // 设置 ADC 分辨率为 12 位 (0-4095)
  analogReadResolution(12);
}

void loop() {
  // 读取原始 ADC 值
  int raw1 = analogRead(pinVOUT1);
  int raw2 = analogRead(pinVOUT2);

  // 转换为电压 (公式：ADC / 4095 * 3.3)
  float volt1 = (raw1 / 4095.0) * 3.3;
  float volt2 = (raw2 / 4095.0) * 3.3;

  // 输出结果
  Serial.print("VOUT1 (D1): ");
  Serial.print(volt1, 2);
  Serial.print("V | VOUT2 (D0): ");
  Serial.print(volt2, 2);
  Serial.println("V");

  delay(500); // 0.5秒刷新一次
}