#include <LiquidCrystal.h> //Inclui a biblioteca do LCD
                //RS,enable
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Configura os pinos do Arduino para se comunicar com o LCD
 

 void setup()
{

lcd.begin(16, 2); //Inicia o LCD com dimensões 16x2(Colunas x Linhas)

}
 
void loop()
{

lcd.setCursor(0, 0); //Posiciona o cursor na primeira coluna(0) e na primeira linha(0) do LCD
lcd.print("WENDEL WILLIAMS"); //Escreve no LCD "Olá Garagista!"

lcd.setCursor(0, 1); //Posiciona o cursor na primeira coluna(0) e na segunda linha(1) do LCD
lcd.print("CARDOSO  SANTOS"); //Escreve no LCD "LabdeGaragem"
 

}
