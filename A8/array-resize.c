#include "array-resize.h"

/*
INTEGRITY STATEMENT (modify if neccessary)
  I received help from the following sources: None. 
  I am the sole author of this work .
  Sign this statement by removing the line below and entering your name
    Name: Yandong Zhu
    login ID: y268zhu
*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// static char *my_strdup(const char *s): make a duplicate
//   of a string
static char *my_strdup(const char *s) {
    char *newstr = malloc((strlen(s) + 1) * sizeof(char));
    strcpy(newstr, s);
    return newstr;
}

// static bool find_object(char *s, const char *find, int start, int s_len, int find_len): check a string contain
//   the spcific string or not
static bool find_object(char *s, const char *find, int start, int s_len, int find_len){
	int i = 0;
	if (s_len - start < find_len)
		return 0;
	while(find[i])
	{
		if (find[i] != s[start]) break;
		i++;
		start++;
	}
	return i == find_len;
}

char *replace(char *s, const char *find, const char *rep){
	int find_len = strlen(find);
	int rep_len = strlen(rep);
	int s_len = strlen(s);
	int i = 0;
	while (i <= s_len)
	{
		int check = find_object(s, find, i, s_len, find_len);
		if (check)
		{
			if(rep_len<find_len){
				char *temp = my_strdup(s);
				strcpy(s+i+rep_len, temp+i+find_len);
				free(temp);
				temp = NULL;
				for (int j = 0; j < rep_len; ++j)
				{
					s[i+j] = rep[j];
				}
			}
			else{
				s = realloc(s, (s_len - find_len + rep_len +1));
				char *temp = my_strdup(s);
				strcpy(s+i+rep_len, temp+i+find_len);
				free(temp);
				temp = NULL;
				for (int j = 0; j < rep_len; ++j)
				{
					s[i+j] = rep[j];
				}
			}
      i = i + rep_len;
      s_len = s_len + rep_len - find_len;
		}
		else
			i++;
	}
	return s;
}
