#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#define D2 4
#define D1 5
LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup() {
//Use predefined PINS consts#
Wire.begin(D2, D1);
lcd.init();
lcd.setBacklight(HIGH);
lcd.begin(16,2);
lcd.setCursor(0,0);
lcd.print("HELLO");

}

void loop() { // do nothing here 
  }
