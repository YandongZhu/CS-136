#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

char *my_strappend(const char *s1, const char *s2){
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	char *combine = malloc((l1 + l2 + 2) * sizeof(char));
	int i = 0;
	while(s1[i]){
		combine[i] = s1[i];
		++i;
	}
	for (int j = 0; j < l2; ++j)
	{
		combine[i] = s2[j];
		++i;
	}
  combine[i] = 0;
	return combine;
}

char *hex_to_bin(const char *h){
	int len = strlen(h);
	char *hex = malloc((4 * len + 1) * sizeof(char));
	int i = 0;
	for (int j = 0; j < len; ++j)
	{
		if (h[j] == '0')
		{
			hex[i] = '0';
			hex[i+1] = '0';
			hex[i+2] = '0';
			hex[i+3] = '0';
		}
		if (h[j] == '1')
		{
			hex[i] = '0';
			hex[i+1] = '0';
			hex[i+2] = '0';
			hex[i+3] = '1';
		}
		if (h[j] == '2')
		{
			hex[i] = '0';
			hex[i+1] = '0';
			hex[i+2] = '1';
			hex[i+3] = '0';
		}
		if (h[j] == '3')
		{
			hex[i] = '0';
			hex[i+1] = '0';
			hex[i+2] = '1';
			hex[i+3] = '1';
		}
		if (h[j] == '4')
		{
			hex[i] = '0';
			hex[i+1] = '1';
			hex[i+2] = '0';
			hex[i+3] = '0';
		}
		if (h[j] == '5')
		{
			hex[i] = '0';
			hex[i+1] = '1';
			hex[i+2] = '0';
			hex[i+3] = '1';
		}
		if (h[j] == '6')
		{
			hex[i] = '0';
			hex[i+1] = '1';
			hex[i+2] = '1';
			hex[i+3] = '0';
		}
		if (h[j] == '7')
		{
			hex[i] = '0';
			hex[i+1] = '1';
			hex[i+2] = '1';
			hex[i+3] = '1';
		}
		if (h[j] == '8')
		{
			hex[i] = '1';
			hex[i+1] = '0';
			hex[i+2] = '0';
			hex[i+3] = '0';
		}
		if (h[j] == '9')
		{
			hex[i] = '1';
			hex[i+1] = '0';
			hex[i+2] = '0';
			hex[i+3] = '1';
		}
		if (h[j] == 'A')
		{
			hex[i] = '1';
			hex[i+1] = '0';
			hex[i+2] = '1';
			hex[i+3] = '0';
		}
		if (h[j] == 'B')
		{
			hex[i] = '1';
			hex[i+1] = '0';
			hex[i+2] = '1';
			hex[i+3] = '1';
		}
		if (h[j] == 'C')
		{
			hex[i] = '1';
			hex[i+1] = '1';
			hex[i+2] = '0';
			hex[i+3] = '0';
		}
		if (h[j] == 'D')
		{
			hex[i] = '1';
			hex[i+1] = '1';
			hex[i+2] = '0';
			hex[i+3] = '1';
		}
		if (h[j] == 'E')
		{
			hex[i] = '1';
			hex[i+1] = '1';
			hex[i+2] = '1';
			hex[i+3] = '0';
		}
		if (h[j] == 'F')
		{
			hex[i] = '1';
			hex[i+1] = '1';
			hex[i+2] = '1';
			hex[i+3] = '1';
		}
		i += 4;
	}
	hex[i] = 0;
	return hex;
}
