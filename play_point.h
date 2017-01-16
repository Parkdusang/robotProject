LedControl tc=LedControl(2,4,3,1); 
void right_clear(){
  int i,j;
  for(i=0;i<4;i++){
    for(j=0;j<8;j++){
      tc.setLed(0,i,j,false);
    }
  }
}
void left_clear(){
   int i,j;
  for(i=4;i<8;i++){
    for(j=0;j<8;j++){
      tc.setLed(0,i,j,false);
    }
  }
}
void right_1(){
  right_clear();
  tc.setLed(0,2,7,true);
  tc.setLed(0,1,7,true);
  tc.setLed(0,0,7,true);
  
  tc.setLed(0,1,6,true);
  tc.setLed(0,1,5,true);
  tc.setLed(0,1,4,true);
  tc.setLed(0,1,3,true);

  tc.setLed(0,2,2,true);
  tc.setLed(0,1,2,true);
  tc.setLed(0,1,1,true);
}
void left_1(){
  left_clear();
  tc.setLed(0,6,7,true);
  tc.setLed(0,5,7,true);
  tc.setLed(0,4,7,true);
  
  tc.setLed(0,5,6,true);
  tc.setLed(0,5,5,true);
  tc.setLed(0,5,4,true);
  tc.setLed(0,5,3,true);

  tc.setLed(0,6,2,true);
  tc.setLed(0,5,2,true);
  tc.setLed(0,5,1,true);
}
void right_2(){
  right_clear();
  tc.setLed(0,2,7,true);
  tc.setLed(0,1,7,true);
  tc.setLed(0,0,7,true);
  
  tc.setLed(0,2,6,true);
  tc.setLed(0,2,5,true);
  tc.setLed(0,1,4,true);
  tc.setLed(0,2,4,true);
  tc.setLed(0,0,4,true);
  
  tc.setLed(0,0,3,true);
  tc.setLed(0,0,2,true);
  
  tc.setLed(0,0,1,true);
  tc.setLed(0,1,1,true);
  tc.setLed(0,2,1,true);
}
void left_2(){
  left_clear();
  tc.setLed(0,6,7,true);
  tc.setLed(0,5,7,true);
  tc.setLed(0,4,7,true);
  
  tc.setLed(0,6,6,true);
  tc.setLed(0,6,5,true);
  tc.setLed(0,5,4,true);
  tc.setLed(0,6,4,true);
  tc.setLed(0,5,4,true);
  
  tc.setLed(0,4,3,true);
  tc.setLed(0,4,2,true);
  
  tc.setLed(0,4,1,true);
  tc.setLed(0,5,1,true);
  tc.setLed(0,6,1,true);
}
void right_3(){
  right_clear();
  tc.setLed(0,2,7,true);
  tc.setLed(0,1,7,true);
  tc.setLed(0,0,7,true);
  
  tc.setLed(0,0,6,true);
  tc.setLed(0,2,6,true);
  
  tc.setLed(0,0,5,true);
  
  tc.setLed(0,1,4,true);
  tc.setLed(0,0,4,true);
  
  tc.setLed(0,0,3,true);
  tc.setLed(0,0,2,true);
  tc.setLed(0,2,2,true);
  
  tc.setLed(0,0,1,true);
  tc.setLed(0,1,1,true);
  tc.setLed(0,2,1,true);
}
void left_3(){
  left_clear();
  tc.setLed(0,6,7,true);
  tc.setLed(0,5,7,true);
  tc.setLed(0,4,7,true);
  
  tc.setLed(0,4,6,true);
  tc.setLed(0,6,6,true);
  
  tc.setLed(0,4,5,true);
  
  tc.setLed(0,5,4,true);
  tc.setLed(0,4,4,true);
  
  tc.setLed(0,4,3,true);
  tc.setLed(0,4,2,true);
  tc.setLed(0,6,2,true);
  
  tc.setLed(0,4,1,true);
  tc.setLed(0,5,1,true);
  tc.setLed(0,6,1,true);
}
void right_4(){
  right_clear();
  tc.setLed(0,0,7,true);
  tc.setLed(0,0,6,true);
  tc.setLed(0,0,5,true);
  
  tc.setLed(0,2,4,true);
  tc.setLed(0,1,4,true);
  tc.setLed(0,0,4,true);
  
  tc.setLed(0,2,3,true);
  tc.setLed(0,0,3,true);
  
  tc.setLed(0,0,2,true);
  tc.setLed(0,2,2,true);
  
  tc.setLed(0,0,1,true);
  tc.setLed(0,2,1,true);
}
void left_4(){
  left_clear();
  tc.setLed(0,4,7,true);
  tc.setLed(0,4,6,true);
  tc.setLed(0,4,5,true);
  
  tc.setLed(0,6,4,true);
  tc.setLed(0,5,4,true);
  tc.setLed(0,4,4,true);
  
  tc.setLed(0,6,3,true);
  tc.setLed(0,4,3,true);
  
  tc.setLed(0,4,2,true);
  tc.setLed(0,6,2,true);
  
  tc.setLed(0,4,1,true);
  tc.setLed(0,6,1,true);
}
void right_5(){
  right_clear();
  tc.setLed(0,0,7,true);
  tc.setLed(0,1,7,true);
  tc.setLed(0,2,7,true);
  
  tc.setLed(0,0,6,true);
  tc.setLed(0,0,5,true);
  
  tc.setLed(0,2,4,true);
  tc.setLed(0,1,4,true);
  tc.setLed(0,0,4,true);
  
  tc.setLed(0,2,3,true);
  tc.setLed(0,2,2,true);
  
  tc.setLed(0,0,1,true);
  tc.setLed(0,1,1,true);
  tc.setLed(0,2,1,true);
}
void left_5(){
  left_clear();
  tc.setLed(0,4,7,true);
  tc.setLed(0,5,7,true);
  tc.setLed(0,6,7,true);
  
  tc.setLed(0,4,6,true);
  tc.setLed(0,4,5,true);
  
  tc.setLed(0,6,4,true);
  tc.setLed(0,5,4,true);
  tc.setLed(0,4,4,true);
  
  tc.setLed(0,6,3,true);
  tc.setLed(0,6,2,true);
  
  tc.setLed(0,4,1,true);
  tc.setLed(0,5,1,true);
  tc.setLed(0,6,1,true);
}
void right_6(){
  right_clear();
  tc.setLed(0,0,7,true);
  tc.setLed(0,1,7,true);
  tc.setLed(0,2,7,true);
  
  tc.setLed(0,0,6,true);
  tc.setLed(0,2,6,true);
  
  tc.setLed(0,0,5,true);
  tc.setLed(0,2,5,true);
  
  tc.setLed(0,2,4,true);
  tc.setLed(0,1,4,true);
  tc.setLed(0,0,4,true);
  
  tc.setLed(0,2,3,true);
  tc.setLed(0,2,2,true);
  
  tc.setLed(0,0,1,true);
  tc.setLed(0,1,1,true);
  tc.setLed(0,2,1,true);
}
void left_6(){
  left_clear();
  tc.setLed(0,4,7,true);
  tc.setLed(0,5,7,true);
  tc.setLed(0,6,7,true);
  
  tc.setLed(0,4,6,true);
  tc.setLed(0,6,6,true);
  
  tc.setLed(0,4,5,true);
  tc.setLed(0,6,5,true);
  
  tc.setLed(0,6,4,true);
  tc.setLed(0,5,4,true);
  tc.setLed(0,4,4,true);
  
  tc.setLed(0,6,3,true);
  tc.setLed(0,6,2,true);
  
  tc.setLed(0,4,1,true);
  tc.setLed(0,5,1,true);
  tc.setLed(0,6,1,true);
}
void right_7(){
  right_clear();
  tc.setLed(0,0,7,true);
  tc.setLed(0,0,6,true);
  tc.setLed(0,0,5,true);
  tc.setLed(0,0,4,true);
  
  tc.setLed(0,0,3,true);
  tc.setLed(0,2,3,true);
  
  tc.setLed(0,0,2,true);
  tc.setLed(0,2,2,true);
  
  tc.setLed(0,0,1,true);
  tc.setLed(0,1,1,true);
  tc.setLed(0,2,1,true);
}
void left_7(){
  left_clear();
  tc.setLed(0,4,7,true);
  tc.setLed(0,4,6,true);
  tc.setLed(0,4,5,true);
  tc.setLed(0,4,4,true);
  
  tc.setLed(0,4,3,true);
  tc.setLed(0,6,3,true);
  
  tc.setLed(0,4,2,true);
  tc.setLed(0,6,2,true);
  
  tc.setLed(0,4,1,true);
  tc.setLed(0,5,1,true);
  tc.setLed(0,6,1,true);
}
void right_8(){
  right_clear();
  tc.setLed(0,0,7,true);
  tc.setLed(0,1,7,true);
  tc.setLed(0,2,7,true);
  
  tc.setLed(0,0,6,true);
  tc.setLed(0,2,6,true);
  
  tc.setLed(0,0,5,true);
  tc.setLed(0,2,5,true);
  
  tc.setLed(0,0,4,true);
  tc.setLed(0,1,4,true);
  tc.setLed(0,2,4,true);
  
  tc.setLed(0,0,3,true);
  tc.setLed(0,2,3,true);
  
  tc.setLed(0,0,2,true);
  tc.setLed(0,2,2,true);
  
  tc.setLed(0,0,1,true);
  tc.setLed(0,1,1,true);
  tc.setLed(0,2,1,true);
}
void left_8(){
  left_clear();
  tc.setLed(0,4,7,true);
  tc.setLed(0,5,7,true);
  tc.setLed(0,6,7,true);
  
  tc.setLed(0,4,6,true);
  tc.setLed(0,6,6,true);
  
  tc.setLed(0,4,5,true);
  tc.setLed(0,6,5,true);
  
  tc.setLed(0,4,4,true);
  tc.setLed(0,5,4,true);
  tc.setLed(0,6,4,true);
  
  tc.setLed(0,4,3,true);
  tc.setLed(0,6,3,true);
  
  tc.setLed(0,4,2,true);
  tc.setLed(0,6,2,true);
  
  tc.setLed(0,4,1,true);
  tc.setLed(0,5,1,true);
  tc.setLed(0,6,1,true);
}
void right_9(){
  right_clear();
  tc.setLed(0,0,7,true);
  tc.setLed(0,1,7,true);
  tc.setLed(0,2,7,true);
  
  tc.setLed(0,0,6,true);
  
  tc.setLed(0,0,5,true);
  
  tc.setLed(0,0,4,true);
  tc.setLed(0,1,4,true);
  tc.setLed(0,2,4,true);
  
  tc.setLed(0,0,3,true);
  tc.setLed(0,2,3,true);
  
  tc.setLed(0,0,2,true);
  tc.setLed(0,2,2,true);
  
  tc.setLed(0,0,1,true);
  tc.setLed(0,1,1,true);
  tc.setLed(0,2,1,true);
}
void left_9(){
  left_clear();
  tc.setLed(0,4,7,true);
  tc.setLed(0,5,7,true);
  tc.setLed(0,6,7,true);
  
  tc.setLed(0,4,6,true);
  
  tc.setLed(0,4,5,true);
  
  tc.setLed(0,4,4,true);
  tc.setLed(0,5,4,true);
  tc.setLed(0,6,4,true);
  
  tc.setLed(0,4,3,true);
  tc.setLed(0,6,3,true);
  
  tc.setLed(0,4,2,true);
  tc.setLed(0,6,2,true);
  
  tc.setLed(0,4,1,true);
  tc.setLed(0,5,1,true);
  tc.setLed(0,6,1,true);
}
void right_0(){
  right_clear();
  tc.setLed(0,0,7,true);
  tc.setLed(0,1,7,true);
  tc.setLed(0,2,7,true);
  
  tc.setLed(0,0,6,true);
  tc.setLed(0,2,6,true);
  
  tc.setLed(0,0,5,true);
  tc.setLed(0,2,5,true);
  
  tc.setLed(0,0,4,true);
  tc.setLed(0,2,4,true);
  
  tc.setLed(0,0,3,true);
  tc.setLed(0,2,3,true);
  
  tc.setLed(0,0,2,true);
  tc.setLed(0,2,2,true);
  
  tc.setLed(0,0,1,true);
  tc.setLed(0,1,1,true);
  tc.setLed(0,2,1,true);
}
void left_0(){
  left_clear();
  tc.setLed(0,4,7,true);
  tc.setLed(0,5,7,true);
  tc.setLed(0,6,7,true);
  
  tc.setLed(0,4,6,true);
  tc.setLed(0,6,6,true);
  
  tc.setLed(0,4,5,true);
  tc.setLed(0,6,5,true);
  
  tc.setLed(0,4,4,true);
  tc.setLed(0,6,4,true);
  
  tc.setLed(0,4,3,true);
  tc.setLed(0,6,3,true);
  
  tc.setLed(0,4,2,true);
  tc.setLed(0,6,2,true);
  
  tc.setLed(0,4,1,true);
  tc.setLed(0,5,1,true);
  tc.setLed(0,6,1,true);
}
void perpect(){
  tc.clearDisplay(0);
  tc.setLed(0,0,7,true);
  tc.setLed(0,1,7,true);
  tc.setLed(0,3,7,true);
  tc.setLed(0,4,7,true);
  tc.setLed(0,6,7,true);

  tc.setLed(0,0,6,true);
  tc.setLed(0,1,6,true);
  tc.setLed(0,3,6,true);
  tc.setLed(0,4,6,true);
  tc.setLed(0,6,6,true);

  tc.setLed(0,0,5,true);
  tc.setLed(0,1,5,true);
  tc.setLed(0,3,5,true);
  tc.setLed(0,4,5,true);
  tc.setLed(0,6,5,true);

  tc.setLed(0,0,4,true);
  tc.setLed(0,1,4,true);
  tc.setLed(0,3,4,true);
  tc.setLed(0,4,4,true);
  tc.setLed(0,6,4,true);

  tc.setLed(0,0,3,true);
  tc.setLed(0,1,3,true);
  tc.setLed(0,3,3,true);
  tc.setLed(0,4,3,true);
  tc.setLed(0,6,3,true);

  tc.setLed(0,6,2,true);
  tc.setLed(0,7,2,true);
  tc.setLed(0,6,1,true);
  
}
void score(int left,int right){
  if(left == 0)
    left_0();
   else if(left == 1)
    left_1();
   else if(left == 2)
    left_2();
   else if(left == 3)
    left_3();
   else if(left == 4)
    left_4();
   else if(left == 5)
    left_5();
   else if(left == 6)
    left_6();
   else if(left == 7)
    left_7();
   else if(left == 8)
    left_8();
   else if(left == 9)
    left_9();

   if(right == 0)
    right_0();
   else if(right == 1)
    right_1();
   else if(right == 2)
    right_2();
   else if(right == 3)
    right_3();
   else if(right == 4)
    right_4();
   else if(right == 5)
    right_5();
   else if(right == 6)
    right_6();
   else if(right == 7)
    right_7();
   else if(right == 8)
    right_8();
   else if(right == 9)
    right_9();

}

