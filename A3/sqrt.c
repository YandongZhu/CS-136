/* double count(double n, double tolerance, double c) find the square root for n and return it within the dolerance by the formula xk+1 = (xk + n/xk)/2, starting from x0 = 1*/
static double count(double n, double tolerance, double c){
	if (within_tolerance(n, c * c, tolerance))
	{
		return c;
	}
	else{
		c = (c + n / c) / 2;
		return count(n, tolerance, c);
	}
}

/* double count(double n, double tolerance, double c) find the square root for n and return it within the tolerance*/
double find_sqrt(double n, double tolerance){
	return count (n, tolerance, 1);
}
