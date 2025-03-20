/*
  Keyes
  mosDoor
  www.keyes-robot.com
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C mylcd(0x27,16,2);
#include "OneButton.h"
// 在Pin16上安装一个新的OneButton.  
OneButton button1(16, true);
// 在Pin27上安装一个新的OneButton.  
OneButton button2(27, true);
#include <ESP32_Servo.h>
Servo myservo;
int servoPin = 13;
String password = "";
String correct_p = "-.-";  //密码门的正确密码

// 安装代码在这里，运行一次:
void setup() {
  Serial.begin(115200);
  mylcd.init();
  mylcd.backlight();
  // 链接按钮1的功能.
  button1.attachClick(click1);
  button1.attachLongPressStop(longPressStop1);
  // 链接按钮2个功能.
  button2.attachClick(click2);
  button2.attachLongPressStop(longPressStop2);

  myservo.attach(servoPin, 500, 2500);
  myservo.write(0);
  mylcd.setCursor(0, 0);
  mylcd.print("Enter password");
}

void loop() {
  // 继续看按钮:
  button1.tick();
  button2.tick();
  delay(10);
}

// ----- 按键1回调函数
// 当button1被按下1次(第2次)时，这个函数将被调用。按钮按下后).
void click1() {
  Serial.print(".");
  password = password + '.';
  mylcd.setCursor(0, 1);
  mylcd.print(password);
} // click1

// 这个函数将被调用一次，当按钮1在长时间按下后被释放时.
void longPressStop1() {
  Serial.print("-");
  password = password + '-';
  mylcd.setCursor(0, 1);
  mylcd.print(password);
} // longPressStop1

// ... 按钮2也是一样:
void click2() {
  Serial.println(password);
  if(password == correct_p)
  {
    myservo.write(180);  //密码正确就开门
    mylcd.clear();
    mylcd.setCursor(0, 0);
    mylcd.print("open");
  }
  else
  {
    mylcd.clear();
    mylcd.setCursor(0, 0);
    mylcd.print("error");
    delay(2000);
    mylcd.clear();
    mylcd.setCursor(0, 0);
    mylcd.print("input again");
  }
  password = "";
} // click2

void longPressStop2() {
  //Serial.println("Button 2 longPress stop");
   myservo.write(0);  //关门
   mylcd.clear();
   mylcd.setCursor(0, 0);
   mylcd.print("close");
} // longPressStop2
