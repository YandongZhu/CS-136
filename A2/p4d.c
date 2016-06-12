#include<stdio.h>
#include"readnat.h"

int find_difference(const int low, const int high, const int counter){
  const int n = readnat();
  if (n > high&&counter == 0){
    return find_difference(n, n, 1);
  }
  else if (n > high){
    return find_difference(low, n, 1);
  }
  else if (n > 0 && n < low){
    return find_difference(n, high, 1);
  }
  else if (n > 0){
    return find_difference(low, high, 1);
  }
  else {
    return high - low; 
  }
}

int main(){
  printf("%d\n", find_difference(0,0,0));
}
