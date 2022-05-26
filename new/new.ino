/*************  Powered By FaithBook-_-  *************/
#include<Servo.h>
Servo myservoB;
Servo myservoL;
Servo myservoR;
Servo myservoU;

#define Lk 7
#define Rk 8


#define ADLy A3
#define ADLx A2
#define ADRy A1
#define ADRx A0

int Ly,Lx,Ry,Rx;
int Bdir = 90,Ldir= 90,Rdir = 90,Udir = 20;

void setup(){
 Serial.begin(9600);
 pinMode(Lk,INPUT_PULLUP);
 pinMode(Rk,INPUT_PULLUP);
 myservoB.attach(3);
 myservoL.attach(5);
 myservoR.attach(9);
 myservoU.attach(11);
 myservoB.write(Bdir);
 myservoR.write(Rdir);
 myservoL.write(Ldir);
 myservoU.write(Udir);
 
}
int limit = 30,flag = 0;
void loop(){
  Ly = map(analogRead(ADLy),0,1023,0,179);
  Lx = map(analogRead(ADLx),0,1023,0,179);
  Ry = map(analogRead(ADRy),0,1023,0,179);
  Rx = map(analogRead(ADRx),0,1023,0,179);
  if(Lx >90+limit && Bdir < 180)Bdir++;
  else if(Lx < 90-limit && Bdir>0)Bdir--;
  
  if(Ly >90+limit && Ldir < 180)Ldir++;
  else if(Ly < 90-limit && Ldir>0 )Ldir--;
  
  if(Rx >90+limit && Bdir < 180)Bdir++;
  else if(Rx < 90-limit && Bdir>0)Bdir--;
  
  if(Ry >90+limit && Rdir < 180)Rdir++;
  else if(Ry < 90-limit && Rdir>0)Rdir--;
   myservoB.write(Bdir);
   myservoL.write(Ldir);
   myservoR.write(Rdir);
   if(digitalRead(Rk) == LOW){
      delay(20);
       if(digitalRead(Rk) == LOW){
         while(digitalRead(Rk) == LOW);
          flag = 1-flag;
       } 
   }else if(digitalRead(Lk) == LOW){
      delay(20);
       if(digitalRead(Lk) == LOW){
         while(digitalRead(Lk) == LOW);
          flag = 1-flag;
       } 
   }
   myservoU.write(flag*20);
  
  Serial.print("Ly"); 
  Serial.print(Ly);
  Serial.print("\tLx");
  Serial.print(Lx);
  Serial.print("\tRy");
  Serial.print(Ry);
  Serial.print("\tRx")h j;
  Serial.println(Rx);
  delay(15);
}
