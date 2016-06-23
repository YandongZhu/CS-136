#include <stdio.h>
#include "readnat.h"

// sum the input number together given first input n
int sum(int n){
  while (1){
    int a = readnat();
    if (a < 0) break;
    n = n + a;
  }
  return n;
}

// print the sum of all the input numbers. if there is no
// input, print -1
int main(){
  int a = readnat();
  int b = -1;
  if(a < 0){
  }
  else {
    b = sum(a);
  }
  printf("%d\n", b);
}
