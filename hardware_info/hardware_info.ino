#include <dummy.h>

uint64_t chipid;  

void setup() {
  Serial.begin(115200);
}

void loop() {
  chipid=ESP.getEfuseMac();//The chip ID is essentially its MAC address(length: 6 bytes).
  Serial.printf("ESP32 Chip ID = %04X",(uint16_t)(chipid>>32));//print High 2 bytes
  Serial.printf("%08X\n",(uint32_t)chipid);//print Low 4bytes.

  FlashMode_t ideMode = ESP.getFlashChipMode();
  uint8_t revision = ESP.getChipRevision();
  Serial.print(F("Arduino Core For ESP32 Version: "));
  Serial.println(revision);
  Serial.printf("CPU Freq: %u\n", ESP.getCpuFreqMHz());
  Serial.printf("Flash 实际大小: %u KBytes\n", ESP.getFlashChipSize()/1024);
  Serial.printf("IDE配置Flash大小: %u KBytes,往往小于实际大小\n", ESP.getFlashChipSize()/1024);
  Serial.printf("IDE配置Flash频率 : %u MHz\n", ESP.getFlashChipSpeed()/1000000);
  Serial.printf("Flash ide mode:  %s\n\n", (ideMode == FM_QIO ? "QIO" : ideMode == FM_QOUT ? "QOUT" : ideMode == FM_DIO ? "DIO" : ideMode == FM_DOUT ? "DOUT" : "UNKNOWN"));

  delay(5000);

}
