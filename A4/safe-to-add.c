#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

// check adding two int a and b will cause overflow or not
bool safe_to_add(int a, int b){
	int c = INT_MAX;
	int d = INT_MIN;
  // two limit numbers
	if (a > 0&&b > 0)
	{
		return b < c - a;
	}
	else if (a < 0&&b < 0)
	{
		return b > d - a;
	}
	else{
		return true;
	}
}
