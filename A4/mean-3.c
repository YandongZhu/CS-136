int mean3(int a, int b, int c){
	int x = a / 3;
	int y = b / 3;
	int z = c / 3;
	int d = a % 3 + b % 3 + c % 3;
	int g = d / 3;
	return x + y + z + g;
}
