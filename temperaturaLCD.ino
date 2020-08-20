#include <LiquidCrystal.h> //Inclui a biblioteca do LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Configura os pinos do Arduino para se comunicar com o LCD
// Pino onde o Termistor esta conectado
#define PINOTERMISTOR A0         
// Valor do termistor na temperatura nominal
#define TERMISTORNOMINAL 10000      
// Temp. nominal descrita no Manual
#define TEMPERATURENOMINAL 25   
// Número de amostragens para 
#define NUMAMOSTRAS 5
// Beta do nosso Termistor
#define BCOEFFICIENT 3977
// valor do resistor em série
#define SERIESRESISTOR 10000    
 float temperatura;
int ldrValor = 0; //Valor lido do LDR
int ledverm = 8;
int ledverd = 9; 
int amostra[NUMAMOSTRAS];
int i; 
void setup(void) {
  Serial.begin(9600);
  analogReference(EXTERNAL);
  pinMode (ledverm , OUTPUT);
  pinMode (ledverd, OUTPUT);

}
 
void loop(void) {
  ldrValor = analogRead(A0); //O valor lido será entre 0 e 1023
    ldrValor = map(ldrValor, 0, 1023, 0, 100); //funçao que converte de 0-1023 para 0-100
   Serial.println(ldrValor);
 delay(100);

  if (ldrValor<41){
    digitalWrite(ledverm, HIGH);
    digitalWrite (ledverd, LOW);
  }
  if ((ldrValor>41)&(ldrValor<71)){
       digitalWrite(ledverm, HIGH);
       digitalWrite (ledverd, HIGH);
  }
  if (ldrValor>70){
       digitalWrite(ledverm, LOW);
       digitalWrite (ledverd, HIGH);
  }
 
  float media;
 
  for (i=0; i< NUMAMOSTRAS; i++) {
   amostra[i] = analogRead(PINOTERMISTOR);
   delay(10);
  }
 
  media = 0;
  for (i=0; i< NUMAMOSTRAS; i++) {
     media += amostra[i];
  }
  media /= NUMAMOSTRAS;
  // Converte o valor da tensão em resistência
  media = 1023 / media - 1;
  media = SERIESRESISTOR / media;
  
  //Faz o cálculo pela fórmula do Fator Beta
  float temperatura;
  temperatura = media / TERMISTORNOMINAL;     // (R/Ro)
  temperatura = log(temperatura); // ln(R/Ro)
  temperatura /= BCOEFFICIENT;                   // 1/B * ln(R/Ro)
  temperatura += 1.0 / (TEMPERATURENOMINAL + 273.15); // + (1/To)
  temperatura = 1.0 / temperatura;                 // Inverte o valor
  temperatura -= 273.15;                         // Converte para Celsius

 
 lcd.begin(16, 2); //Inicia o LCD com dimensões 16x2(Colunas x Linhas)
lcd.setCursor(0, 0); //Posiciona o cursor na primeira coluna(0) e na primeira linha(0) do LCD
lcd.print("Temp : "); //Escreve no LCD "Temp"
lcd.print (temperatura,1); // escreve no lcd o valor da temperatura
lcd.write(B11011111); //Simbolo de graus celsius
lcd.println ("C");
lcd.setCursor(0, 1); //Posiciona o cursor na primeira coluna(0) e na segunda linha(1) do LCD
lcd.print("lumi : ");
lcd.print (ldrValor); //Escreve no LCD a % da luminosidade
lcd.print ("%");
  
  Serial.print("Temperatura no Sensor eh: "); 
  Serial.print(temperatura);
  Serial.println(" *C");
 
  delay(1000);
}

