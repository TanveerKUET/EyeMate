
#include <SoftwareSerial.h>
#define tx0Pin 1
#define rx0Pin 0
int flag=3;
char data;
int x,y,z;
  float inCmMeter,incmMeter,incMmeter;
SoftwareSerial bluetooth = SoftwareSerial(rx0Pin,tx0Pin);

void setup(){
  
  bluetooth.begin(9600);
  pinMode(rx0Pin,INPUT);
  pinMode(tx0Pin,OUTPUT);
  bluetooth.println("ok let's go.......");
  
}

void loop(){
  
  data=bluetooth.read();
  if(data=='1')
  {
    flag=1;
    bluetooth.println("  starts");
    delay(1000);
  }
  if(data=='0')
  {
    flag=1;
    bluetooth.println("  stop");
    delay(1000);
  }
  while(flag!=0)
  {
  if(bluetooth.available())
  {
  
  x = analogRead(A0);
  y = analogRead(A1);
  z = analogRead(A2);
  
  inCmMeter = (x/2.0)*0.0254*100;
 incmMeter = (y/2.0)*0.0254*100;
  incMmeter = (z/2.0)*0.0254*100;
  
  /*Serial.print("x= ");
  Serial.println(inCmMeter);
  Serial.print("y= ");
  Serial.println(incmMeter);
  Serial.print("z= ");
  Serial.println(incMmeter);*/
  
  ///First operation of range finder
  if(inCmMeter<=50)
  {
   if(bluetooth.available())
   {
   bluetooth.println("Ground");
   y = analogRead(A1);
   z = analogRead(A2);
  incmMeter = (y/2.0)*0.0254*100;
  incMmeter = (z/2.0)*0.0254*100;
   }
    delay(2000);
  }
    
  ///Second operation of range finder
  if(incmMeter<=100)
  {
  if(bluetooth.available())
   {
   bluetooth.println("  Left");
   z = analogRead(A2);
   incMmeter = (z/2.0)*0.0254*100;
   }
    delay(2000);
  }
   ///Third operation of range finder
  if(incMmeter<=100)
  {
  
   if(bluetooth.available())
   {
   bluetooth.println("  Right");
   }
    delay(2000); 
  }
  
  delay(1000);  
}
  }
}


