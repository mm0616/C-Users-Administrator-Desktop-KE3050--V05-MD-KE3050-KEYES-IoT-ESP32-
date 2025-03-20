/*
  Keyes
  servo
  www.keyes-robot.com
*/

#include <ESP32_Servo.h>
Servo myservo;  // 创建舵机对象来控制舵机
                //在ESP32上可以创建16个伺服对象
                
int pos = 0;    // 建立变量来存储伺服位置
// 推荐的ESP32 PWM GPIO引脚包括2,4,12-19,21-23,25-27,32-33 
int servoPin = 13;
                
void setup() {
  myservo.attach(servoPin, 500, 2500);   // 将伺服管脚13连接到伺服对象上

}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // 从0°到180°
    // 每一步1度
    myservo.write(pos);              // 告诉舵机去的位置在变量'pos'
    delay(15);                       // 等待15ms舵机到达对应的位置
  }
  for (pos = 180; pos >= 0; pos -= 1) { // 从180度到0度
    myservo.write(pos);              // 告诉舵机去的位置在变量'pos'
    delay(15);                       // 等待15ms舵机到达对应的位置
  }
}
