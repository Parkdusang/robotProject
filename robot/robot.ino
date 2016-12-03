#include "pitches.h"
#include "IRremote.h"
#include "LedControl.h" //  need the library
#include <avr/pgmspace.h>
LedControl lc=LedControl(2,4,3,1); 
IRrecv irrecv(13);
IRrecv irrecv2(12);
decode_results results,results2;

//IR 리모콘 : 13 
//부저 : 8 
//Datain : 2 
//clock : 4 
//CS : 3
//led 9, 10

#define melodyPin 8
short int countaaa = 0;
boolean checkinput =false;
unsigned long prevPlayTime = 0;
unsigned long playDuration = 0;
short int currentMelody = 0;
unsigned int getFlashInt;
short int row=0,col=0;
short int noteDuration = 180;
short int i =0,checksum =0;
//Mario main theme melody
short int melodySize = 279;
short int basestack1 = 0,stack1;
short int node[138][3] = { {0,1,0},{1,3,0},{3,5,0},{5,3,0},{6,5,0},{8,7,0},{12,0,0},
                         {16,6,0},{19,5,0},{22,2,0},{25,5,0},{27,4,0},{29,3,0},{30,2,0},
                         {32,0,0},{33,1,0},{34,2,0},{35,5,0},{37,4,0},{38,7,0},{40,6,0},{42,4,0},{43,5,0},{44,2,0},
                         {48,6,0},{51,5,0},{54,2,0},{57,5,0},{59,4,0},{61,3,0},{62,2,0},
                         {64,0,0},{65,1,0},{66,2,0},{67,5,0},{69,4,0},{70,7,0},{72,6,0},{74,4,0},{75,5,0},{76,2,0},
                         {81,6,0},{82,5,0},{83,3,0},{84,2,0}, {86,4,0}, {88,0,0},{89,1,0},{90,2,0}, {92,2,0},{93,3,0},{94,4,0},
                         {97,7,0},{98,6,0},{99,5,0},{100,3,0},{102,4,0},{104,7,0},{105,6,0},{106,7,0},
                         {113,6,0},{114,5,0},{115,3,0},{116,2,0}, {118,4,0}, {120,0,0},{121,1,0},{122,2,0}, {124,2,0},{125,3,0},{126,4,0},
                         {129,6,0},{132,3,0},{135,1,0},  
                         {144,2,0},{145,3,0},{147,4,0},{149,5,0},{150,6,0},{152,7,0},{153,5,0},{155,3,0},{156,1,0},
                         {160,0,0},{161,1,0},{163,2,0},{165,5,0},{166,6,0},{168,7,0},
                         {176,2,0},{177,3,0},{179,4,0},{181,5,0},{182,6,0},{184,7,0},{185,5,0},{187,3,0},{188,1,0},
                         {192,1,0},{193,3,0},{195,5,0},{197,3,0},{198,5,0},{200,7,0},{204,0,0},


                         {208,7,0},{209,5,0},{211,1,0},{213,4,0},{215,5,0},{216,6,0},{218,7,0},{219,5,0},
                         {224,0,0},{225,1,0},{227,2,0},{228,3,0},{229,4,0},{231,5,0},{232,6,0},{233,7,0},{235,5,0},{236,3,0},
                         {240,7,0},{241,5,0},{243,1,0},{245,4,0},{247,5,0},{248,6,0},{250,7,0},{251,5,0}, 
                         {256,2,0},{257,3,0},{259,4,0},{260,3,0},{261,5,0},{263,2,0},{264,1,0},

                        
                         };

