#include <pcmConfig.h>
#include <pcmRF.h>
#include <TMRpcm.h>
#include <SD.h>
#include <SPI.h>
TMRpcm audioSD;

void setup() {
  // put your setup code here, to run once:
  pinInit();
  audioSD.setVolume(4);
  audioSD.play("GTR.wav");
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

  randomSeed(analogRead(A3));
}

void loop() {
  // put your main code here, to run repeatedly   //unit test -> integration tests -> system tests
  
  //keeping track of gameplay status and score
  bool playing = false;
  int score;

  //if the start button is hit, the player starts playing with a score of 0
  if(digitalRead(3) == HIGH)
  {
    score = 0;
    playing = true;
  }
    //gameplay while loop  
    while(playing == true && score < 99) {
      //digitalWrite(number+9,HIGH);
      
      //generate random number 1-3 for expected input
      int number = random(1,4);
      //window of time to get correct input scales down as score goes up
      int counter = 300 - score*2;
      
      switch(number)
      {
          //whammy it
          case 3:
          //play corresponding instruction
          audioSD.play("Wham.wav");
          //write LED high (for when sound did not work)
            digitalWrite(12,HIGH);
            //delay(20);

            //only read input if input window has not closed
            while(counter>0)
            {
              //if correct input
              if(analogRead(A2) > 420)
              {
                //increment score
                score++;
                //turn off LED (when no sound)
                digitalWrite(12,LOW);
                //flash green LED
                flash(5);
                delay(10);
                //break out of while loop to generate new expected input
                break;
              }
              //if wrong input
              else if(digitalRead(1) == HIGH || digitalRead(2) == HIGH || digitalRead(4) == HIGH  || digitalRead(A0) == HIGH || digitalRead(A1) == HIGH)
              {
                //game stops
                playing = false;
                digitalWrite(12,LOW);
                //red LED flashes
                flash(7);
                delay(10);
                break;
              }
              //if no input
              else
              {
                //flash yellow led and continue
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
          audioSD.play("Strum.wav");
            digitalWrite(11,HIGH);
            //delay(20);
            
            while(counter>0)
            {
                if(digitalRead(A0) == HIGH || digitalRead(A1) == HIGH)
                {
                  score++;
                  digitalWrite(11,LOW);
                  flash(5);
                  delay(10);
                  break;
                }
                
                else if(digitalRead(1) == HIGH || digitalRead(2) == HIGH || digitalRead(4) == HIGH  || analogRead(A2) > 420)
                {
                  playing = false;
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
          audioSD.play("Fret.wav");
            digitalWrite(10,HIGH);
            //delay(20);
            
            while(counter>0)
            {
              if(digitalRead(1) == HIGH || digitalRead(2) == HIGH || digitalRead(4) == HIGH)
              {
                score++;
                digitalWrite(10,LOW);
                flash(5);
                delay(10);
                break;
              }
              else if(digitalRead(A0) == HIGH || digitalRead(A1) == HIGH || analogRead(A2) > 420)
              {
                playing = false;
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
          //debugging flashing light for if RNG goes outside of expected bounds
          default:
            for(int i = 0; i < 10; i++)
            {
              flash(7);
            }
            break;
        }
  delay(30);
  }
}

void pinInit()
{
   //speaker
  pinMode(9,OUTPUT);//speaker init
  audioSD.speakerPin = 9;

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
