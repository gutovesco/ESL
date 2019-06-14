#include <dht.h>
#include <Servo.h>

#define dht_apin A0

Servo myservo;
dht DHT;

void setup()
{
  myservo.attach(4);
  Serial.begin(9600);
  delay(500);
  Serial.println("DHT11 Humidade e temperatura Sensor\n\n");
  delay(1000);
}

void loop()
{
  DHT.read11(dht_apin);
    
    Serial.print("Humidade Atual: = ");
    Serial.print(DHT.humidity);
    Serial.print("% ");
    Serial.print("Temperatura Atual = ");
    Serial.print(DHT.temperature);
    Serial.println("C ");
    
   delay(500);

   if (DHT.temperature > 27)
   {
    myservo.write(180);
   }
   else
   {
    myservo.write(0);
   }
}
