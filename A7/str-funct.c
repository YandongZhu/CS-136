#include <string.h>
#include <stdbool.h>
#include "str-funct.h"
    
void letter_freq_count(const char *s, int count[]){
  int i = 0;
	while(s[i]){
		if (s[i]>='a'&&s[i]<='z')
			count[s[i]-'a']++;
		if (s[i]>='A'&&s[i]<='Z')
			count[s[i]-'A']++;
		i++;
	}
}

bool anagram(const char *s1,const char *s2){
	int count[26] = {0};
	letter_freq_count(s1, count);
	int i = 0;
  int j = 0;
	while (s2[i])
	{
		if (s2[i]>='a'&&s2[i]<='z')
			count[s2[i]-'a']--;
		if (s2[i]>='A'&&s2[i]<='Z')
			count[s2[i]-'A']--;
		i++;
	}
	for (; j < 26; ++j)
	{
		if (count[j] != 0) break;
	}
	return j == 26;
}

int ccount(const char *strings[], int len, char ch){
	int count = 0;
	if (ch>='a'&&ch<='z')
		ch = ch - 32; 
	for (int i = 0; i < len; ++i)
	{
    int j = 0;
    while (strings[i][j]){
		if (strings[i][j] == ch)
			count++;
		if (strings[i][j] == ch + 32)
			count++;
      j++;
    }
	}
	return count;
}
