/*
 * ATTINY 84
 * 
 * Pin Utilisés
 *VCC -> 1    14 <- GND
 */

/* INCLUDE */
#include <TinyWireS.h>

/* DEFINE */
#define LED 8
#define BTN 1

//int valBTN;
boolean valBTN;
boolean oldValBTN;
byte returnBTN = 0;
byte byteRcvd = 0;

void setup()
{
  // put your setup code here, to run once:
  TinyWireS.begin(0x00);  // Activation de l'I2C avec l'adresse 000|0000 soit 0x00 à 000|1111| 0x15

  pinMode(LED, OUTPUT); //Led en sortie
  pinMode(BTN, INPUT);  //Bouton en entrée
}

void loop()
{
  // put your main code here, to run repeatedly:
  
  if (TinyWireS.available())
  {
    byteRcvd = TinyWireS.receive(); //Data reçu

    switch(byteRcvd)
    {
      case 0x01:
        digitalWrite(LED, HIGH);
        break;
      case 0x02:
        digitalWrite(LED, LOW);
        break;
    }

    valBTN = digitalRead(BTN);
    
    if(valBTN != oldValBTN)
    {
      oldValBTN = valBTN;
    }

    returnBTN = oldValBTN; //Transforme en byte
    TinyWireS.send(returnBTN);
  }
}


