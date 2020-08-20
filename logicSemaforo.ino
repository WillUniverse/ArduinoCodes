//Semaforo A
int semA_Vermelho = 8;
int semA_Amarelo =9;
int semA_Verde = 10;

//Semaforo B
int semB_Vermelho = 5;
int semB_Amarelo = 6;
int semB_Verde = 7;

//Semaforo P
int semP_Vermelho = 11;
int semP_Verde = 12;

int botao = 13;
int botaoStatus;

int time_1, time_2;

int estado;

void setup() {
  // put your setup code here, to run once:
//Semaforo A
pinMode(semA_Vermelho, OUTPUT);
pinMode(semA_Amarelo, OUTPUT);
pinMode(semA_Verde, OUTPUT);

//Semaforo B
pinMode(semB_Vermelho, OUTPUT);
pinMode(semB_Amarelo, OUTPUT);
pinMode(semB_Verde, OUTPUT);

//Semaforo P
pinMode(semP_Vermelho, OUTPUT);
pinMode(semP_Verde, OUTPUT);

pinMode(botao, INPUT);
botaoStatus = 1;


}

void loop() {
  // put your main code here, to run repeatedly:

  int atualMillis = millis();

  if (digitalRead(botao) == HIGH && botaoStatus == 1 && estado != 1 && estado != 2){
    digitalWrite(semA_Vermelho, LOW);
    digitalWrite(semA_Amarelo, HIGH);
    digitalWrite(semA_Verde, LOW);
    delay(3000);

    digitalWrite(semA_Vermelho, HIGH);
    digitalWrite(semA_Amarelo, LOW);
    digitalWrite(semA_Verde, LOW);
    
    digitalWrite(semB_Vermelho, LOW);
    digitalWrite(semB_Amarelo, LOW);
    digitalWrite(semB_Verde, HIGH);

    digitalWrite(semP_Vermelho, LOW);
    digitalWrite(semP_Verde, HIGH);
    delay(5000);

  digitalWrite(semA_Vermelho, HIGH);
    digitalWrite(semA_Amarelo, LOW);
    digitalWrite(semA_Verde, LOW);
    
    digitalWrite(semB_Vermelho, LOW);
    digitalWrite(semB_Amarelo, HIGH);
    digitalWrite(semB_Verde, LOW);

    digitalWrite(semP_Vermelho, HIGH);
    digitalWrite(semP_Verde, HIGH);
    delay(3000);
     
    time_2 = atualMillis;
    botaoStatus = 2;
    time_1 = atualMillis;
    }
    
    if (botaoStatus == 2){
      if(atualMillis - time_1 < 0 || atualMillis - time_1 > 34000){
      time_1 = atualMillis;
      botaoStatus = 1;
      }
    }

//De 0 a 5000
   if(atualMillis - time_2 > 0 && atualMillis - time_2 < 5000){
      estado = 1;
      }
      
//De 5000 a 8000
   if (atualMillis - time_2 > 5000 && atualMillis - time_2 < 8000){
        estado = 2;
        }

//De 8000 a 20000
   if (atualMillis - time_2 > 8000 && atualMillis - time_2 < 20000){
          estado = 3;
          }

//De 20000 a 23000
   if (atualMillis - time_2 > 20000 && atualMillis - time_2 < 23000){
          estado = 4;
          }

//Reset
   if (atualMillis - time_2 > 23000 || atualMillis - time_2 < 0){
          time_2 = atualMillis;
          }

if(estado == 1){
    //Estado A = Vermelho
    //Estado B = Verde
    //Estado P = Verde
    
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
    //Estado A = Vermelho
    //Estado B = Amarelo
    //Estado P = Vermelho
    //Estado P = Verde
    
    digitalWrite(semA_Vermelho, HIGH);
    digitalWrite(semA_Amarelo, LOW);
    digitalWrite(semA_Verde, LOW);
    
    digitalWrite(semB_Vermelho, LOW);
    digitalWrite(semB_Amarelo, HIGH);
    digitalWrite(semB_Verde, LOW);

    digitalWrite(semP_Vermelho, HIGH);
    digitalWrite(semP_Verde, HIGH);
    }
if(estado == 3){    
    //Estado A = Verde
    //Estado B = Vermelho
    //Estado P = Vermelho
    
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
    //Estado A = Amarelo
    //Estado B = Vermelho
    //Estado P = Vermelho
    
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
