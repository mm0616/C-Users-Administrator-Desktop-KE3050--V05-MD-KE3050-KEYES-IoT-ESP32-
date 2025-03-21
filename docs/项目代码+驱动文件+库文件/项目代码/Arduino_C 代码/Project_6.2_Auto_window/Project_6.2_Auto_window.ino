/*
  Keyes
  Auto_window
  www.keyes-robot.com
*/

#include <ESP32_Servo.h>
Servo myservo;
#define servoPin 5
#define waterPin 34


void setup() {
  Serial.begin(9600);
  pinMode(waterPin, INPUT);
  myservo.attach(servoPin, 500, 2500);
  myservo.write(100);
  delay(200);
}

void loop() {
  int water_val = analogRead(waterPin);
  Serial.println(water_val);
  if(water_val > 3300) {
    myservo.write(0);
    delay(200);
  }
  else {
    myservo.write(100);
    delay(200);
  }
}
