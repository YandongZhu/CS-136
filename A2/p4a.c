#include<stdio.h>
#include "readnat.h"

  
int find_max(const int sofar) {
const int n = readnat();
  if (n > sofar) {
    return find_max(n);
  } 
  else if (n > 0) {
    return find_max(sofar);
  }
  else {
    return sofar;
  }
}

int main(void) {
  printf("%d\n", find_max(0));
}
