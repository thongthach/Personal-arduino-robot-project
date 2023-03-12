#include<Servo.h>
int echo = 7;
int trig = 8;
int duration =0;
int distance =0;
int first_led = 2; 

int f=11;
int e=12;
int d= 13;

int in1=5;
int in2 = 4;
int in3 = 6;
int in4= 10;

int sig[4]={in1,in2,in3,in4};
int counter =0;
int leds[3]={f,e,d};

Servo s1;
Servo s2;

void setup() {
  // put your setup code here, to run once:
pinMode(echo,INPUT);
pinMode(trig,OUTPUT);
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);

pinMode(f,OUTPUT);
pinMode(e,OUTPUT);
pinMode(d,OUTPUT);

Serial.begin(9600);
s1.attach(9);
s2.attach(3);
pinMode(first_led,OUTPUT);


}
int nums[1][3]{
  
 
  {1,1,1}
  
  };


void write(int val){
      for(int i=0; i<3;i++){
    if(nums[val][i] ==1){
      
      digitalWrite(leds[i],HIGH);
      
      }
      else{
        digitalWrite(leds[i],LOW); 
        
       }
    
    
    } 
  
  
  }

void stepperMotor(bool dir){
  if(dir){
    
    /*switch(counter){
  case 0:
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  break;
  case 1:
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  break;
  case 2:
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  break;
  case 3:
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  break;
} 
  }else{
    switch(counter){
  case 0:
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  break;
  case 1:
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  break;
  case 2:
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  break;
  case 3:
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
 
  
} 
  }
  counter++;
  if(counter >3){
    
      counter =0; 
   }*/
   digitalWrite(in1,HIGH);
   //digitalWrite(in2,LOW);
   digitalWrite(in3,HIGH);
    //digitalWrite(in4,HIGH);
  }
  else{
      digitalWrite(in1,LOW);
   digitalWrite(in2,LOW);
   digitalWrite(in3,LOW);
   digitalWrite(in4,LOW);
 
    
   }
   
  }
    
 
  

void triggerUltrasonicsensor(){
  
  digitalWrite(trig,LOW);
   delayMicroseconds(100);
  digitalWrite(trig, HIGH);
  delayMicroseconds(100);
  digitalWrite(trig, LOW);

  
  duration = pulseIn(echo, HIGH);
  distance = (duration/2) /28.5;
  Serial.println(distance); 
  
  
 if(distance >50 || distance ==50){
    
  stepperMotor(false);
  write(1);
  }
  else if(distance <50 && distance >30){
    
    stepperMotor(true);
   
    
    write(0);
    
    
   }
   else if(distance <30 && distance >10){
    stepperMotor(true);
    delay(5);
   digitalWrite(first_led,HIGH);
    delay(100);
    digitalWrite(first_led,LOW);
    delay(100);
     write(0);
      s1.write(180);
       s2.write(0);
      delay(1000);
      s1.write(0);
       s2.write(180);
      delay(1000);
    
    }
  else if(distance <10){
    
       stepperMotor(true);
       delay(5);
        digitalWrite(first_led,HIGH);
    delay(100);
    digitalWrite(first_led,LOW);
    delay(100);
      s1.write(180);
       s2.write(0);
      delay(1000);
      s1.write(0);
       s2.write(180);
      delay(1000);

     // s2.write(0);
     // delay(1000);
      //s2.write(180);
      //delay(1000);
       
      write(0);
      
   }  
 }

void loop() {
  // put your main code here, to run repeatedly:
 triggerUltrasonicsensor();
}
