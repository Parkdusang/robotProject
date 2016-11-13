
#include "pitches.h"
#include "LedControl.h" //  need the library
LedControl lc=LedControl(2,4,3,1); // 
 
#define melodyPin 5

unsigned long prevPlayTime = 0;
unsigned long playDuration = 0;
int currentMelody = 0;

int row=0,col=0;


 
//Mario main theme melody
int melodySize = 528;
int checker=0;
int melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7, 0, NOTE_C7, NOTE_E7, 0, NOTE_G7, 0, 0,  0, NOTE_G6, 0, 0, 0, 
  NOTE_C7, 0, 0, NOTE_G6, 0, 0, NOTE_E6, 0, 0, NOTE_A6, 0, NOTE_B6, 0, NOTE_AS6, NOTE_A6, 0, 
  NOTE_G6, NOTE_E7, NOTE_G7, NOTE_A7, 0, NOTE_F7, NOTE_G7, 0, NOTE_E7,  0,NOTE_C7, NOTE_D7, NOTE_B6, 0, 0, 0,
  NOTE_C7, 0, 0, NOTE_G6, 0, 0, NOTE_E6, 0, 0, NOTE_A6, 0, NOTE_B6, 0, NOTE_AS6, NOTE_A6, 0, 
  NOTE_G6, NOTE_E7, NOTE_G7, NOTE_A7, 0, NOTE_F7, NOTE_G7, 0, NOTE_E7, 0,NOTE_C7, NOTE_D7, NOTE_B6, 0, 0, 0,
  0, NOTE_G7 ,NOTE_FS7 ,NOTE_F7 ,NOTE_DS7 ,0,NOTE_E7,0, NOTE_GS6, NOTE_A6, NOTE_C7,0, NOTE_A6, NOTE_C7,NOTE_D7, 0,
  0, NOTE_G7 ,NOTE_FS7 , NOTE_F7 ,NOTE_DS7,0, NOTE_E7,0, NOTE_C8,0, NOTE_C8,NOTE_C8,0,0,0,0,
  0, NOTE_G7 ,NOTE_FS7 ,NOTE_F7 ,NOTE_DS7 ,0,NOTE_E7,0, NOTE_GS6, NOTE_A6, NOTE_C7,0, NOTE_A6, NOTE_C7,NOTE_D7, 0,
  0, NOTE_DS7,0 ,0, NOTE_D7,0 ,0,NOTE_C7,0,0,0,0,0,0,0,  
  NOTE_C7, NOTE_C7, 0, NOTE_C7, 0, NOTE_C7, NOTE_D7, 0, NOTE_E7, NOTE_C7,0, NOTE_A6, NOTE_G6 ,0,0,0,
  NOTE_C7, NOTE_C7, 0, NOTE_C7, 0, NOTE_C7, NOTE_D7, 0, NOTE_E7, 0, 0, 0, 0, 0, 0, 0,
  NOTE_C7, NOTE_C7, 0, NOTE_C7, 0, NOTE_C7, NOTE_D7, 0, NOTE_E7, NOTE_C7,0, NOTE_A6, NOTE_G6 ,0,0,0,
  NOTE_E7, NOTE_E7, 0, NOTE_E7, 0, NOTE_C7, NOTE_E7, 0, NOTE_G7, 0, 0,  0, NOTE_G6, 0, 0, 0, 
  NOTE_C7, 0, 0, NOTE_G6, 0, 0, NOTE_E6, 0, 0, NOTE_A6, 0, NOTE_B6, 0, NOTE_AS6, NOTE_A6, 0,
  NOTE_G6, NOTE_E7, NOTE_G7, NOTE_A7, 0, NOTE_F7, NOTE_G7, 0, NOTE_E7,  0,NOTE_C7, NOTE_D7, NOTE_B6, 0, 0,
  NOTE_C7, 0, 0, NOTE_G6, 0, 0, NOTE_E6, 0, 0, NOTE_A6, 0, NOTE_B6, 0, NOTE_AS6, NOTE_A6, 0, 
  NOTE_G6, NOTE_E7, NOTE_G7, NOTE_A7, 0, NOTE_F7, NOTE_G7, 0, NOTE_E7,  0,NOTE_C7, NOTE_D7, NOTE_B6, 0, 0,  
  NOTE_E7, NOTE_C7,0, NOTE_G6,0, NOTE_GS6, 0 , NOTE_A6, NOTE_F7,0, NOTE_F7, NOTE_A6,0,0,0,0,
  NOTE_G6, NOTE_A7,0, NOTE_A7,NOTE_A7,NOTE_G7,0 , NOTE_F7,NOTE_E7, NOTE_C7, 0, NOTE_A6, NOTE_G6,0,0,0,
  NOTE_E7, NOTE_C7,0, NOTE_G6,0, NOTE_GS6, 0 , NOTE_A6, NOTE_F7,0, NOTE_F7, NOTE_A6,0,0,0,0,
  NOTE_G6, NOTE_F7,0, NOTE_F7, NOTE_F7, NOTE_E7,0 ,NOTE_D7,NOTE_C7,0,0,0,0,0,0,0,
  NOTE_E7, NOTE_C7, 0 , NOTE_G6,0, NOTE_GS6, 0 , NOTE_A6, NOTE_F7,0, NOTE_F7, NOTE_A6,0,0,0,0,
  NOTE_G6, NOTE_A7,0, NOTE_A7,NOTE_A7,NOTE_G7,0 , NOTE_F7,NOTE_E7, NOTE_C7, 0, NOTE_A6, NOTE_G6,0,0,0, 
  NOTE_E7, NOTE_C7,0, NOTE_G6,0, NOTE_GS6, 0 , NOTE_A6, NOTE_F7,0, NOTE_F7, NOTE_A6,0,0,0,0,
  NOTE_G6, NOTE_F7,0, NOTE_F7, NOTE_F7, NOTE_E7,0 ,NOTE_D7,NOTE_C7,0,0,0,0,0,0,0,
  NOTE_C7, NOTE_C7, 0, NOTE_C7, 0, NOTE_C7, NOTE_D7, 0, NOTE_E7, NOTE_C7,0, NOTE_A6, NOTE_G6 ,0,0,0,
  NOTE_C7, NOTE_C7, 0, NOTE_C7, 0, NOTE_C7, NOTE_D7, 0, NOTE_E7, 0, 0, 0, 0, 0, 0, 0,
  NOTE_C7, NOTE_C7, 0, NOTE_C7, 0, NOTE_C7, NOTE_D7, 0, NOTE_E7, NOTE_C7,0, NOTE_A6, NOTE_G6 ,0,0,0, 
  NOTE_E7, NOTE_E7, 0, NOTE_E7, 0, NOTE_C7, NOTE_E7, 0, NOTE_G7, 0, 0,  0, NOTE_G6, 0, 0, 0,
  NOTE_E7, NOTE_C7,0, NOTE_G6,0, NOTE_GS6, 0 , NOTE_A6, NOTE_F7,0, NOTE_F7, NOTE_A6,0,0,0,0,
  NOTE_G6, NOTE_A7,0, NOTE_A7, NOTE_A7 ,NOTE_G7, 0 , NOTE_F7 ,NOTE_E7 ,NOTE_C7,0 ,NOTE_A6 ,NOTE_G6,0,0,0,
  NOTE_E7, NOTE_C7,0, NOTE_G6,0, NOTE_GS6, 0 , NOTE_A6, NOTE_F7,0, NOTE_F7, NOTE_A6,0,0,0,0,
  NOTE_B6, NOTE_F7,0, NOTE_F7,NOTE_F7,NOTE_E7,0, NOTE_D7, NOTE_C7,0,0,0,0,0,0,0
  };
