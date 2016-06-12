#include<stdio.h>
#include"readnat.h"

int find_even(const int sofar) {
const int n = readnat();
  if (n >= 0&&n % 2 == 0) {
    return find_even(sofar + 1);
  } 
  else if (n > 0) {
    return find_even(sofar);
  }
  else {
    return sofar;
  }
}

int main(void) {
  printf("%d\n", find_even(0));
}
