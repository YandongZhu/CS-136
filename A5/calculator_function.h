// int plus(int *a, int *b): return the sum of a and b
int plus(int *a, int *b);

// int minus(int *a, int *b): return the difference of a and b
int minus(int *a, int *b);

// int times(int *a, int *b): return the product of a and b
int times(int *a, int *b);

// int divide(int *a, int *b): return the quotient of a and b
int divide(int *a, int *b);

// int math(int (*f)(int *, int *), int n, int m): make 
// the math operation with given function and two number
// and return the result
int math(int (*f)(int *, int *), int n, int m);
