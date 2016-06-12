#include<stdio.h>
#include"readnat.h"

int find_division(const int sofar, const int n){
  const int a = readnat();
  if (a > sofar&&a % n == 0){
    return find_division(a,n);
  }
  else if (a > 0){
    return find_division(sofar,n);
  }
  else {
    return sofar;
  }
}

int main(){
  const int n = readnat();
  if (n == 0) {
    printf("0\n");
  }
  else {
    printf("%d\n", find_division(0,n));
  }
}
