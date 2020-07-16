
#include <Servo.h>

Servo myServo;
int angle = 0;
void setup(){
    myServo.attach(9);
    Serial.begin(9600);
//    myServo.write(0);
}

void loop(){
//    myServo.write(0.02);
//    myServo.writeMicroseconds(800);
//    delay(100);
//    myServo.writeMicroseconds(1600);
//    delay(300);
//    myServo.writeMicroseconds(1500);
//    delay(2500);
      myServo.write(90);
      delay(200);
      myServo.write(120);
      delay(50);



//    myServo.writeMicroseconds(2000);
    angle = (angle + 10) % 180;
//    myServo.write(angle);
    Serial.println(angle);
}
