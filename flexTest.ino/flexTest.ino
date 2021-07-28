void setup() {
  // put your setup code here, to run once:
  pinMode(25,INPUT);

  pinMode(11,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(analogRead(25) <= 500)
  {
    digitalWrite(11,HIGH);
    delay(30);
  }
  digitalWrite(11,LOW);
}