// 7 , 7 , 10,  7 , 10 , 11 , 8 , 11 , 3 , 9,      6 , 9 , 7 ,7, 10 ,7 , 10 , 8 , 10, 8 ,     7 ,8 ,10 , 8 , 7
const PROGMEM  uint16_t melody[]  = {
  0,0,0,0,0,0,0,
  NOTE_E7, NOTE_E7, 0, NOTE_E7, 0, NOTE_C7, NOTE_E7, 0, NOTE_G7, 0, 0,  0, NOTE_G6, 0, 0, 0, 
  NOTE_C7, 0, 0, NOTE_G6, 0, 0, NOTE_E6, 0, 0, NOTE_A6, 0, NOTE_B6, 0, NOTE_AS6, NOTE_A6, 0, 
  NOTE_G6, NOTE_E7, NOTE_G7, NOTE_A7, 0, NOTE_F7, NOTE_G7, 0, NOTE_E7, 0,NOTE_C7, NOTE_D7, NOTE_B6, 0, 0, 0,
  NOTE_C7, 0, 0, NOTE_G6, 0, 0, NOTE_E6, 0, 0, NOTE_A6, 0, NOTE_B6, 0, NOTE_AS6, NOTE_A6, 0, 
  NOTE_G6, NOTE_E7, NOTE_G7, NOTE_A7, 0, NOTE_F7, NOTE_G7, 0, NOTE_E7, 0,NOTE_C7, NOTE_D7, NOTE_B6, 0, 0, 0,
  
  0, NOTE_G7 ,NOTE_FS7 ,NOTE_F7 ,NOTE_DS7 ,0,NOTE_E7,0, NOTE_GS6, NOTE_A6, NOTE_C7,0, NOTE_A6, NOTE_C7,NOTE_D7, 0,
  0, NOTE_G7 ,NOTE_FS7 , NOTE_F7 ,NOTE_DS7,0, NOTE_E7,0, NOTE_C8,0, NOTE_C8, NOTE_C8,0,0,0,0,
  0, NOTE_G7 ,NOTE_FS7 ,NOTE_F7 ,NOTE_DS7 ,0,NOTE_E7,0, NOTE_GS6, NOTE_A6, NOTE_C7,0, NOTE_A6, NOTE_C7,NOTE_D7, 0,
  0, NOTE_DS7,0 ,0, NOTE_D7,0 ,0,NOTE_C7,0,0,0,0,0,0,0,0,  
  
  NOTE_C7, NOTE_C7, 0, NOTE_C7, 0, NOTE_C7, NOTE_D7, 0, NOTE_E7, NOTE_C7,0, NOTE_A6, NOTE_G6 ,0,0,0,
  NOTE_C7, NOTE_C7, 0, NOTE_C7, 0, NOTE_C7, NOTE_D7, 0, NOTE_E7, 0, 0, 0, 0, 0, 0, 0,
  NOTE_C7, NOTE_C7, 0, NOTE_C7, 0, NOTE_C7, NOTE_D7, 0, NOTE_E7, NOTE_C7,0, NOTE_A6, NOTE_G6 ,0,0,0,
  NOTE_E7, NOTE_E7, 0, NOTE_E7, 0, NOTE_C7, NOTE_E7, 0, NOTE_G7, 0, 0,  0, NOTE_G6, 0, 0, 0, 
 
  NOTE_E7, NOTE_C7,0, NOTE_G6,0, NOTE_GS6, 0 , NOTE_A6, NOTE_F7,0, NOTE_F7, NOTE_A6,0,0,0,0,
  NOTE_G6, NOTE_A7,0, NOTE_A7, NOTE_A7, NOTE_G7,0 , NOTE_F7,NOTE_E7, NOTE_C7, 0, NOTE_A6, NOTE_G6,0,0,0, 
  NOTE_E7, NOTE_C7,0, NOTE_G6,0, NOTE_GS6, 0 , NOTE_A6, NOTE_F7,0, NOTE_F7, NOTE_A6,0,0,0,0,
  NOTE_B6, NOTE_F7,0, NOTE_F7,NOTE_F7,NOTE_E7,0, NOTE_D7, NOTE_C7,0,0,0,0,0,0,0

  };
//Mario main them tempo

