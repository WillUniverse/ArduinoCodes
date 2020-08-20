#define botao 2
#define ledver 11


int botaoestado = 0;

void setup() {

  pinMode (botao, INPUT);
  pinMode (ledver, OUTPUT);

}

void loop() {

  botaoestado = digitalRead (botao);
  if (botaoestado == HIGH) {
      digitalWrite (ledver, HIGH);
      delay(100);
      digitalWrite (ledver, LOW);
      delay(300);       
    
  }

  else {
    digitalWrite (ledver, LOW);
    
  }
 
      
  
  }
