
#include "pitches.h"
#include "LedControl.h" //  need the library
#include <avr/pgmspace.h>
LedControl lc=LedControl(2,4,3,1); 


//IR 리모콘 : 13 
//부저 : 8 
//Datain : 2 
//clock : 4 
//CS : 3

#define melodyPin 8

unsigned long prevPlayTime = 0;
unsigned long playDuration = 0;
short int currentMelody = 0;

short int row=0,col=0;

//Mario main theme melody
short int melodySize = 535;
// 1st : count  , 2st : col , 3st :  row , 4st : 
short int base = 0,stack;
uint16_t node[60][3] = { {0,1,0},{1,3,0},{3,5,0},{5,3,0},{6,5,0},{8,7,0},{12,0,0},
                         {16,6,0},{19,5,0},{22,2,0},{25,5,0},{27,4,0},{29,3,0},{30,2,0},
                         {32,0,0},{33,1,0},{34,2,0},{35,5,0},{37,4,0},{38,7,0},{40,6,0},{42,4,0},{43,5,0},{44,2,0},
                         {48,6,0},{51,5,0},{54,2,0},{57,5,0},{59,4,0},{61,3,0},{62,2,0},
                         {64,0,0},{65,1,0},{66,2,0},{67,5,0},{69,4,0},{70,7,0},{72,6,0},{74,4,0},{75,5,0},{76,2,0}
                         };
int melody[]  = {
  0,0,0,0,0,0,0,
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

    
    short int noteDuration = 125;
 
    tone(melodyPin, melody[currentMelody], noteDuration);
    prevPlayTime = millis();
    playDuration = noteDuration * 1.30;
    
    
    //lc.clearDisplay(1);
    stack = base;
    while(true){
      if(node[stack][0] > currentMelody){
        break;
      }
      else{
        if(node[stack][2] == 8 ){
           lc.setLed(0,node[stack][1],7,false); 
           base++;
        }
        else{
          if(node[stack][2] == 0){
            lc.setLed(0,node[stack][1],node[stack][2],true); 
            node[stack][2]++;
          }
          else{
            lc.setLed(0,node[stack][1],node[stack][2]-1,false); 
            lc.setLed(0,node[stack][1],node[stack][2],true); 
            node[stack][2]++;
          }
         
        }
      }
      stack++;
    }

    
//    lc.setLed(0,col,row,true); // turns on LED at col, row
//      if(row != 0){
//        lc.setLed(0,col,row-1,false); 
//      }
//      if(row ==7){
//
//        lc.setLed(0,col,7,false); 
//      }
//      row++;
//      if(row == 8){
//        row=0;
//      }
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
  base = 0;
}

