#include <Servo.h>

Servo servo;

const int trigPin = 5;  //D1
const int echoPin = 4;  //D2
#define LED D0
// defines variables
long duration;
int distance;
#include <SoftwareSerial.h>
 
SoftwareSerial mp3(0, 2);
 
static uint8_t cmdbuf[8] = {0};
 
void command(int8_t cmd, int16_t dat)
{
  delay(20);
  
  cmdbuf[0] = 0x7e; 
  cmdbuf[1] = 0xFF; 
  cmdbuf[2] = 0x06; 
  cmdbuf[3] = cmd; 
  cmdbuf[4] = 0x00; 
  cmdbuf[5] = (int8_t)(dat >> 8); 
  cmdbuf[6] = (int8_t)(dat); 
  cmdbuf[7] = 0xef; 
 
  for (uint8_t i = 0; i < 8; i++)
  {
    mp3.write(cmdbuf[i]);
  }
}
void setup() {
servo.attach(14);  //D5
servo.write(0);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(LED, OUTPUT);
pinMode(13, OUTPUT);
pinMode(LED_BUILTIN, OUTPUT);
Serial.begin(9600); // Starts the serial communication
mp3.begin(9600);
delay(1500);
command(0x09, 0x0002);
delay(200);
command(0x03,0x0004);

}

void loop() {
//measure distance
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
Serial.println(distance);
if(distance<= 180){
  servo.write(distance);
  delay(distance);
}
delay(100);
}
