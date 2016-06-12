#include <stdio.h>
#include <assert.h>

/* void fibonacci_count(const int a, const int b, const int c, const int n) print the fibonacci list start from n, n >= 3 */
static void fibonacci_count(const int a, const int b, const int c, const int n){
	if (c == n)
	{
		printf("%d.\n", a + b);
	}
	else 
	{
		printf("%d, ", a + b);
		return fibonacci_count(b, a + b, c + 1, n); 
	}
}

/* void fibonacci(const int n) print the fibonacci list start from n, n > 0*/
void fibonacci(const int n){
  assert (n > 0);
  if(n == 1){
    printf("%d.\n", 0);
  }
  else if (n == 2){
    printf("%d, %d.\n", 0, 1);
  }
  else{
	  printf("%d, %d, ", 0, 1);
	  return fibonacci_count(0, 1, 3, n);
  }
}
