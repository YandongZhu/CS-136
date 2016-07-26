// Runtime: O(n^2)
// Reason: the runtime for readstr is O(n). the runtime for
//   the while loop in main function is O(n), where n is 
//   the number of the strings. the for loop in the 
//   function insert is also O(n). Thus the overall runtime
//   is O(n) + O(n^2) = O(n^2) 

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static int maxlen = 32;
static int len = 0;

static char *readstr(void) {
  char c;
  if (scanf("%c", &c) != 1) return NULL;
  int maxlen = 1;
  char *str = malloc(maxlen * sizeof(char));
  int len = 0;
do {
  str[len] = c;
  ++len;
  if (len == maxlen) {
      maxlen *= 2;
      str = realloc(str, maxlen * sizeof(char));
    }
    if (scanf("%c", &c) != 1) break;
  } while (c != '\n');
  str[len] = '\0';
  str = realloc(str, (len + 1) * sizeof(char));
  return str;
}

static void insert(char **arr, char *str){
  int i = 0;
  while(i < len){
    if (strcmp(str, arr[i]) < 0){
      for(int j = len; j > i; j--){
        arr[j] = arr[j-1];
      }
      arr[i] = str;
      len++;
      break;
    }
    i++;
  }
  if(i == len){
    arr[i] = str;
    len++;
  }
}

int main() {
  char **arr = malloc(maxlen * sizeof(char *));
  arr[0] = 0;
  while(1){
    char *str = readstr();
    if (str == NULL) break;
    insert(arr, str);
    if (len == maxlen){
      maxlen *= 2;
      arr = realloc(arr, maxlen*sizeof(int));
    }
  }
  for(int i = 0; i < len; i++){
    printf("%s\n", arr[i]);
    free(arr[i]);
  }
  free(arr);
  return 0;
}
