#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "basic_pointer.h"

int readnat(){
  int i = 0;
  int count = scanf("%d", &i);
  if(count == -1){
    return -1;
  }
  else if(i < 0){
    return -2;
  }
  else {
    return i;
  }
}

int *down_value(int *x, int *y){
	if (*x > *y)
	{
		*x = *y;
		return x;
	}
	else if (*y > *x)
	{
		*y = *x;
		return y;
	}
	return NULL;
}

struct posn *up_value(struct posn *p1, struct posn *p2){
	int p1_sum = p1->x + p1->y;
	int p2_sum = p2->x + p2->y;
	if (p1_sum > p2_sum)
	{
		p2->x = p1->x;
		p2->y = p1->y;
		return p2;
	}
	else if (p2_sum > p1_sum)
	{
		p1->x = p2->x;
		p1->y = p2->y;
		return p1;
	}
	return NULL;
} 

int read_two(int *n1, int *n2){
	int n = readnat();
	if (n == -1)
	{
		return 0;
	}
	*n1 = n;
	int m = readnat();
	if (m == -1)
	{
		return 1;
	}
	else{
		*n2 = m;
		return 2;
	}
}

bool sum_and_range(int n, int *sum, int *smallest, int *largest){
  *sum = 0;
  *smallest = 0;
  *largest = 0;
	while(n > 0){
		int a = readnat();
		if (a < 0) break;
		*sum += a;
		if (*smallest == 0||a < *smallest)
		{
			*smallest = a;
		}
		if (a > *largest)
		{
			*largest = a;
		}
		n--;
	}
	return n != 0;
}
