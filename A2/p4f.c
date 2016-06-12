#include<stdio.h>
#include"readnat.h"

int find_longest(const int sofar, const int c, const int n){
  const int a = readnat();
  if(a >= c){
  return find_longest(sofar, a, n + 1);
  }
  else if(a >= 0&&n > sofar){
  return find_longest(n, a, 1);
  }
  else if(a >= 0){
  return find_longest(sofar, a, 1);
  }
  else if(n > sofar){
  return n;
  }
  else{
  return sofar;
  }
}

int main(){
  printf("%d\n", find_longest(0, 0, 0));
  return 0;
}
