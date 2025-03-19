/*
  Keyes
  button
  www.keyes-robot.com
*/

#define btn1 16

void setup() {
  Serial.begin(9600);
  pinMode(btn1, INPUT);
}

void loop() {
  boolean btn1_val = digitalRead(btn1);
  Serial.print("button1 = ");
  Serial.println(btn1_val);
  delay(100);
}
