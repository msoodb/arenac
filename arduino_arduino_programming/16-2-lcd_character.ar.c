#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte heart[8] = {
	0b00000,
  	0b01010,
  	0b11111,
  	0b11111,
  	0b11111,
  	0b01110,
  	0b00100,
  	0b00000
};

void setup()
{
	lcd.begin(16, 2);
	lcd.createChar(0, heart);
  	lcd.setCursor(0, 0);
  	lcd.print("I ");
  	lcd.write((byte)0);
  	lcd.print(" Embeded! ");
}

void loop()
{
	
}
