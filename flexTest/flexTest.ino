void setup() {
  // put your setup code here, to run once:
  pinMode(25,INPUT);

  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 while(analogRead(25) <= 440 || analogRead(25) >= 612)
 {
   digitalWrite(13,HIGH);
   delay(30);
 }
 digitalWrite(13,LOW);

}
