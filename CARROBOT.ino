#include <Servo.h>
#include<NewPing.h>
Servo servo;
NewPing sonar(12,11,300);
char ebo();
void setup(){
   servo.attach(9);
   Serial.begin(9600);
   pinMode(5,OUTPUT); 
   pinMode(4,OUTPUT); 
   pinMode(3,OUTPUT); 
   pinMode(2,OUTPUT);  
}

void loop(){
  ebo();
  servo.write(90);
  int i=sonar.ping_cm();
  Serial.println(i);
  if(0 < i & i < 35){
    digitalWrite(5,LOW);
    digitalWrite(4,LOW);
    digitalWrite(3,LOW);
    digitalWrite(2,LOW);
    delay(500);
    digitalWrite(5,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(3,HIGH);
    digitalWrite(2,LOW);
    delay(250);
    digitalWrite(5,LOW);
    digitalWrite(4,LOW);
    digitalWrite(3,LOW);
    digitalWrite(2,LOW);
    delay(100);
    servo.write(0);
    int right= sonar.ping_cm();
    delay(300);
    
    servo.write(180); 
    int left= sonar.ping_cm();
    delay(300);
    
      if(right>left){  
    digitalWrite(5,LOW);
    digitalWrite(4,HIGH);
    delay(350);
    digitalWrite(3,LOW);
    digitalWrite(2,LOW);
      }
      else{
    digitalWrite(5,LOW);
    digitalWrite(4,LOW);
    digitalWrite(3,HIGH);
    delay(350);
    digitalWrite(2,LOW);
      
    
        }
    }
  else{
    digitalWrite(5,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(2,LOW);
    }
}
char ebo(){
  if(Serial.available()){
    char c=Serial.read();
    if(c=='f'){
    digitalWrite(5,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(3,LOW);
    digitalWrite(2,HIGH);  
      }
    if(c=='b'){
    digitalWrite(5,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(2,LOW);  
      }  
    if(c=='l'){
    digitalWrite(5,LOW);
    digitalWrite(4,LOW);
    digitalWrite(3,LOW);
    digitalWrite(2,HIGH);  
      }
    if(c=='r'){
    digitalWrite(5,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(3,LOW);
    digitalWrite(2,LOW);  
      }
    if(c=='s'){
    digitalWrite(5,LOW);
    digitalWrite(4,LOW);
    digitalWrite(3,LOW);
    digitalWrite(2,LOW);     
    }
   }
  }