void setdigital(short int a){
  if(a == 1){
    digitalWrite(9 , HIGH);
    digitalWrite(10 , LOW);
    digitalWrite(11 , LOW);
  }
  else if(a == 2){
    digitalWrite(9 , LOW);
    digitalWrite(10 , LOW);
    digitalWrite(11 , HIGH);
  }
  else{
    digitalWrite(9 , LOW);
    digitalWrite(10 , HIGH);
    digitalWrite(11 , LOW);
  }
}

 
void sing() {
  while(true){
      checksum =0;
        if(millis() < prevPlayTime + playDuration) {
            // music is playing. do nothing
            continue;
        }
        // stop the tone playing:
        noTone(8);
        
        if(currentMelody >= melodySize){
            currentMelody = 0;
            basestack1 = 0;
            asm volatile ("  jmp 0");
            break;
        }
        // to calculate the note duration, take one second
        // divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    
        
        
        getFlashInt = pgm_read_word_near(melody + currentMelody);
         
        tone(melodyPin, getFlashInt, noteDuration);
        prevPlayTime = millis();
        playDuration = noteDuration * 1.30;
        
        
        //lc.clearDisplay(1);
        stack1 = basestack1;
        while(true){
          if(node[stack1][0] > currentMelody){
            break;
          }
          else{
            if(node[stack1][2] == 8 ){
               lc.setLed(0,node[stack1][1],7,false); 
                basestack1++;
            }
            else if(node[stack1][2] == 7 ){   
                for(i = 0 ; i < 8 ; i++){
                    if(checksum == 0){
                      if (irrecv.decode(&results)  || irrecv2.decode(&results2) ) {
                          if(results.value == 0xFD08F7 || results2.value == 0xFD08F7 ){
                             //case 1  
                             if(node[stack1][1] == 7){
                                if(i <4){
                                  checksum = 2;
                                }
                                else{
                                  checksum = 1;
                                }
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          else if(results.value == 0xFD8877 || results2.value == 0xFD8877 ){
                            //case 2
                            if(node[stack1][1] == 6){
                                if(i <4){
                                  checksum = 2;
                                }
                                else{
                                  checksum = 1;
                                }
                                
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          else if(results.value == 0xFD48B7 || results2.value == 0xFD48B7 ){
                            //case 3
                            if(node[stack1][1] == 5){
                                if(i <4){
                                  checksum = 2;
                                }
                                else{
                                  checksum = 1;
                                }
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          else if(results.value == 0xFD28D7 || results2.value == 0xFD28D7 ){
                            //case 4
                            if(node[stack1][1] == 4){
                                if(i <4){
                                  checksum = 2;
                                }
                                else{
                                  checksum = 1;
                                }
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          else if(results.value == 0xFDA857 || results2.value == 0xFDA857 ){
                            //case 5
                            if(node[stack1][1] == 3){
                               if(i < 4){
                                checksum = 2;
                                }
                                else{
                                  checksum = 1;
                                }
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          else if(results.value == 0xFD6897 || results2.value == 0xFD6897 ){
                            //case 6
                            if(node[stack1][1] == 2){
                                if(i < 4){
                                  checksum = 2;
                                }
                                else{
                                  checksum = 1;
                                }
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          else if(results.value == 0xFD18E7 || results2.value == 0xFD18E7 ){
                            //case 7
                            if(node[stack1][1] == 1){
                                if(i < 4){
                                  checksum = 2;
                                }
                                else{
                                  checksum = 1;
                                }
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          else if(results.value == 0xFD9867 || results2.value == 0xFD9867 ){
                            //case 8
                            if(node[stack1][1] == 0){
                                if(i < 4){
                                  checksum = 2;
                                }
                                else{
                                  checksum = 1;
                                }
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          irrecv.resume();
                          irrecv2.resume();
                      }
                      
                      delay(12);
                    }
                }
                
                lc.setLed(0,node[stack1][1],node[stack1][2]-1,false); 
                lc.setLed(0,node[stack1][1],node[stack1][2],true);  
                node[stack1][2]++;
                
                for(i = 0 ; i < 8 ; i++){
                    if(checksum == 0){
                      if (irrecv.decode(&results)  || irrecv2.decode(&results2) ) {
                          if(results.value == 0xFD08F7 || results2.value == 0xFD08F7 ){
                             //case 1  
                             if(node[stack1][1] == 7){
                                if(i <  4){
                                  checksum = 1;
                                }
                                else{
                                  checksum = 2;
                                }
                             }
                             else{
                              checksum = 3;
                             }
                          }
                          else if(results.value == 0xFD8877 || results2.value == 0xFD8877 ){
                            //case 2
                            if(node[stack1][1] == 6){
                                if(i < 4){
                                  checksum = 1;
                                }
                                else{
                                  checksum = 2;
                                }
                                
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          else if(results.value == 0xFD48B7 || results2.value == 0xFD48B7 ){
                            //case 3
                            if(node[stack1][1] == 5){
                                if(i < 4){
                                  checksum = 1;
                                }
                                else{
                                  checksum = 2;
                                }
                               
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          else if(results.value == 0xFD28D7 || results2.value == 0xFD28D7 ){
                            //case 4
                            if(node[stack1][1] == 4){
                                if(i < 4){
                                  checksum = 1;
                                }
                                else{
                                  checksum = 2;
                                }
                                
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          else if(results.value == 0xFDA857 || results2.value == 0xFDA857 ){
                            //case 5
                            if(node[stack1][1] == 3){
                                if(i < 4){
                                  checksum = 1;
                                }
                                else{
                                  checksum = 2;
                                }
                                
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          else if(results.value == 0xFD6897 || results2.value == 0xFD6897 ){
                            //case 6
                            if(node[stack1][1] == 2){
                                if(i < 4){
                                  checksum = 1;
                                }
                                else{
                                  checksum = 2;
                                }
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          else if(results.value == 0xFD18E7 || results2.value == 0xFD18E7 ){
                            //case 7
                            if(node[stack1][1] == 1){
                                if(i < 4){
                                  checksum = 1;
                                }
                                else{
                                  checksum = 2;
                                }
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          else if(results.value == 0xFD9867 || results2.value == 0xFD9867 ){
                            //case 8
                            if(node[stack1][1] == 0){
                               if(i < 4){
                                  checksum = 1;
                                }
                                else{
                                  checksum = 2;
                                }
                               
                             }
                             else{
                                checksum = 3;
                             }
                          }
    
                          irrecv.resume();
                          irrecv2.resume();
                      }
                      
                      delay(12);
                    }
                }
                
                
                setdigital(checksum);
    
                
               
            }
            else{
              if(node[stack1][2] == 0){
                lc.setLed(0,node[stack1][1],node[stack1][2],true); 
                node[stack1][2]++;
              }
              else{
                lc.setLed(0,node[stack1][1],node[stack1][2]-1,false); 
                lc.setLed(0,node[stack1][1],node[stack1][2],true); 
                node[stack1][2]++;
              }
             
            }
          }
          stack1++;
        }
    
        currentMelody++;
  }
}

void sing2() {
  while(true){
      checksum =0;
        if(millis() < prevPlayTime + playDuration) {
            // music is playing. do nothing
            continue;
        }
        // stop the tone playing:
        noTone(8);
        
        if(currentMelody >= melodySize){
            currentMelody = 0;
            basestack1 = 0;
            asm volatile ("  jmp 0");
            break;
        }
        // to calculate the note duration, take one second
        // divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    
        
        
        getFlashInt = pgm_read_word_near(melody + currentMelody);
         
        tone(melodyPin, getFlashInt, noteDuration);
        prevPlayTime = millis();
        playDuration = noteDuration * 1.30;
        
        
        //lc.clearDisplay(1);
        stack1 = basestack1;
        while(true){
          if(node[stack1][0] > currentMelody){
            break;
          }
          else{
            if(node[stack1][2] == 8 ){
               lc.setLed(0,node[stack1][1],7,false); 
                basestack1++;
            }
            else if(node[stack1][2] == 7 ){   
                for(i = 0 ; i < 8 ; i++){
                    if(checksum == 0){
                      if (irrecv.decode(&results)  || irrecv2.decode(&results2) ) {
                          if(results.value == 0xFD08F7 || results2.value == 0xFD08F7 ){
                             //case 1  
                             if(node[stack1][1] == 7){
                                if(i <4){
                                  checksum = 2;
                                }
                                else{
                                  checksum = 1;
                                }
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          else if(results.value == 0xFD8877 || results2.value == 0xFD8877 ){
                            //case 2
                            if(node[stack1][1] == 6){
                                if(i <4){
                                  checksum = 2;
                                }
                                else{
                                  checksum = 1;
                                }
                                
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          else if(results.value == 0xFD48B7 || results2.value == 0xFD48B7 ){
                            //case 3
                            if(node[stack1][1] == 5){
                                if(i <4){
                                  checksum = 2;
                                }
                                else{
                                  checksum = 1;
                                }
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          else if(results.value == 0xFD28D7 || results2.value == 0xFD28D7 ){
                            //case 4
                            if(node[stack1][1] == 4){
                                if(i <4){
                                  checksum = 2;
                                }
                                else{
                                  checksum = 1;
                                }
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          else if(results.value == 0xFDA857 || results2.value == 0xFDA857 ){
                            //case 5
                            if(node[stack1][1] == 3){
                               if(i < 4){
                                checksum = 2;
                                }
                                else{
                                  checksum = 1;
                                }
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          else if(results.value == 0xFD6897 || results2.value == 0xFD6897 ){
                            //case 6
                            if(node[stack1][1] == 2){
                                if(i < 4){
                                  checksum = 2;
                                }
                                else{
                                  checksum = 1;
                                }
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          else if(results.value == 0xFD18E7 || results2.value == 0xFD18E7 ){
                            //case 7
                            if(node[stack1][1] == 1){
                                if(i < 4){
                                  checksum = 2;
                                }
                                else{
                                  checksum = 1;
                                }
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          else if(results.value == 0xFD9867 || results2.value == 0xFD9867 ){
                            //case 8
                            if(node[stack1][1] == 0){
                                if(i < 4){
                                  checksum = 2;
                                }
                                else{
                                  checksum = 1;
                                }
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          irrecv.resume();
                          irrecv2.resume();
                      }
                      
                      delay(12);
                    }
                }
                
                lc.setLed(0,node[stack1][1],node[stack1][2]-1,false); 
                lc.setLed(0,node[stack1][1],node[stack1][2],true);  
                node[stack1][2]++;
                
                for(i = 0 ; i < 8 ; i++){
                    if(checksum == 0){
                      if (irrecv.decode(&results)  || irrecv2.decode(&results2) ) {
                          if(results.value == 0xFD08F7 || results2.value == 0xFD08F7 ){
                             //case 1  
                             if(node[stack1][1] == 7){
                                if(i <  4){
                                  checksum = 1;
                                }
                                else{
                                  checksum = 2;
                                }
                             }
                             else{
                              checksum = 3;
                             }
                          }
                          else if(results.value == 0xFD8877 || results2.value == 0xFD8877 ){
                            //case 2
                            if(node[stack1][1] == 6){
                                if(i < 4){
                                  checksum = 1;
                                }
                                else{
                                  checksum = 2;
                                }
                                
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          else if(results.value == 0xFD48B7 || results2.value == 0xFD48B7 ){
                            //case 3
                            if(node[stack1][1] == 5){
                                if(i < 4){
                                  checksum = 1;
                                }
                                else{
                                  checksum = 2;
                                }
                               
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          else if(results.value == 0xFD28D7 || results2.value == 0xFD28D7 ){
                            //case 4
                            if(node[stack1][1] == 4){
                                if(i < 4){
                                  checksum = 1;
                                }
                                else{
                                  checksum = 2;
                                }
                                
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          else if(results.value == 0xFDA857 || results2.value == 0xFDA857 ){
                            //case 5
                            if(node[stack1][1] == 3){
                                if(i < 4){
                                  checksum = 1;
                                }
                                else{
                                  checksum = 2;
                                }
                                
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          else if(results.value == 0xFD6897 || results2.value == 0xFD6897 ){
                            //case 6
                            if(node[stack1][1] == 2){
                                if(i < 4){
                                  checksum = 1;
                                }
                                else{
                                  checksum = 2;
                                }
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          else if(results.value == 0xFD18E7 || results2.value == 0xFD18E7 ){
                            //case 7
                            if(node[stack1][1] == 1){
                                if(i < 4){
                                  checksum = 1;
                                }
                                else{
                                  checksum = 2;
                                }
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          else if(results.value == 0xFD9867 || results2.value == 0xFD9867 ){
                            //case 8
                            if(node[stack1][1] == 0){
                               if(i < 4){
                                  checksum = 1;
                                }
                                else{
                                  checksum = 2;
                                }
                               
                             }
                             else{
                                checksum = 3;
                             }
                          }
    
                          irrecv.resume();
                          irrecv2.resume();
                      }
                      
                      delay(12);
                    }
                }
                
                
                setdigital(checksum);
    
                
               
            }
            else{
              if(node[stack1][2] == 0){
                lc.setLed(0,node[stack1][1],node[stack1][2],true); 
                node[stack1][2]++;
              }
              else{
                lc.setLed(0,node[stack1][1],node[stack1][2]-1,false); 
                lc.setLed(0,node[stack1][1],node[stack1][2],true); 
                node[stack1][2]++;
              }
             
            }
          }
          stack1++;
        }
    
        currentMelody++;
  }
}

void sing3() {
  while(true){
      checksum =0;
        if(millis() < prevPlayTime + playDuration) {
            // music is playing. do nothing
            continue;
        }
        // stop the tone playing:
        noTone(8);
        
        if(currentMelody >= melodySize){
            currentMelody = 0;
            basestack1 = 0;
            asm volatile ("  jmp 0");
            break;
        }
        // to calculate the note duration, take one second
        // divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    
        
        
        getFlashInt = pgm_read_word_near(melody + currentMelody);
         
        tone(melodyPin, getFlashInt, noteDuration);
        prevPlayTime = millis();
        playDuration = noteDuration * 1.30;
        
        
        //lc.clearDisplay(1);
        stack1 = basestack1;
        while(true){
          if(node[stack1][0] > currentMelody){
            break;
          }
          else{
            if(node[stack1][2] == 8 ){
               lc.setLed(0,node[stack1][1],7,false); 
                basestack1++;
            }
            else if(node[stack1][2] == 7 ){   
                for(i = 0 ; i < 8 ; i++){
                    if(checksum == 0){
                      if (irrecv.decode(&results)  || irrecv2.decode(&results2) ) {
                          if(results.value == 0xFD08F7 || results2.value == 0xFD08F7 ){
                             //case 1  
                             if(node[stack1][1] == 7){
                                if(i <4){
                                  checksum = 2;
                                }
                                else{
                                  checksum = 1;
                                }
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          else if(results.value == 0xFD8877 || results2.value == 0xFD8877 ){
                            //case 2
                            if(node[stack1][1] == 6){
                                if(i <4){
                                  checksum = 2;
                                }
                                else{
                                  checksum = 1;
                                }
                                
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          else if(results.value == 0xFD48B7 || results2.value == 0xFD48B7 ){
                            //case 3
                            if(node[stack1][1] == 5){
                                if(i <4){
                                  checksum = 2;
                                }
                                else{
                                  checksum = 1;
                                }
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          else if(results.value == 0xFD28D7 || results2.value == 0xFD28D7 ){
                            //case 4
                            if(node[stack1][1] == 4){
                                if(i <4){
                                  checksum = 2;
                                }
                                else{
                                  checksum = 1;
                                }
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          else if(results.value == 0xFDA857 || results2.value == 0xFDA857 ){
                            //case 5
                            if(node[stack1][1] == 3){
                               if(i < 4){
                                checksum = 2;
                                }
                                else{
                                  checksum = 1;
                                }
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          else if(results.value == 0xFD6897 || results2.value == 0xFD6897 ){
                            //case 6
                            if(node[stack1][1] == 2){
                                if(i < 4){
                                  checksum = 2;
                                }
                                else{
                                  checksum = 1;
                                }
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          else if(results.value == 0xFD18E7 || results2.value == 0xFD18E7 ){
                            //case 7
                            if(node[stack1][1] == 1){
                                if(i < 4){
                                  checksum = 2;
                                }
                                else{
                                  checksum = 1;
                                }
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          else if(results.value == 0xFD9867 || results2.value == 0xFD9867 ){
                            //case 8
                            if(node[stack1][1] == 0){
                                if(i < 4){
                                  checksum = 2;
                                }
                                else{
                                  checksum = 1;
                                }
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          irrecv.resume();
                          irrecv2.resume();
                      }
                      
                      delay(12);
                    }
                }
                
                lc.setLed(0,node[stack1][1],node[stack1][2]-1,false); 
                lc.setLed(0,node[stack1][1],node[stack1][2],true);  
                node[stack1][2]++;
                
                for(i = 0 ; i < 8 ; i++){
                    if(checksum == 0){
                      if (irrecv.decode(&results)  || irrecv2.decode(&results2) ) {
                          if(results.value == 0xFD08F7 || results2.value == 0xFD08F7 ){
                             //case 1  
                             if(node[stack1][1] == 7){
                                if(i <  4){
                                  checksum = 1;
                                }
                                else{
                                  checksum = 2;
                                }
                             }
                             else{
                              checksum = 3;
                             }
                          }
                          else if(results.value == 0xFD8877 || results2.value == 0xFD8877 ){
                            //case 2
                            if(node[stack1][1] == 6){
                                if(i < 4){
                                  checksum = 1;
                                }
                                else{
                                  checksum = 2;
                                }
                                
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          else if(results.value == 0xFD48B7 || results2.value == 0xFD48B7 ){
                            //case 3
                            if(node[stack1][1] == 5){
                                if(i < 4){
                                  checksum = 1;
                                }
                                else{
                                  checksum = 2;
                                }
                               
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          else if(results.value == 0xFD28D7 || results2.value == 0xFD28D7 ){
                            //case 4
                            if(node[stack1][1] == 4){
                                if(i < 4){
                                  checksum = 1;
                                }
                                else{
                                  checksum = 2;
                                }
                                
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          else if(results.value == 0xFDA857 || results2.value == 0xFDA857 ){
                            //case 5
                            if(node[stack1][1] == 3){
                                if(i < 4){
                                  checksum = 1;
                                }
                                else{
                                  checksum = 2;
                                }
                                
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          else if(results.value == 0xFD6897 || results2.value == 0xFD6897 ){
                            //case 6
                            if(node[stack1][1] == 2){
                                if(i < 4){
                                  checksum = 1;
                                }
                                else{
                                  checksum = 2;
                                }
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          else if(results.value == 0xFD18E7 || results2.value == 0xFD18E7 ){
                            //case 7
                            if(node[stack1][1] == 1){
                                if(i < 4){
                                  checksum = 1;
                                }
                                else{
                                  checksum = 2;
                                }
                             }
                             else{
                                checksum = 3;
                             }
                          }
                          else if(results.value == 0xFD9867 || results2.value == 0xFD9867 ){
                            //case 8
                            if(node[stack1][1] == 0){
                               if(i < 4){
                                  checksum = 1;
                                }
                                else{
                                  checksum = 2;
                                }
                               
                             }
                             else{
                                checksum = 3;
                             }
                          }
    
                          irrecv.resume();
                          irrecv2.resume();
                      }
                      
                      delay(12);
                    }
                }
                
                
                setdigital(checksum);
    
                
               
            }
            else{
              if(node[stack1][2] == 0){
                lc.setLed(0,node[stack1][1],node[stack1][2],true); 
                node[stack1][2]++;
              }
              else{
                lc.setLed(0,node[stack1][1],node[stack1][2]-1,false); 
                lc.setLed(0,node[stack1][1],node[stack1][2],true); 
                node[stack1][2]++;
              }
             
            }
          }
          stack1++;
        }
    
        currentMelody++;
  }
}
 
void setup() {
  pinMode(melodyPin, OUTPUT);
  lc.shutdown(0,false);// turn off power saving, enables display
  lc.setIntensity(0,8);// sets brightness (0~15 possible values)
  lc.clearDisplay(0);// clear screen

  lc.shutdown(1,false);// turn off power saving, enables display
  lc.setIntensity(1,8);// sets brightness (0~15 possible values)
  lc.clearDisplay(1);// clear screen

  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  irrecv.enableIRIn();
  irrecv2.enableIRIn();
}

 
void loop() {
   if (irrecv.decode(&results)  || irrecv2.decode(&results2) ) {
      if(results.value == 0xFD08F7 || results2.value == 0xFD08F7 ){
          
          checksum =0;
          sing();
      }
      else{
          checksum =0;
          sing2();
      }
   }

}
