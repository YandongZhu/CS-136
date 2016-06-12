#include <stdio.h>
#include <assert.h>

/* divisors_count(const int n, const int a) try to find and print all the divisors for given number n start from a */
static void divisors_count(const int n, const int a){
	if (n == a)
	{
		printf("%d.\n", n);
	}
	else if (n % a == 0)
	{
		printf("%d, ", a);
		return divisors_count(n, a + 1);
	}
	else {
		return divisors_count(n, a + 1);
	}
}

/* print all the divisors for given number n from 1 */
void divisors(const int n){
    assert(n > 0);
  	return divisors_count(n, 1); 
}
