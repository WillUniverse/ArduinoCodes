#include <LiquidCrystal.h> //Inclui a biblioteca do LCD
                //RS,enable
LiquidCrystal lcd(9, 8,10, 11, 12, 13); //Configura os pinos do Arduino para se comunicar com o LCD
 

 void setup()
{


lcd.begin(16, 2);
}

 
void loop()
{



lcd.setCursor(0, 0);
lcd.print("DIGA"); 

lcd.setCursor(0, 1);
lcd.print("OLA"); 




 

}
