#include "pitches.h"
#include "IRremote.h"
#include "LedControl.h" //  need the library
#include "play_point.h"
#include <avr/pgmspace.h>
LedControl lc=LedControl(2,4,3,1); 
IRrecv irrecv(13);
IRrecv irrecv2(12);
IRrecv irrecv3(5);
decode_results results,results2,results3;

//IR 리모콘 : 13 
//부저 : 8 
//Datain : 2 
//clock : 4 
//CS : 3

const PROGMEM  uint16_t node_1[414] ={0,1,0,1,3,0,3,5,0,5,3,0,6,5,0,8,7,0,12,0,0,
                         16,6,0,19,5,0,22,2,0,25,5,0,27,4,0,29,3,0,30,2,0,
                         32,0,0,33,1,0,34,2,0,35,5,0,37,4,0,38,7,0,40,6,0,42,4,0,43,5,0,44,2,0,
                         48,6,0,51,5,0,54,2,0,57,5,0,59,4,0,61,3,0,62,2,0,
                         64,0,0,65,1,0,66,2,0,67,5,0,69,4,0,70,7,0,72,6,0,74,4,0,75,5,0,76,2,0,
                         81,6,0,82,5,0,83,3,0,84,2,0, 86,4,0, 88,0,0,89,1,0,90,2,0, 92,2,0,93,3,0,94,4,0,
                         97,7,0,98,6,0,99,5,0,100,3,0,102,4,0,104,7,0,105,6,0,106,7,0,
                         113,6,0,114,5,0,115,3,0,116,2,0, 118,4,0, 120,0,0,121,1,0,122,2,0, 124,2,0,125,3,0,126,4,0,
                         129,6,0,132,3,0,135,1,0,  
                         144,2,0,145,3,0,147,4,0,149,5,0,150,6,0,152,7,0,153,5,0,155,3,0,156,1,0,
                         160,0,0,161,1,0,163,2,0,165,5,0,166,6,0,168,7,0,
                         176,2,0,177,3,0,179,4,0,181,5,0,182,6,0,184,7,0,185,5,0,187,3,0,188,1,0,
                         192,1,0,193,3,0,195,5,0,197,3,0,198,5,0,200,7,0,204,0,0,


                         208,7,0,209,5,0,211,1,0,213,4,0,215,5,0,216,6,0,218,7,0,219,5,0,
                         224,0,0,225,1,0,227,2,0,228,3,0,229,4,0,231,5,0,232,6,0,233,7,0,235,5,0,236,3,0,
                         240,7,0,241,5,0,243,1,0,245,4,0,247,5,0,248,6,0,250,7,0,251,5,0, 
                         256,2,0,257,3,0,259,4,0,260,3,0,261,5,0,263,2,0,264,1,0
                         };
const PROGMEM  uint16_t node_2[396] ={  // 2번째는 노드가 떨어지는 위치

                         0,1,0,1,2,0,2,3,0, 3,4,0,  5,5,0,6,6,0,   8,2,0,9,3,0,10,4,0, 11,5,0,    13,8,0,14,7,0,
                         16,6,0,17,5,0,18,4,0,  20,3,0,21,2,0,22,1,0,   24,5,0,25,4,0,26,5,0, 27,6,0,   29,4,0,30,5,0,
                         32,1,0,33,2,0,34,1,0,35,3,0,  36,4,0,37,5,0 ,38,6,0,39,7,0,41,0,0,43,1,0,
                         48,5,0,49,4,0,50,5,0,51,6,0,  53,6,0,54,7,0 ,56,0,0,

                         64,1,0,65,2,0,66,3,0, 67,4,0,  69,5,0,70,6,0,   72,2,0,73,3,0,74,4,0, 75,5,0,    77,8,0,78,7,0,
                         80,0,0,81,1,0,82,2,0,83,3,0,  84,4,0,85,3,0,86,2,0,87,1,0, 88,3,0,89,4,0,90,5,0,91,6,0,93,0,0,94,7,0,
                         96,0,0,97,2,0,98,1,0, 99,3,0,  100,2,0, 101,4,0, 102,5,0,  103,7,0, 105,6,0, 106,5,0, 107,4,0, 108,3,0, 109,2,0,
                         112,3,0,113,2,0,114,1,0, 115,0,0,117,5,0, 118,4,0,120,3,0,
                         128,2,0, 129,4,0 , 130,6,0 ,131,4,0 ,132,5,0 , 134,6,0 , 135,0,0 ,137,1,0,138,2,0, 139,3,0,140,6,0 , 141,7,0,
                         144,7,0, 145,5,0 ,146,6,0, 147,4,0 ,148,3,0,149,4,0,150,5,0,151,2,0 ,153,1,0,155,0,0,
                         160,1,0, 161,2,0, 162,3,0, 163,4,0, 166,7,0, 167,6,0, 168,3,0, 169,4,0, 170,5,0, 171,6,0, 
                         176,0,0, 177,1,0, 178,2,0, 179,1,0, 180,3,0, 182,7,0, 183,6,0, 184,4,0, 186,7,0, 188,6,0, 190,5,0, 191,4,0, 
                         192,0,0

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
  NOTE_B6, NOTE_F7,0, NOTE_F7, NOTE_F7, NOTE_E7,0 ,NOTE_D7,NOTE_C7,0,0,0,0,0,0,0
  };
