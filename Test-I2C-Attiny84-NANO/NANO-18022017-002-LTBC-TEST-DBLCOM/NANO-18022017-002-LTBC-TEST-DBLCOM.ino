#include <Wire.h>

byte data;

void setup() {
  // put your setup code here, to run once:
  Wire.begin();

  Serial.begin(9600);
}

void loop() {
  
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(0x00); //Adresse esclave
  Wire.write(0x01);
  Wire.endTransmission();
  delay(10);
  Wire.beginTransmission(0x00); //Adresse esclave
  Wire.write(0x02);
  Wire.endTransmission();
  delay(100);
  
  /*Wire.beginTransmission(0x00); //Adresse esclave
  Wire.write(0x06); //Lancer état bouton
  Wire.endTransmission();
  delay(100);*/
  
  Wire.requestFrom(0x00, 1);  //Recevoir 1 byte depuis l'esclave
  if(Wire.available())
  {
    data = Wire.read(); //Réception data
    Serial.println(data);
  }

  delay(1);
}
