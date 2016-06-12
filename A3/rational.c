#include <stdio.h>
#include "rational.h"

struct rational {
  int num;
  int den;
};

// See interface for purpose statement and requirements
struct rational R(int n, int d) {
  assert(d != 0);
  const struct rational r = {n, d};
  return r;
}

// Your code below


// find the greatest common divisor for a and b
// b != 0
static int gcd(int a, int b){
	int c = a % b;
	if (c == 0&&b < 0)
	{
		return -b;
	}
	else if (c == 0)
	{
		return b;
	}
	else{
		return gcd(b, a % b);
  }
};
	

// simplify(int n, int d) returns the simplified rational,
// according to the rule 
struct rational simplify(int n, int d){
	assert(d != 0);
	int c = gcd(n, d);
	if (n == 0)
	{
		return R(0, 1);
	}
	else if (d < 0)
	{
		return simplify(-n, -d);
	}
	else if (c == d)
	{
		return R(n / d, 1);
	}
	else{
		return R(n / c, d / c);
	}
}; 

// r_add(a,b) returns a rational representing the sum a + b
// requires: a,b are valid rationals
struct rational r_add(struct rational a, struct rational b){
	int n1 = a.num * b.den;
	int n2 = b.num * a.den;
	int d = a.den * b.den;
	return simplify(n1 + n2, d);
};

// r_sub(a,b) returns a rational representing the difference a - b
// requires: a,b are valid rationals
struct rational r_sub(struct rational a, struct rational b){
	int n1 = a.num * b.den;
	int n2 = b.num * a.den;
	int d = a.den * b.den;
	return simplify(n1 - n2, d);
};

// r_mult(a,b) returns a rational representing the product a * b
// requires: a,b are valid rationals
struct rational r_mult(struct rational a, struct rational b){
	int n = a.num * b.num;
	int d = a.den * b.den;
	return simplify(n, d);
};

// r_div(a,b) returns a rational representing the division a / b
// requires: a,b are valid rationals and b is non-zero
struct rational r_div(struct rational a, struct rational b){
	int n = a.num * b.den;
	int d = a.den * b.num;
	return simplify(n,d);
};

// r_equal(a,b) returns 1 if a and b represent the same rational number
//   and 0 otherwise
// requires: a,b are valid rationals
bool r_equal(struct rational a, struct rational b){
	struct rational x = simplify(a.num, a.den);
	struct rational y = simplify(b.num, b.den);
	if (x.num == y.num&&x.den == y.den)
	{
		return true;
	}
	else{
		return false;
	}
};
