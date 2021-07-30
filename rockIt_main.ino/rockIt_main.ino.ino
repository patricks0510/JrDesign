void setup() {
  // put your setup code here, to run once:
  pinInit();

  playMusic();
}

void loop() {
  // put your main code here, to run repeatedly:
  
    //variables ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    bool playing; //flag for when user is playing vs just on
    int score; //the user's score
    
    //3 booleans used for determining expected input
    bool fretIT;
    bool strumIT;
    bool whammyIT;

    //3 booleans used for determining user's given input
    bool fretted;
    bool strummed;
    bool whammied;

    //########################################################################################################################    
    
    //function ***********************************************************************************************************
    //********************************************************************************************************************
    //when the user selects the start button, playing becomes true
    playing = (digitalRead(5)==HIGH);
    
    if(playing == true)
    {
        //reset startBTN
        digitalWrite(5) = LOW;

//      //user starts playing, set to false when failure
//      playing = true;

        //reset score
        score = 0;

        //initialize timing window
        float t_limit = 3000;//value TBD


        //loop through gameplay while still playing
        while(playing == true)
        {
            //generate random number 1,2, or 3 for expected input
            int e_input = random(1,3);

            //switch case for choosing input settings, and playing command sound
            switch (e_input)
            {
                case 1:
                    fretIT = true;
//                    //play fretIT sound
//                    sound(fretIT);
                    strumIT = false;
                    whammyIT = false;
                    break;
                case 2:
                    strumIT = true;
//                    sound(strumIT);
//                    ...
                    fretIT = false;
                    whammyIT = false;
                    break;
                case 3:
                    whammyIT = true;
                  //sound(whammyIT);
                    fretIT = false;
                    strumIT = false;
                    break;
            }

            //buffer to give user time window to carry out instruction
            delay(t_limit);

            //take in user's input
            if(fret = HIGH)
            {
                fretted = true;
            }
            else if(strum = HIGH)
            {
                strummed = true;
            }
            else if(whammy = HIGH)
            {
                whammied = true;
            }
            else
            {
                all input set false
            }

            //compare user's input to expected input
            if(e_input == users)
            {//if user's the same as instructed

                //increment score
                score++;
                //flash light for success
                flash(SUCCESS);
                //resest user inputs
                fretted = false;
                ...

                //reset expected input
                e_input = 0;
                
                //decrement timing window: t_limit
                t_limit -= 0.02 seconds;
            }
            else
            {//if no match
                //end playing game
                playing = false;

                //flash light for fail
                flash(FAIL);
            }
            //if player reaches 99
            if(score == 99)
            {
                //game ends as highscore is reached
                playing = false;
            }
        }

        //read out score once game loop is broken
        score_out(score);
    }
}

void pinInit()
{
  //speaker
  pinMode(15,OUTPUT);//speaker init

  //SD card
  pinMode(17,OUTPUT);//SD MOSI init
  pinMode(18,INPUT);//SD MISO init
  pinMode(19,INPUT);//SD clock init

  //Joystick
  pinMode(23,INPUT);//horizontal axis init
  pinMode(24,INPUT);//vertical axis init

  //Flex sensor
  pinMode(25,INPUT);//flex sensor, potentially should be INPUT_PULLUP

  //Frets
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(6,INPUT);

  //Start button
  pinMode(5,INPUT);

  //LEDs
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  return;
}

void playMusic()
{
    //drive simple tune to speaker
    return;
}
