
int but1 = 13;
int relay1 = 11;
int butState = 0;
int bpres = 0;

void setup() {
  Serial.begin(9600);
    pinMode(but1,INPUT);
    pinMode(relay1,OUTPUT);

}

void loop() {
  butState = digitalRead(but1);
  if(butState == LOW){{
     digitalWrite(relay1,LOW);
    
     Serial.print("pressed = ");
     Serial.println(bpres);
  }
   bpres++;
  }
  else
    digitalWrite(relay1,HIGH);
    

}
