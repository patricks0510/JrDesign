void setup() {
  // put your setup code here, to run once:

  //fret pins
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(6,INPUT);

  pinMode(11,OUTPUT);//output
  pinMode(12,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  
  if(digitalRead(3,HIGH))
  {
    digitalWrite(11,HIGH);
    delay(30);
  }
  if(digitalRead(4,HIGH))
  {
    digitalWrite(12,HIGH);
    delay(30);
  }
  if(digitalRead(6,HIGH))
  {
    digitalWrite(13,HIGH);
    delay(30);
  }
  delay(60);
  
  for(i = 11; i<=13; i++)
  {
    digitalWrite(i,LOW);
  }
}
