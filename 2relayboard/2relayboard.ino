int relay1 =11;
int relay2 =12;

void setup() {
 pinMode(relay1, OUTPUT);
pinMode(relay2, OUTPUT);

}

void loop() {
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, LOW);
delay(5000);
digitalWrite(relay1, LOW);
digitalWrite(relay2, HIGH);
delay(5000);



}
