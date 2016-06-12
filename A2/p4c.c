#include<stdio.h>
#include"readnat.h"

int find_great(const int base, const int counter){
  const int a = readnat();
  if(a > base){
    return find_great(base,counter + 1);
  }
  else if (a >= 0){
    return find_great(base,counter);
  }
  else {
    return counter;
  }
}

int main(){
  const int n = readnat();
  printf("%d\n", find_great(n,0));
}