//Mario main them tempo

const PROGMEM  uint16_t melody2[]  = {
  0,0,0,0,0,0,0,
  NOTE_FS6,NOTE_A6 ,NOTE_A6,NOTE_A6,0,NOTE_FS6, NOTE_A6,0 ,NOTE_FS6,NOTE_A6 ,NOTE_A6,NOTE_A6,0,NOTE_B6, NOTE_A6,0,
  NOTE_D7,NOTE_D7,NOTE_D7,0 ,NOTE_D7,NOTE_D7,NOTE_D7, 0 ,NOTE_D7, NOTE_B6,NOTE_B6,NOTE_B6, 0 ,NOTE_A6 ,NOTE_B6,0,
  NOTE_G6,NOTE_G6,NOTE_A6,NOTE_A6,NOTE_B6,NOTE_B6,NOTE_CS7,NOTE_D7,0 ,NOTE_AS6,0,NOTE_B6,0,0,0,0,
  NOTE_FS7,NOTE_FS7,NOTE_FS7,NOTE_FS7,0,NOTE_D7 ,NOTE_FS7,0,NOTE_E7,0,0,0,0,0,0,0,

  NOTE_FS6,NOTE_A6 ,NOTE_A6,NOTE_A6,0,NOTE_FS6, NOTE_A6,0 ,NOTE_FS6,NOTE_A6 ,NOTE_A6,NOTE_A6,0,NOTE_B6, NOTE_A6,0,
  NOTE_D7,NOTE_D7,NOTE_D7,NOTE_D7,NOTE_D7,NOTE_D7,NOTE_D7,NOTE_D7,NOTE_D7,NOTE_B6,NOTE_B6,NOTE_B6,0, NOTE_A6,NOTE_B6,0,
  NOTE_D7,NOTE_D7,NOTE_E7,NOTE_E7,NOTE_FS7,NOTE_FS7,NOTE_G7,NOTE_A7,0,NOTE_A7,NOTE_A7,NOTE_A7,NOTE_A7,NOTE_G7 ,0,0,
  NOTE_FS7,NOTE_FS7,NOTE_FS7,NOTE_FS7,0,NOTE_E7,NOTE_D7,0,NOTE_E7,0,0,0,0,0,0,0,

  NOTE_B6,NOTE_CS7,NOTE_D7,NOTE_CS7,NOTE_D7,0,NOTE_D7,NOTE_CS7,0,NOTE_D7,NOTE_E7,NOTE_E7,NOTE_E7,NOTE_CS7,0,0,
  
  NOTE_CS7,NOTE_B6,NOTE_CS7,NOTE_B6, NOTE_CS7,NOTE_D7,NOTE_E7,NOTE_D7,0 ,NOTE_CS7,0,NOTE_B6,0,0,0,0,
  NOTE_B6,NOTE_CS7,NOTE_D7,NOTE_D7,0,0, NOTE_D7,NOTE_B6,NOTE_CS7,NOTE_D7,NOTE_E7,NOTE_E7,0,0,0,0,
  NOTE_CS7,NOTE_D7,NOTE_E7,NOTE_D7,NOTE_FS7,0,NOTE_FS7,NOTE_B6,NOTE_FS7,0,NOTE_G7,0,NOTE_FS7,0,NOTE_E7,NOTE_E7,
  
  NOTE_D7,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0

 
  };
  


