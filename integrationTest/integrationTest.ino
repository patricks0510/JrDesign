void setup() {
  // put your setup code here, to run once:
  pinInit();

  digitalWrite(6,HIGH);
  delay(100);
  digitalWrite(6,LOW);
}

void loop() {
  // put your main code here, to run repeatedly
  int score = 0;
  int userIn = 0;
  
  bool playing = false;

  if(digitalRead(3) == HIGH)
  {
    playing = true;
  }
  else
  {
    playing = false;
  }

  if(playing = true)
  {
    digitalWrite(6,HIGH);
    score = 0;
    int t_limit = 3000;

    while(playing == true)
    {
      //random instruction 
      int e_input = random(10,12);
      int t_remain = t_limit;

      //turn on LEDs in place of instruction sound
      digitalWrite(e_input,HIGH);

      
      while(t_remaining > 0){
          //take in user's input
          //if fret buttons hit
          if(digitalRead(1) == HIGH || digitalRead(2) == HIGH || digitalRead(4) == HIGH )
          {
              //set user input switch case controller
              userIn = 10;
              //break out of while loop to get next instruction
              break;
          }
          //if strummer moved
          else if(digitalRead(23) == HIGH || digitalRead(24) == HIGH )
          {  
              userIn = 11;
              break;
          }
          //if whammy bar flexed
          else if(analogRead(25) <= 500)
          {
              userIn = 12;
              break;
          }
          //no input given
          else
          {
              userIn = 0;
              break;
          }
          //delay and decrement remaining time
          delay(10);
          t_remaining -= 10;
      }
      if(e_input == userIn)
      {
        score++;
        //flash green LED
        flash(5);

        e_input = 0;
        userIn = 0;

        t_limit -= 10;
      }
      else
      {
        playing = false;
        digitalWrite(6,LOW);
        flash(7);
      }
    }
    for(int i = 0; i<score;i++)
    {
      flash(5);
    }
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

  //LEDs replacing sounds
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);

  return;
}

void flash(int pinout)
{
    digitalWrite(pinout,HIGH);
    delay(10);
    digitalWrite(pinout,LOW);
    return;
}
