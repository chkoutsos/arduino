int but1 = 13;
int relay1 = 11;
int butState = 0;
int relayS = 0;
int pushed = 0; 


void setup() {
  Serial.begin(9600);
    pinMode(but1,INPUT);
    pinMode(relay1,OUTPUT);

}

void loop() {
  butState = digitalRead(but1);
  
  if(butState == LOW && relayS == LOW){
    pushed = 1-pushed;
    delay(100);
    
  }
  relayS = butState;
 if(pushed==LOW){
  Serial.println("on");
  digitalWrite(relay1,LOW);
  
 }
  else{
    Serial.println("off");
    digitalWrite(relay1,HIGH);
  
  }

delay(150);
}