//Mario main them tempo
#define melodyPin 8
short int choice = 0;
boolean end_music =false;
unsigned long prevPlayTime = 0;
unsigned long playDuration = 0;
short int currentMelody = 0;
unsigned int getFlashInt;
short int row=0,col=0;
short int i =0,checksum =0;
//Mario main theme melody
short int melodySize = 0;
short int basestack1 = 0,stack1;
short int node[138][3];

short int perfectPoint = 0;
short int normalPoint = 0;
short int failurePoint = 0;
long beforeValue;

/////////////////////////////////////////////////////////////////////////////////////   function start
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

    if(millis() < prevPlayTime + playDuration) {
        // music is playing. do nothing
        return;
    }
    // stop the tone playing:
    noTone(8);
    
    if(currentMelody >= melodySize){
        currentMelody = 0;
        basestack1 = 0;
        end_music=true;
    }
    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

    

    short int noteDuration=170;
     
    if(choice == 0){
      getFlashInt = pgm_read_word_near(melody + currentMelody);
    }
     else{
      getFlashInt = pgm_read_word_near(melody2 + currentMelody);
    }
     
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
                for(i = 0 ; i < 10 ; i++){
                    if(checksum == 0){
                      if (irrecv.decode(&results)  || irrecv2.decode(&results2)  || irrecv3.decode(&results3)) {
                          if( (results.value == 0xFD08F7 || results2.value == 0xFD08F7 ||  results3.value == 0xFD08F7 ) && (beforeValue != 0xFD08F7) ){
                             //case 1                          
                             beforeValue = 0xFD08F7;
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
                          else if( ( results.value == 0xFD8877 || results2.value == 0xFD8877 || results3.value  == 0xFD8877 )  && ( beforeValue != 0xFD8877 )){
                            //case 2
                            beforeValue = 0xFD8877;
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
                          else if((results.value == 0xFD48B7 || results2.value == 0xFD48B7 || results3.value == 0xFD48B7) && ( beforeValue != 0xFD48B7 )){
                            //case 3
                            beforeValue = 0xFD48B7;
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
                          else if( (results.value == 0xFD28D7 || results2.value == 0xFD28D7 || results3.value == 0xFD28D7) && ( beforeValue != 0xFD28D7 )){
                            //case 4
                            beforeValue = 0xFD28D7;
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
                          else if((results.value == 0xFDA857 || results2.value == 0xFDA857 || results3.value == 0xFDA857 ) && ( beforeValue != 0xFDA857 )) {
                            //case 5
                            beforeValue = 0xFDA857;
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
                          else if( (results.value == 0xFD6897 || results2.value == 0xFD6897 || results3.value == 0xFD6897 ) &&  ( beforeValue != 0xFD6897 )){
                            //case 6
                            beforeValue = 0xFD6897;
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
                          else if((results.value == 0xFD18E7 || results2.value == 0xFD18E7 || results3.value == 0xFD18E7 ) && (beforeValue != 0xFD18E7)){
                            //case 7
                             beforeValue = 0xFD18E7;
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
                          else if( (results.value == 0xFD9867 || results2.value == 0xFD9867 || results3.value == 0xFD9867) && (beforeValue != 0xFD9867)){
                            //case 8
                            beforeValue = 0xFD9867;
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
                          irrecv3.resume();
                      }
                      
                      delay(10);
                    }
                }
                
                lc.setLed(0,node[stack1][1],node[stack1][2]-1,false); 
                lc.setLed(0,node[stack1][1],node[stack1][2],true);  
                node[stack1][2]++;
                
                for(i = 0 ; i < 10 ; i++){
                    if(checksum == 0){
                      if (irrecv.decode(&results)  || irrecv2.decode(&results2) || irrecv3.decode(&results3)) {
                          if( (results.value == 0xFD08F7 || results2.value == 0xFD08F7 || results3.value == 0xFD08F7 ) && (beforeValue != 0xFD08F7)){
                             //case 1  
                             beforeValue = 0xFD08F7;
                             if(node[stack1][1] == 7){
                                if(i <  6){
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
                          else if( (results.value == 0xFD8877 || results2.value == 0xFD8877 || results3.value == 0xFD8877 ) && (beforeValue != 0xFD8877)){
                            //case 2
                            beforeValue = 0xFD8877;
                            if(node[stack1][1] == 6){
                                if(i < 6){
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
                          else if( (results.value == 0xFD48B7 || results2.value == 0xFD48B7 || results3.value == 0xFD48B7)  && (beforeValue != 0xFD8877)){
                            //case 3
                            beforeValue = 0xFD48B7;
                            if(node[stack1][1] == 5){
                                if(i < 6){
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
                          else if( (results.value == 0xFD28D7 || results2.value == 0xFD28D7 || results3.value == 0xFD28D7 ) && (beforeValue != 0xFD28D7)){
                            //case 4
                            beforeValue = 0xFD28D7;
                            if(node[stack1][1] == 4){
                                if(i < 6){
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
                          else if( (results.value == 0xFDA857 || results2.value == 0xFDA857 || results3.value == 0xFDA857 ) && (beforeValue != 0xFDA857)){
                            //case 5
                             beforeValue = 0xFDA857;
                            if(node[stack1][1] == 3){
                                if(i < 6){
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
                          else if( (results.value == 0xFD6897 || results2.value == 0xFD6897 || results3.value == 0xFD6897 ) && (beforeValue != 0xFD6897)){
                            //case 6
                            beforeValue = 0xFD6897;
                            if(node[stack1][1] == 2){
                                if(i < 6){
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
                          else if((results.value == 0xFD18E7 || results2.value == 0xFD18E7 || results3.value == 0xFD18E7) && (beforeValue != 0xFD18E7)){
                            //case 7
                            beforeValue = 0xFD18E7;
                            if(node[stack1][1] == 1){
                                if(i < 6){
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
                          else if( (results.value == 0xFD9867 || results2.value == 0xFD9867 || results3.value == 0xFD9867) && (beforeValue != 0xFD9867)){
                            //case 8
                            beforeValue = 0xFD9867;
                            if(node[stack1][1] == 0){
                               if(i < 6){
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
                          irrecv3.resume();
                      }
                      
                      delay(10);
                    }
                }
                if( checksum ==  1){
                  perfectPoint++;
                }
                else if(checksum == 2){
                  normalPoint++;
                }
                else if(checksum == 3){
                  failurePoint++;
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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void play_music_1()
{
  short int i=0,j=0,result;
  float temp;
  melodySize = 278;
  
  for(i=0;i<414;i=i+3){
      node[j][0]=pgm_read_word_near(node_1 + i);
      node[j][1]=pgm_read_word_near(node_1 + i+1);
      node[j][2]=pgm_read_word_near(node_1 + i+2);
      j++;
    }
  beforeValue = 0xFD08F7;
  while(!end_music){
    checksum=0;
    sing();
  }
  delay(300);
  lc.clearDisplay(0);
  temp=((float)perfectPoint+(float)normalPoint)/((float)perfectPoint+(float)normalPoint+(float)failurePoint);
  temp=temp*100;
  result=(int)temp;
  if(result == 100){
    perpect();
  }
  else{
    i=result/10;
    j=result%10;
    score(i,j);
  } 
  delay(3000);
  asm volatile (" jmp 0");
  delay(10000);
}
void play_music_2()
{
  short int i=0,j=0,result;
  melodySize = 215;
  float temp;
  
  for(i=0;i<396;i=i+3){
      node[j][0]=pgm_read_word_near(node_2 + i);
      node[j][1]=pgm_read_word_near(node_2 + i+1);
      node[j][2]=pgm_read_word_near(node_2 + i+2);
      j++;
  }
  beforeValue = 0xFD08F7;
  while(!end_music){
    checksum=0;
    sing();
  }
  delay(300);
  lc.clearDisplay(0);
  temp=((float)perfectPoint+(float)normalPoint)/((float)perfectPoint+(float)normalPoint+(float)failurePoint);
  temp=temp*100;
  result=(int)temp;
  if(result == 100){
    perpect();
  }
  else{
    i=result/10;
    j=result%10;
    score(i,j);
  } 
  delay(3000);
  asm volatile ("  jmp 0"); 
  delay(10000);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
void setup() {

  pinMode(melodyPin, OUTPUT);
  lc.shutdown(0,false);// turn off power saving, enables display
  lc.setIntensity(0,8);// sets brightness (0~15 possible values)
  lc.clearDisplay(0);// clear screen

  lc.shutdown(1,false);// turn off power saving, enables display
  lc.setIntensity(1,8);// sets brightness (0~15 possible values)
  lc.clearDisplay(1);// clear screen
  irrecv.enableIRIn();
  irrecv2.enableIRIn();
  irrecv3.enableIRIn();
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
}

 
void loop() { 
  lc.setLed(0,2,0,false); 
  lc.setLed(0,5,0,false);
  lc.setLed(0,7,7,false); 
  lc.setLed(0,0,7,false);
  
  lc.setLed(0,5,1,true); 
  lc.setLed(0,2,1,true); 

  lc.setLed(0,6,2,true); 
  lc.setLed(0,5,2,true); 
  lc.setLed(0,4,2,true); 
  lc.setLed(0,3,2,true);
  lc.setLed(0,2,2,true); 
  lc.setLed(0,1,2,true);

  lc.setLed(0,7,3,true); 
  lc.setLed(0,6,3,true); 
  lc.setLed(0,4,3,true); 
  lc.setLed(0,3,3,true);
  lc.setLed(0,1,3,true); 
  lc.setLed(0,0,3,true);

  lc.setLed(0,6,4,true); 
  lc.setLed(0,5,4,true); 
  lc.setLed(0,4,4,true); 
  lc.setLed(0,3,4,true);
  lc.setLed(0,2,4,true); 
  lc.setLed(0,1,4,true);

  lc.setLed(0,6,5,true); 
  lc.setLed(0,5,5,true); 
  lc.setLed(0,4,5,true); 
  lc.setLed(0,3,5,true);
  lc.setLed(0,2,5,true); 
  lc.setLed(0,1,5,true);

  lc.setLed(0,6,6,true); 
  lc.setLed(0,1,6,true); 

  lc.setLed(0,2,7,true); 
  lc.setLed(0,5,7,true);
  lc.setLed(0,6,0,true); 
  lc.setLed(0,1,0,true); 
  delay(500);

  lc.setLed(0,2,7,false); 
  lc.setLed(0,5,7,false);
  lc.setLed(0,6,0,false); 
  lc.setLed(0,1,0,false);
  
  lc.setLed(0,2,0,true); 
  lc.setLed(0,5,0,true);
  lc.setLed(0,7,7,true); 
  lc.setLed(0,0,7,true);
  delay(500);

   
  
  
  if (irrecv.decode(&results)  || irrecv2.decode(&results2) || irrecv3.decode(&results3)) { //노래1
      if(results.value == 0xFD08F7 || results2.value == 0xFD08F7 || results3.value == 0xFD08F7){
          lc.clearDisplay(0);
          lc.setLed(0,3,6,true); 
          lc.setLed(0,4,6,true); 
          lc.setLed(0,5,6,true);

          lc.setLed(0,4,5,true); 
          lc.setLed(0,4,4,true); 
          lc.setLed(0,4,3,true);
          lc.setLed(0,4,2,true); 
          lc.setLed(0,4,1,true);

          lc.setLed(0,5,2,true);
          delay(1000);
          lc.clearDisplay(0);
          
          choice=0;
          play_music_1();
          delay(3000);
      }
      else if(results.value == 0xFD8877 || results2.value == 0xFD8877 || results3.value == 0xFD08F7){// 노래2
          lc.clearDisplay(0);
          lc.setLed(0,2,6,true); 
          lc.setLed(0,3,6,true);
          lc.setLed(0,4,6,true); 
          lc.setLed(0,5,6,true);
          lc.setLed(0,6,6,true);

          lc.setLed(0,6,5,true); 
          lc.setLed(0,6,4,true); 
          
          lc.setLed(0,3,3,true); 
          lc.setLed(0,4,3,true); 
          lc.setLed(0,5,3,true);
          
   
          lc.setLed(0,6,1,true);

          lc.setLed(0,3,0,true); 
          lc.setLed(0,4,0,true);
          lc.setLed(0,5,0,true); 
          
          lc.setLed(0,2,1,true);
          lc.setLed(0,2,2,true);
          delay(1000);
          lc.clearDisplay(0);
          
          choice=1;
          play_music_2();
          delay(3000);
      }
      irrecv.resume();
      irrecv2.resume();
      irrecv3.resume();
   }
}
