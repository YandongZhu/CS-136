#include <stdio.h>
#include "readnat.h"

// return the absolute value of given number n
static int abs(int n){
  if(n < 0){
    return -n;
  }
  else {
    return n;
  }
}

void cloest(int a){
  while(1){
    int b = readnat();
    int d = 0;
    if(b == 0) break;
    while (b > 0){
      int c = readnat();
      if (d == 0){
        d = c;
      }
      else if (abs(d - a) <= abs(c - a)){
      }
      else {
        d = c;
      }
      b--;
    }
    printf("%d\n", d);
  } 
}

int main(){
  int a = readnat();
  if (a == 0){
    printf("%d\n", a);
  }
  else {
    cloest(a);
  }
}
