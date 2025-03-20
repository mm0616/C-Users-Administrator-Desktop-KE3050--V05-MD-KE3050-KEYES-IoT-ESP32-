/*
  Keyes
  lcd
  www.keyes-robot.com
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C mylcd(0x27,16,2);

void setup(){
  mylcd.init();
  mylcd.backlight();
}

void loop(){
  mylcd.setCursor(0, 0);
  mylcd.print("     keyes");
  mylcd.setCursor(0, 1);
  mylcd.print("  Hello, World");
  //mylcd.clear();
}