//Mario main them tempo


 
 
void sing() {
    if(millis() < prevPlayTime + playDuration) {
        // music is playing. do nothing
        return;
    }
    // stop the tone playing:
    noTone(8);
    
    if(currentMelody >= melodySize)
        currentMelody = 0;
    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

    
    int noteDuration = 125;
 
    tone(melodyPin, melody[currentMelody], noteDuration);
    prevPlayTime = millis();
    playDuration = noteDuration * 1.30;


    
    lc.setLed(0,col,row,true); // turns on LED at col, row
      if(row != 0){
        lc.setLed(0,col,row-1,false); 
      }
      if(row ==7){

        lc.setLed(0,col,7,false); 
      }
      row++;
      if(row == 8){
        row=0;
      }
    currentMelody++;
}
 
 
 
void setup() {
  pinMode(melodyPin, OUTPUT);
  lc.shutdown(0,false);// turn off power saving, enables display
  lc.setIntensity(0,8);// sets brightness (0~15 possible values)
  lc.clearDisplay(0);// clear screen
 
  lc.shutdown(1,false);// turn off power saving, enables display
  lc.setIntensity(1,8);// sets brightness (0~15 possible values)
  lc.clearDisplay(1);// clear screen
}
 
void loop() {
  // Do what you want
 
  // play music
  sing();
}

