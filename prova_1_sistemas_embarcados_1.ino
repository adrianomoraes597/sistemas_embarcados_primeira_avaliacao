/*

Exemplo para trabalhar com displays 7 segmentos

*/


#define A 2
#define B 3
#define C 4
#define D 5
#define E 6
#define F 7
#define G 8
#define btn1 9
#define btn2 10

int cont = 0;

int numero1 = 0; 
int numero2 = 0; 

int controle = 0; 

int soma = 0; 


const byte tabela_7seg[7][7] = 
{ //A B C D E F G
  { 1,1,1,1,1,1,0},	//0
  { 0,1,1,0,0,0,0}, //1
  { 1,1,0,1,1,0,1},	//2
  { 1,1,1,1,0,0,1}, //3 
  { 0,1,1,0,0,1,1},	//4
  { 1,0,1,1,0,1,1},	//5
  { 1,0,1,1,1,1,1}, //6 
};

void converteValorDisplay(byte valor){
  byte pino = 2;
 
  for(byte x = 0;x<7;x++){
    digitalWrite(pino,tabela_7seg[valor][x]);
    pino++;
  }
}

void setup()
{
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  
  converteValorDisplay(cont);
  
  if(cont<4)
  {
    if (digitalRead(btn1) == HIGH) 
    {
      delay(200);
      cont++; 
    }
 
	if (digitalRead(btn2) == HIGH && controle == 0)
    {
      numero1 = cont;
      cont = 0;
      delay(200);
      controle++;
      
    }
    
	if (digitalRead(btn2) == HIGH && controle == 1)
    {
      numero2 = cont;
      controle = 2; 
    }
  
    if (controle == 2)
    {
    
    soma = numero1 + numero2;
    
    switch (soma)
    {
      case 0:
      	digitalWrite(11,LOW);
      	digitalWrite(12,LOW);
      	digitalWrite(13,LOW);
      	converteValorDisplay(cont = 0);
        delay(200); 
      	controle++;
      	break; 
      case 1:
        digitalWrite(11,HIGH);
      	digitalWrite(12,LOW);
      	digitalWrite(13,LOW);
      	converteValorDisplay(cont = 1);
      	delay(200); 
      	controle++; 
      	break;
      case 2:
        digitalWrite(11,LOW);
      	digitalWrite(12,HIGH);
      	digitalWrite(13,LOW);
      	converteValorDisplay(cont = 2);
        delay(200); 
      	controle++;
      	break;
      case 3:
        digitalWrite(11,HIGH);
      	digitalWrite(12,HIGH);
      	digitalWrite(13,LOW);
      	converteValorDisplay(cont = 3);
      	delay(200); 
      	controle++;
      	break;
      case 4:
        digitalWrite(11,LOW);
      	digitalWrite(12,LOW);
      	digitalWrite(13,HIGH);
      	converteValorDisplay(cont = 4);
      	delay(200); 
      	controle++;
      	break;
      case 5:
        digitalWrite(11,HIGH);
      	digitalWrite(12,LOW);
      	digitalWrite(13,HIGH);
      	converteValorDisplay(cont = 5);
      	delay(200); 
      	controle++;
      	break;
      case 6:
        digitalWrite(11,LOW);
      	digitalWrite(12,HIGH);
      	digitalWrite(13,HIGH);
      	converteValorDisplay(cont = 6);
      	delay(200); 
      	controle++;
      	break;
    }
      
    }
    
  }
  
  if (cont == 4 && soma != 4)
  {
    cont = 0;
  }
  
  if (digitalRead(btn2) == HIGH && controle == 3)
  {
    cont = 0;
    numero1 = 0;
    numero2 = 0;
    delay(200);
    controle = 0; 
    soma = 0; 
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
    
  }
  
}