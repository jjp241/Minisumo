/*
  Simple example for receiving
  
  https://github.com/sui77/rc-switch/
*/

#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
bool wrog = false;
int distance = 120;
int surface;
bool checked = false;
double sensitivity = 0.04;
void setup() {
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(A7,INPUT);
  pinMode(A5,INPUT);
  digitalWrite(13,LOW);
  Serial.begin(9600);
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin #2
  
}

void loop() {

  if (mySwitch.available()) {
     
    if(mySwitch.getReceivedValue()==5592512){
      
 
    
      digitalWrite(12,LOW);
      digitalWrite(10,LOW);
      digitalWrite(11,LOW);
      digitalWrite(6,LOW);
      digitalWrite(9,LOW);
      checked = false;
    }
    

   
    
    if(mySwitch.getReceivedValue()==5592332){
     if(analogRead(A5) < 600){
      digitalWrite(12,HIGH);
      if(analogRead(A7) > distance){
        //distance += 3;
        Serial.println(distance);
          
          digitalWrite(10,HIGH);
          digitalWrite(11,LOW); 
          digitalWrite(6,HIGH);
          digitalWrite(9,LOW);
          delay(10);
          wrog = true;
         }
      
      else{
        if(wrog == false){
      analogWrite(10,50);
      digitalWrite(11,LOW);
      analogWrite(9,50);
      digitalWrite(6,LOW);
      }
      if(wrog == true){
      digitalWrite(11,HIGH);
      digitalWrite(10,LOW);
      digitalWrite(6,HIGH);
      digitalWrite(9,LOW);
      delay(60);
      wrog = false;
    }
      }
     }
      
     else{
      Serial.println(analogRead(A5));
       digitalWrite(11,HIGH);
          digitalWrite(10,LOW); 
          digitalWrite(9,HIGH);
          digitalWrite(6,LOW);
          delay(400);

      digitalWrite(10,HIGH);
      digitalWrite(11,LOW);
      digitalWrite(9,HIGH);
      digitalWrite(6,LOW);
      delay(100);
      
      }
      
  }
    
  
    
  }
  }
