#include <assert.h>

static int s0 = 0; // the first number in fib list
static int s1 = 1; // the second number in fib list
static int current = -1; // the current fib number

// return the nth number of the fibonacci list
int fib(int n){
	s0 = 0;
	s1 = 1;
	current = 2;
	if (n == 0)
	{
		current = n;
		return s0;
	}
	else if (n == 1)
	{
		current = n;
		return s1;
	}
	else{
		while(current < n){
			int c = s1;
			s1 = s0 + s1;
			s0 = c;
			current++;
		}
		return s1;
	}	
}

// return the next number of fibonacci list that is created 
// by function fib or next_fib
int next_fib(){
	int c = s0 + s1; // the next fib number
  if (current == 0){
    current++;
    return s1;
  }
	else if (current > 0&&current <=45)
	{
		s0 = s1;
		s1 = c;
		current++;
		return s1;
	}
	else{
		return -1;
		current = -1;
	}
}
