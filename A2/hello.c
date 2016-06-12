#include <stdio.h>

int main(void)
{
  const int n = 1337;
	const int m = 4010;
	printf("Hello,\n\n");
	printf("This is a test to see if you can use the C printf function in CS %d.\n\n", 136);
	printf("Watch your spacing very carefully.\n");
  printf("                   ~~~~~~~~~~~~~~\n\n");
  printf("You can assume there are no spaces at the end of the lines.\n\n");
  printf("One restriction: you cannot use numbers directly.\n\n");
   printf("So, in order to print the fun number %d and %d, you must use %%d.\n\n", n, m);
  printf("Also, please define:\n\n");
  printf("const int n = %d;\n\n",n);
  printf("const int m = %d;\n\n",m);
  printf("And then use m and n (and %%d) to print:\n");
	printf("\"The sum of %d and %d is %d!\".\n\n", n, m, n + m);
  printf("Don't forget to put a newline (\\n) at the end of the last line.\n");
	return 0;
}
