void setup() {
  // put your setup code here, to run once:
  //Joystick
  pinMode(23,INPUT);//horizontal axis init
  pinMode(24,INPUT);//vertical axis init

  pinMode(11,OUTPUT);//output
  pinMode(12,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(23) == HIGH)
  {
    digitalWrite(11,HIGH);
    delay(30);
    digitalWrite(12,LOW);
    delay(30);
  }
  if(digitalRead(24) == HIGH)
  {
    digitalWrite(12,HIGH);
    delay(30);
    digitalWrite(12,LOW);
    delay(30);
    
  }
  
}
