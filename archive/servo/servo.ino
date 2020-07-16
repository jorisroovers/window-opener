
#include <Servo.h>

Servo myServo;
int angle = 180;
void setup(){
    myServo.attach(9);
    Serial.begin(9600);
    myServo.write(180);
}

void loop(){
    if (angle == 0) {
      angle = 180;
    }
    angle = (angle - 1);
    myServo.write(angle);
    Serial.println(angle);
    delay(20);
}
