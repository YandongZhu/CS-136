#include <string.h>
#include "fun-with-strings.h"

// is_palindrome(str) determines if str is a palindrome
// Time: O(n), n is the length of str
bool is_palindrome(const char *str){
	int len = strlen(str);
  int i;
	for (i = 0; i < len / 2; ++i)
	{
		int j = len - i - 1;
		if(str[i] != str[j]) break;
	}
	return i == len / 2;
}

// pig_latin(in, out) stores the Pig Latin of "in" in "out"
// Requires: "out" is large enough to store the result
// Effects: modifies output
// Time: O(n), n is the length of "in"
void pig_latin(const char *input, char *output){
	char first = input[0];
	int i = 0;
	while(input[i]){
		output[i] = input[i + 1];
		i++;
	}
	output[i-1] = first;
	output[i] = 'a';
	output[i+1] = 'y';
}

// mostfreq(str) finds the character that occurs the most frequently in str
// Time: O(n). n is the length of str 
// Reason: the runtime for the while loop is O(n), where
//   n is the length of str. the runtime for the for loop
//   is O(1). Since the len has the upper limit of 95.
//   the second for loop is also O(1). Since the len has 
//   the upper limit of 95.
//   the overall runtime is O(n) * O(1) + O(1) = O(n).
char mostfreq(const char *str){
	int count[95] = {0};
	int len = 0;
	char symbol[95] = {0};
	int i = 0;
	while (str[i]){
    int pos = -1;
		for (int j = 0; j < len; ++j)
		{
			if(symbol[j] == str[i]){
				pos = j;
				break;
			}
    }
			if (pos == -1)
			{
				symbol[len] = str[i];
				count[len]++;
				len++;
			}
			else{
				count[pos]++;
			}
		i++;
	}
	int indicate[2] = {0, count[0]};
	for (int k = 1; k < len; ++k)
	{
		if (count[k]>indicate[1]){
			indicate[0] = k;
			indicate[1] = count[k];
		}
	}
	return symbol[indicate[0]];
}
