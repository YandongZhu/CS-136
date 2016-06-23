#include<stdio.h>

int readnat(){
  int i = 0;
  int count = scanf("%d", &i);
  if(count == -1){
    return -1;
  }
  else if(i < 0){
    return -2;
  }
  else {
    return i;
  }
}

float readnonnegfloat(){
  float i = 0;
  int count = scanf("%f", &i);
  if(count == -1){
    return -1;
  }
  else if(i > 0){
     return i; 
  }
  else{
    return -2;
  }
};
