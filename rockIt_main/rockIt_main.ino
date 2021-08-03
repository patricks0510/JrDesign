#include <pcmConfig.h>
#include <pcmRF.h>
#include <TMRpcm.h>

#include <SD.h>
#include <SPI.h>

TMRpcm audioSD;

void setup() {
  // put your setup code here, to run once:
  pinInit();

  playMusic();
}

void loop() {
  // put your main code here, to run repeatedly:
  
    //variables ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    bool playing = false; //flag for when user is playing vs just on
    
    //3 booleans used for determining expected input and which sound to play
    // bool fretIT = false;
    // bool strumIT = false;
    // bool whammyIT = false;

    //3 booleans used for determining user's given input
    bool fretted = false;
    bool strummed = false;
    bool whammied = false;

    //int used in switch case for determining user's input
    int userIn = 0;

    //########################################################################################################################    
    
    //function ***********************************************************************************************************
    //********************************************************************************************************************
    //when the user selects the start button
    playing = digitalRead(3);

    //if user selected play button
    if(playing == true)
    {
        //reset startBTN
        //digitalWrite(5) = LOW;
        
        int score = 0; //the user's score
        //reset score, just in case
        //score = 0;

        //initialize timing window, 3000 = 3 seconds
        int t_limit = 3000;

        //play sound to indicate game has started
        //sound();

        //slight delay after starting sound
        //delay(100);

        //loop through gameplay while still playing
        while(playing == true)
        {
            //generate random number 1,2, or 3 for expected input
            int e_input = random(1,3);

            //play sound of expected input
            instruction(e_input);
            
            //time remaining until valid input, max value of t_limit
            int t_remaining = t_limit;

            while(t_remaining > 0){
                //take in user's input
                //if fret buttons hit
                if(digitalRead(3) == HIGH || digitalRead(4) == HIGH || digitalRead(6) == HIGH )
                {
                    //set user input flags
                    fretted = true;
                    strummed = false;
                    whammied = false;

                    //set user input switch case controller
                    userIn = 1;
                    //break out of while loop to get next instruction
                    break;
                }
                //if strummer moved
                else if(digitalRead(23) == HIGH || digitalRead(24) == HIGH )
                {
                    strummed = true;
                    fretted = false;
                    whammied = false;

                    userIn = 2;
                    break;
                }
                //if whammy bar flexed
                else if(analogRead(25) <= 500)
                {
                    whammied = true;
                    strummed = false;
                    fretted = false;

                    userIn = 3;
                    break;
                }
                //no input given
                else
                {
                    fretted = false;
                    strummed = false;
                    whammied = false;

                    userIn = 0;
                }
                //delay and decrement remaining time
                delay(10);
                t_remaining -= 10;
            }   

            //compare user's input to expected input
            if(e_input == userIn)
            {//if user's the same as instructed

                //increment score
                score++;
                //flash green light for success
                flash(5);

                //resest user input flags
                fretted = false;
                strummed = false;
                whammied = false;
                //reset expected input
                e_input = 0;
                //reset user input
                userIn = 0;
                
                //decrement timing window, t_limit, to make game harder
                t_limit -= 10;
            }
            else
            {//if no match
                playing = false;

                //flash light for fail
                flash(7);
            }
            //if player reaches 99
            if(score >= 99)
            {
                //game ends as highscore is reached
                playing = false;

                //blink green light on and off to indicate win
                flash(5);
                flash(5);
                flash(5);
            }
        }

        //read out score once game loop is broken
        scoreOut(score);
    }
}

void flash(int pinout)
{
    digitalWrite(pinout,HIGH);
    delay(10);
    digitalWrite(pinout,LOW);
    return;
}
void instruction(int expected)
{
    //switch case to play either "Fret it!", "Strum It!", or "Whammy It!"
    switch(expected)
    {
      //fret it
      case 1:
       digitalWrite(10,HIGH);
       digitalWrite(11,LOW);
       digitalWrite(12,LOW);
       audioSD.play("Fret It.wav");
       break;
      
      //strum it
      case 2:
        digitalWrite(11,HIGH);
        digitalWrite(10,LOW);
        digitalWrite(12,LOW);
        audioSD.play("Strum It.wav");
        break;

      //whammy it
      case 3:
        digitalWrite(12,HIGH);
        digitalWrite(10,LOW);
        digitalWrite(11,LOW);
        audioSD.play("Whammy It.wav");
    }
    return;
}

void scoreOut(int score)
{
    //read file with associated score recording
    return;
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

  //LEDs
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  //LEDs for debug
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

  return;
}

void playMusic()
{
    //drive simple tune to speaker
    audioSD.play("GTRSLIDE.wav");
    delay(1000);
    audioSD.stopPlayback();
    return;
}
