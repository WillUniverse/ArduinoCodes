#define botao 7
#define ledver 2


int botaoestado = 0;

void setup() {

  pinMode (botao, INPUT);
  pinMode (ledver, OUTPUT);

}

void loop() {

  botaoestado = digitalRead (botao);
  if (botaoestado == HIGH) {
      digitalWrite (ledver, HIGH);      
    
  }

  else {
    digitalWrite (ledver, LOW);
    
  }
 
      
  
  }
