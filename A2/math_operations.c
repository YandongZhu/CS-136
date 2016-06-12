static int multiply_count(const int a, const int b, const int sofar){
	if (b == 0)
	{
		return sofar;
	}
	else{
		return multiply_count(a,(b - 1),(sofar + a));
	}
}

int multiply(const int a, const int b){
	if (b < 0)
	{
		return -multiply_count(a,-b,0);
	}
	else{
		return multiply_count(a,b,0);
	}
}

static int divide_count(const int a, const int b, const int c){
	if (a >= 0&&(a < b||a < -b)){
		return c;
	}
	else {
		return divide_count(a - b, b, c + 1);
	}
}

int divide(const int a, const int b){
	if((a > 0&&b < 0)||(a < 0&&b > 0)){
		return -divide_count(a, -b, 0);
	}
	else{
		return divide_count(a, b, 0);
	}
}
