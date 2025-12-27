
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "MPU6050_light.h"

Adafruit_SSD1306 display(128, 64, &Wire);
MPU6050 mpu(Wire);

void setup() {
  Serial.begin(115200);
  Wire.begin();

  // OLED init
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(WHITE);
  
  // MPU init
  mpu.begin();
  delay(1000);
  mpu.calcOffsets();  
}

void loop() {
  mpu.update();

  float x = mpu.getAngleX();     // front/back tilt
  float y = mpu.getAngleY();     // left/right tilt

  // Send data to PC for 3D control
  Serial.print(x);
  Serial.print(",");
  Serial.println(y);

  // Determine orientation label
  String view = "";

  if (x > 20)       view = "BACK VIEW";
  else if (x < -20) view = "FRONT VIEW";
  else if (y > 20)  view = "RIGHT VIEW";
  else if (y < -20) view = "LEFT VIEW";
  else              view = "CENTER";

  // OLED output
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 20);
  display.println(view);
  display.display();

  delay(50);
}
