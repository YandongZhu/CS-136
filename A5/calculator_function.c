#include <stdio.h>
#include <assert.h>

int plus(int *a, int *b){
	int n  = *a + *b;
	return n;
}

int minus(int *a, int *b){
	int n = *a - *b;
	return n;
}

int times(int *a, int *b){
	int n  = *a * *b;
	return n;
}

int divide(int *a, int *b){
	assert(*b != 0);
	int n = *a / *b;
	return n;
}

int math(int (*f)(int *, int *), int n, int m){
	int result = f(&n, &m);
	return result;
}
