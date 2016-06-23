#include <stdio.h>
#include "calculator_functions.h"

/* read the 2 number and one character by the order of 
number, character, number. And return the result by given
two numbers and math operator. As long as no invalid input 
or EOF, the programme will keep running. Otherwise, the 
programme will print "Invalid Input. Exiting." and exit.*/

int main(){
  while(1){
    int n;
    int m;
    char a;
    printf("Please enter your Math problem:\n");
    int count1 = scanf("%d", &n);
    int count2 = scanf(" %c", &a);
    int count3 = scanf(" %d", &m);
    if(count1 != 1||count2 != 1||count3 !=1) break;
    if(a != '+'&&a != '-'&&a != '*'&&a != '/') break;
    int result;
    if(a == '+'){
      result = math(plus, n, m);
    }
    else if (a == '-'){
      result = math(minus, n, m);
    }
    else if (a == '*'){
      result = math(times, n, m);
    }
    else {
      result = math(divide, n, m); 
    }
    printf("%d %c %d = %d\n", n, a, m, result);
  }
  printf("Invalid Input. Exiting.\n");
}
