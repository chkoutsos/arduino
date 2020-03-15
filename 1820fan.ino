#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>

#define ONE_WIRE_BUS 4

LiquidCrystal_I2C lcd(0x27, 2,1,0,4,5,6,7,3,POSITIVE);
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
int relay1 = 11;



void setup() {
  pinMode(relay1, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.clear();
  lcd.print("Temp is        C");
  lcd.setCursor ( 0, 1 );
  lcd.print("Fan status ~");
  sensors.begin();
}

void loop() {
   sensors.requestTemperatures();
   float tmp = sensors.getTempCByIndex(0);
   Serial.print("Temperature is: ");
   lcd.setCursor ( 9, 0 );
   lcd.print(tmp);
   lcd.setCursor ( 13, 1 );
   Serial.println(tmp);
   delay(1000);
   if(tmp >= 20){
    digitalWrite(relay1,LOW);
    lcd.print("ON  ");
   }
   else{
    digitalWrite(relay1,HIGH);
    lcd.print("OFF");
   }
}
