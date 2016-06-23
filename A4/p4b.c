#include <stdio.h>
#include "readnat.h"

// return the max number of all the input compare to the 
// given number sofar
int max(int sofar){
  while (1){
    int a = readnat();
    if (a < 0) break;
    if (a > sofar){
      sofar = a;
    }
    else{
    }
  }
  return sofar;
}

// print the max number of all the input, if there is no 
// input, print -1
int main(){
  int a = readnat();
  int b = -1;
  if(a < 0){
  }
  else {
    b = max(a);
  }
  printf("%d\n", b);
}
