#include <SoftwareSerial.h>
int pinled1=8;
int pinled2=9;
int pinled3=10;
int pinled4=11;
int pinled5=12;
int var;
int var1;
int var2;
int var3;
int var4;
int var5;
int s=0;
int q[5]={0,0,0,0,0};
unsigned long t=0;
SoftwareSerial a(14, 15); //bluetooth module Tx:Digital 2 Rx:Digital 3

void setup() 
{
  Serial.begin(9600);
   a.begin(38400);
   pinMode(A0,INPUT);
  pinMode(pinled1,OUTPUT);
  pinMode(pinled2,OUTPUT);
  pinMode(pinled3,OUTPUT);
  pinMode(pinled4,OUTPUT);
  pinMode(pinled5,OUTPUT);
}


void loop() 
{
    if (a.available()){
         a.println("afdas") ; 
    }
var=analogRead(A0);
  unsigned long t2 =millis();
  if(t2-t>=100)
  {
    t=t2;
    Serial.println(var);
  }

  
}
void serialEvent()
{
  if(Serial.available())
  {
    var1=Serial.parseInt();
    var2=Serial.parseInt();
    var3=Serial.parseInt();
    var4=Serial.parseInt();
    var5=Serial.parseInt();
    if(Serial.read()==char(13))
    {
       
       if(var1==1)
       {
        if(q[0]==1){
           digitalWrite(pinled1,LOW);
           q[0]=0;
        }
        else
        {
          digitalWrite(pinled1,HIGH);
           q[0]=1;
        }
       }

///////////////////////////////////////////////////////1
        if(var2==1)
       {
        if(q[1]==1){
           digitalWrite(pinled2,LOW);
           q[1]=0;
        }
        else
        {
          digitalWrite(pinled2,HIGH);
           q[1]=1;
        }
       }
////////////////////////////////////////////////////2


        if(var3==1)
       {
        if(q[2]==1){
           digitalWrite(pinled3,LOW);
           q[2]=0;
        }
        else
        {
          digitalWrite(pinled3,HIGH);
           q[2]=1;
        }
       }
////////////////////////////////////////////////3

        if(var4==1)
       {
        if(q[3]==1){
           digitalWrite(pinled4,LOW);
           q[3]=0;
        }
        else
        {
          digitalWrite(pinled4,HIGH);
           q[3]=1;
        }
       }
/////////////////////////////////////////////////////4
 if(var5==1)
       {
        if(q[4]==1){
           digitalWrite(pinled5,LOW);
           q[4]=0;
        }
        else
        {
          digitalWrite(pinled5,HIGH);
           q[4]=1;
        }
       }
////////////////////////////////////////////////////////5

    }
  }
}
