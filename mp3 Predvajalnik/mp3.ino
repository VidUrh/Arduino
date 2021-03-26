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

void setup(){
Serial.begin(9600);
mp3.begin(9600);
delay(1500);
command(0x09, 0x0002);
delay(200);
command(0x03,0x0004);


}
void loop() {
  Serial.println("done");

}
