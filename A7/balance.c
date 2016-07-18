#include "stack.h"
#include <string.h>
#include <stdio.h>
bool is_balanced(char str[]){
  int len = strlen(str);
  int i = 0;
  int count = 0;
  while(str[i]){
    if (str[i] == '(')
      count++;
    if (str[i] == ')')
      count--;
    if (count < 0) break;
    i++;
  }
  return i == len&&count == 0;
}
