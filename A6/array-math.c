#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "array-math.h"

int dot_product(const int a[], const int b[], int s){
	int sum = 0;
	for (int i = 0; i < s; ++i)
	{
		sum += a[i]*b[i];
	}
	return sum;
}

bool is_orthogonal(const int a[], const int b[], int s){
	int n = dot_product(a , b, s);
	return n == 0;
}



void add_to_vector(const int a[], const int b[], int c[], int s){
	for (int i = 0; i < s; ++i)
	{
		c[i] = a[i] + b[i]; 
	}
}

static bool check_rest(const int a[], const int b[], int s, int n, int start){
	while (start < s)
	{
		if (a[start] * n != b[start]) break;
		++start;
	}
	return start == s;
}

static bool check_one_zero(const int a [], const int b [], int start, int s){
	for(; start < s; start++)
	{
		if(a[start] == 0) continue;
		break;
	}
	return start == s;
}

bool is_multiple(const int a[], const int b[], int s){
	int check = 0;
	int i, n;
	for (i = 0; i < s; ++i)
	{
		if (a[i] == 0&&b[i] == 0) continue;
		if (a[i] == 0)
		{
			check = check_one_zero(a, b, i, s);
			break;
		}
		if (b[i] == 0)
		{
			check = check_one_zero(b, a, i, s);
			break;
		}
		if (a[i] % b[i] != 0&&b[i] % a[i] != 0) break;
		if (a[i] % b[i] == 0)
		{
			n = a[i] / b[i];
			check = check_rest(b, a, s, n, i + 1);
		}
		else{
			n = b[i] / a[i];
			check = check_rest(a, b, s, n, i + 1);
		}
		break;
	}
	return i == s||check;
}
