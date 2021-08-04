void setup() {
  // put your setup code here, to run once:
  pinInit();
  digitalWrite(6,HIGH);
  delay(100);
  digitalWrite(6,LOW);
  delay(150);
  digitalWrite(7,HIGH);
  delay(150);
  digitalWrite(7,LOW);
  delay(150);
  digitalWrite(10,HIGH);
  delay(150);
  digitalWrite(10,LOW);
}

void loop() {
  // put your main code here, to run repeatedly
  
  if(digitalRead(3) == HIGH)
  {
    flash(5);
    flash(6);
    flash(7);

    flash(10);
    flash(11);
    flash(12);
    
    //for(int threeLoops = 300; threeLoops > 0; threeLoops--)
    //{
    int number = random(1,4);
    //digitalWrite(number+9,HIGH);
    int counter = 300;
    
    switch(number)
    {
        //whammy it
        case 3:
          digitalWrite(12,HIGH);
          //delay(20);
          
          while(counter>0)
          {
            if(analogRead(A2) > 420)
            {
              digitalWrite(12,LOW);
              flash(5);
              delay(10);
              break;
            }
            else if(digitalRead(1) == HIGH || digitalRead(2) == HIGH || digitalRead(4) == HIGH  || digitalRead(A0) == HIGH || digitalRead(A1) == HIGH)
            {
              digitalWrite(12,LOW);
              flash(7);
              delay(10);
              break;
            }
            else
            {
              flash(6);
              delay(10);
            }
            counter--;
          }
          digitalWrite(12,LOW);
          flash(7);
          delay(10);
          break;

         
        //strum it  
        case 2:
          digitalWrite(11,HIGH);
          //delay(20);
          
          while(counter>0)
          {
              if(digitalRead(A0) == HIGH || digitalRead(A1) == HIGH)
              {
                digitalWrite(11,LOW);
                flash(5);
                delay(10);
                break;
              }
              
              else if(digitalRead(1) == HIGH || digitalRead(2) == HIGH || digitalRead(4) == HIGH  || analogRead(A2) > 420)
              {
                digitalWrite(11,LOW);
                flash(7);
                delay(10);
                break;
              }
              else
              {
                flash(6);
                delay(10);
              }
              counter--;
           } 
          digitalWrite(11,LOW);
          flash(7);
          delay(10);
          break;
        
        //fret it
        case 1:
          digitalWrite(10,HIGH);
          //delay(20);
          
          while(counter>0)
          {
            if(digitalRead(1) == HIGH || digitalRead(2) == HIGH || digitalRead(4) == HIGH)
            {
              digitalWrite(10,LOW);
              flash(5);
              delay(10);
              break;
            }
            else if(digitalRead(A0) == HIGH || digitalRead(A1) == HIGH || analogRead(A2) > 420)
            {
              digitalWrite(10,LOW);
              flash(7);
              delay(10);
              break;
            }
            else
            {
              flash(6);
              delay(10);
            }
            counter--;
          }
          digitalWrite(11,LOW);
          flash(7);
          delay(10);
          break;

        default:
          for(int i = 0; i < 10; i++)
          {
            flash(7);
          }
          break;
      }
//      for(int i = 0; i < 10; i++)
//          {
//            flash(7);
//          }
      //threeLoops--;
    //}
  //end of for loop
//}
  delay(30);
  }
}

void pinInit()
{
   //speaker
  pinMode(9,OUTPUT);//speaker init

  //SD card
  //pinMode(17,OUTPUT);//SD MOSI init
  //pinMode(18,INPUT);//SD MISO init
  //pinMode(19,INPUT);//SD clock init

  //Joystick
  pinMode(A0,INPUT);//horizontal axis init
  pinMode(A1,INPUT);//vertical axis init

  //Flex sensor
  pinMode(A2,INPUT);//flex sensor, potentially should be INPUT_PULLUP

  //Frets 
  pinMode(1,INPUT);
  pinMode(2,INPUT);
  pinMode(4,INPUT);

  //Start button
  pinMode(3,INPUT);
  
  //LEDs, 5 green, 6 yellow, 7 red
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  //digitalWrite(5,LOW);
  //digitalWrite(6,LOW);
  //digitalWrite(7,LOW);

  //LEDs replacing sounds
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  //digitalWrite(10,LOW);
  //digitalWrite(11,LOW);
  //digitalWrite(12,LOW);

  return;
}

void flash(int pinout)
{
    digitalWrite(pinout,HIGH);
    delay(100);
    digitalWrite(pinout,LOW);
    delay(100);
    return;
}
