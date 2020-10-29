int but1 = 8;
int relay1 = 4;
int butState = 0;

void setup() {
    pinMode(but1,INPUT);
    pinMode(relay1,OUTPUT);

}

void loop() {
  butState = digitalRead(but1);
  if(butState == LOW)
    digitalWrite(relay1,LOW);
  else
    digitalWrite(relay1,HIGH);
    

}
