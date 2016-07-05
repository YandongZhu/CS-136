#include <stdio.h>
#include <string.h>

// static void find_string(char *string): find the max and 
//   min string of all the input string by Lexicographical
//   order.
// effect: mutate the max and min.
static void find_string(char *string);

static char sample[100]; // the current string
static char max[100]; // the current max string
static char min[100]; // the current min string

static void find_string(char *string){
	while(1){
		int m = scanf("%s", sample);
		if (m != 1) break;
		if (strcmp(max, sample) < 0)
			strcpy(max, sample);
		if (strcmp(min, sample) > 0)
			strcpy(min, sample);
	}
}

int main(){
	int n = scanf("%s", sample);
	if (n != 1)
	{
		printf("NO STRINGS\n");
		return 0;
	}
	else{
		strcpy(max, sample);
		strcpy(min, sample);
		find_string(sample);
		printf("%s ", min);
		printf("%s\n", max);
	}
}
