#include <Servo.h>

Servo servo;

void setup() {

servo.attach(2); //D4

servo.write(0);


}

void loop() {
  servo.write(0);

}
