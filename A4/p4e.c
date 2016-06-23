#include <stdio.h>
#include "readnat.h"

// print all the intermediate result if the sum will not 
// cause overflow, otherwise print overflow and reset the 
// sum to 0
void running_sum(void){
  int max = 2147483647;
  int sofar = 0;
  while(1){
    int a = readnat();
    if(a < 0) break;
    if (max - a >= sofar){
      sofar = sofar + a;
      printf("%d\n", sofar);
    }
    else{
      printf("overflow\n");
      sofar = 0;
    }
  }
}

int main(){
  running_sum();
}
