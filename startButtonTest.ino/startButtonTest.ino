void setup() {
  // put your setup code here, to run once:
  pinMode(5,INPUT);

  pinMode(11,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(5,HIGH))
  {
    digitalWrite(11,HIGH);
    delay(30);
  }
  delay(60);
  if(digitalRead(5,LOW))
  {
    digitalWrite(11,LOW);
    delay(30);
  }
}
