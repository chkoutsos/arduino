 int touch = 8;
int stat;
int red = 10;
int sen;
bool trick = false;

void setup() {

pinMode(touch,INPUT);
pinMode(red,OUTPUT);
stat = 0;
Serial.begin(9600);

}




void loop() {
  sen = pulseIn(touch,HIGH);
  Serial.println(sen);

    if(sen == 0)
    {trick = trick ;}
    else
    {trick = !trick;}
    Serial.print("trick");
    Serial.println(trick);

if(trick==false)
    digitalWrite(red,HIGH);

    else
    digitalWrite(red,LOW);

}
