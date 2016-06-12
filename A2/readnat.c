#include<stdio.h>

int readnat(){
  int i = 0;
  int count = scanf("%d", &i);
  if(count == -1){
    return -1;
  }
  else {
    return i;
  }
}
