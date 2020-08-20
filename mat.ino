int semA_Vermelho = 7;
int semA_Amarelo =6;
int semA_Verde = 5;

int semB_Vermelho = 4;
int semB_Amarelo = 3;
int semB_Verde = 2;

int semP_Vermelho = 8;
int semP_Verde = 9;

int botao = 10;
int botaoStatus;

int time_1, time_2;

int estado;

void setup() {
  // put your setup code here, to run once:

pinMode(semA_Vermelho, OUTPUT);
pinMode(semA_Amarelo, OUTPUT);
pinMode(semA_Verde, OUTPUT);

pinMode(semB_Vermelho, OUTPUT);
pinMode(semB_Amarelo, OUTPUT);
pinMode(semB_Verde, OUTPUT);

pinMode(semP_Vermelho, OUTPUT);
pinMode(semP_Verde, OUTPUT);

pinMode(botao, INPUT);
botaoStatus = 1;


}

void loop() {
  // put your main code here, to run repeatedly:

  int atualMillis = millis();

  if (digitalRead(botao) == HIGH && botaoStatus == 1){

    digitalWrite(semA_Vermelho, LOW);
    digitalWrite(semA_Amarelo, HIGH);
    digitalWrite(semA_Verde, LOW);
    delay(3000);

    
    time_1 = atualMillis;
    time_2 = atualMillis;
    botaoStatus = 2;
    }
    if (botaoStatus == 2){
      if(atualMillis - time_1 < 5000)
      time_1 = atualMillis;
      botaoStatus = 2;
    }
   if(atualMillis - time_2 > 0 && atualMillis - time_2 < 5000){
      estado = 1;
      }
   if (atualMillis - time_2 > 5000 && atualMillis - time_2 < 8000){
        estado = 2;
        }
   if (atualMillis - time_2 > 8000 && atualMillis - time_2 < 20000){
          estado = 3;
          }
   if (atualMillis - time_2 > 20000 && atualMillis - time_2 < 23000){
          estado = 4;
          }
   if (atualMillis - time_2 > 23000 || atualMillis - time_2 < 0){
          time_2 = atualMillis;
          }

if(estado == 1){
    digitalWrite(semA_Vermelho, HIGH);
    digitalWrite(semA_Amarelo, LOW);
    digitalWrite(semA_Verde, LOW);
    
    digitalWrite(semB_Vermelho, LOW);
    digitalWrite(semB_Amarelo, LOW);
    digitalWrite(semB_Verde, HIGH);

    digitalWrite(semP_Vermelho, LOW);
    digitalWrite(semP_Verde, HIGH);
    }
if(estado == 2){
    digitalWrite(semA_Vermelho, LOW);
    digitalWrite(semA_Amarelo, LOW);
    digitalWrite(semA_Verde, HIGH);
    
    digitalWrite(semB_Vermelho, LOW);
    digitalWrite(semB_Amarelo, HIGH);
    digitalWrite(semB_Verde, LOW);

    digitalWrite(semP_Vermelho, HIGH);
    digitalWrite(semP_Verde, HIGH);
    }
if(estado == 3){    
    digitalWrite(semA_Vermelho, LOW);
    digitalWrite(semA_Amarelo, LOW);
    digitalWrite(semA_Verde, HIGH);
    
    digitalWrite(semB_Vermelho, HIGH);
    digitalWrite(semB_Amarelo, LOW);
    digitalWrite(semB_Verde, LOW);

    digitalWrite(semP_Vermelho, HIGH);
    digitalWrite(semP_Verde, LOW);
    }
if(estado == 4){    
    digitalWrite(semA_Vermelho, LOW);
    digitalWrite(semA_Amarelo, HIGH);
    digitalWrite(semA_Verde, LOW);
    
    digitalWrite(semB_Vermelho, HIGH);
    digitalWrite(semB_Amarelo, LOW);
    digitalWrite(semB_Verde, LOW);

    digitalWrite(semP_Vermelho, HIGH);
    digitalWrite(semP_Verde, LOW);
    }

    
}
