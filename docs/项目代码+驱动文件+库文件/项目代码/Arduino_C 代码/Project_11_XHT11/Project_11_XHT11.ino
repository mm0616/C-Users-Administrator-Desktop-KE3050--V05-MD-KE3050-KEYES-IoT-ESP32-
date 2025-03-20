/*
  Keyes
  XHT11
  www.keyes-robot.com
*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C mylcd(0x27,16,2);
#include "xht11.h"
xht11 xht(17);

unsigned char dht[4] = {0, 0, 0, 0};//只接收前32位数据，不接收奇偶校验位
void setup() {
  Serial.begin(9600);//启动串口监视器，设置波特率为9600
  mylcd.init();
  mylcd.backlight();
}

void loop() {
  if (xht.receive(dht)) { //选中正确时返回true
    Serial.print("RH:");
    Serial.print(dht[0]); //湿度的积分部分，DHT[1]是分数部分
    Serial.print("%  ");
    Serial.print("Temp:");
    Serial.print(dht[2]); //温度的积分部分，DHT[3]是分数部分
    Serial.println("C");
    
    mylcd.setCursor(0, 0);
    mylcd.print("T = ");
    mylcd.print(dht[2]);
    mylcd.setCursor(7, 0);
    mylcd.print("C ");
    mylcd.setCursor(0, 1);
    mylcd.print("H = ");
    mylcd.print(dht[0]);
    mylcd.setCursor(7, 1);
    mylcd.print("% ");
    //mylcd.clear();
    delay(200);
  } else {    //读取错误
    Serial.println("sensor error");
  }
  delay(1000);  //设备读取的等待时间为1000ms
}
