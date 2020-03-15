#include <dht.h>
dht DHT;
#define DHT11_PIN 7
int relay1 = 11;

void setup(){
 
 pinMode(relay1, OUTPUT);
  Serial.begin(9600); 
 
}

void loop()
{
 
 
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  delay(5000);
  if(DHT.temperature > 20)
          digitalWrite(relay1, LOW);
else
      digitalWrite(relay1, HIGH);

  
  
 
}
