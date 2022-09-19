#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  // configure the USB serial monitor 
  Serial.begin(115200); 
}

void loop() {
  // put your main code here, to run repeatedly:
  int iVal; 
 
  // read digitized value from the D1 Mini's A/D convertor 
  iVal = analogRead(A0); 
 
  // print value to the USB port 
  double outputValue = 50.0/1023;
  float inputValue = iVal*outputValue;
  String judgement = "";
  if (inputValue<10){
    judgement = "Cold!";
  } 
  else if (inputValue>10 && inputValue<15){
    judgement = "Cool";
  }
  else if (inputValue>15 && inputValue<25){
    judgement = "Perfect";
  }
  else if (inputValue>25 && inputValue<30){
    judgement = "Warm";
  }
  else if (inputValue>30 && inputValue<35){
    judgement = "Hot";
  }else{
    judgement = "Too Hot!";
  }
  Serial.println("Output Value = " + String(outputValue));
  //Serial.println("Digitized Value = " + String(iVal));
  //Serial.println("Digitized Value is equivalent to an Analog Voltage = " + String(inputValue)+"V"); 
  Serial.println("Digitized Value of " + String(iVal)+" is equivalent to a temperature input of " + String(inputValue) + ", which is " + judgement);
  // wait 0.5 seconds (500 ms) 
  delay(2000); 
}