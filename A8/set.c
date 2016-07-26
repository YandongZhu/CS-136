#include "set.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct Set{
  int max_len;
  int len;
  int *data;
};

struct Set *set_create(void){
  struct Set *sample = malloc(sizeof(struct Set));
  sample->max_len = 32;
  sample->len = 0;
  sample->data = malloc(sample->max_len * sizeof(int));
  return sample;
}

void set_destroy(struct Set *s){
  free(s->data);
  free(s);
}

int set_size(const struct Set *s){
  return s->len;
}

void set_add(struct Set *s, int i){
  int j = 0;
  int k = 0;
  while (j < s->len){
    if(i == s->data[j]) break;
    if(i > s->data[j])
      k++;
    j++;
  }
  if(j != s->len)
    return;
  if (s->len == s->max_len) {
      s->max_len *= 2;
      s->data = realloc(s->data, s->max_len*sizeof(int));   }
  while (k < s->len){
    int temp = s->data[k];
    s->data[k] = i;
    i = temp;
    k++;
  }
  s->len++;
  s->data[k] = i;
}


void set_remove(struct Set *s, int i){
  int j = 0;
  while (j < s->len){
    if (s->data[j] == i) break;
    j++;
  }
  if(j == s->len)
    return;
  for (int k = j; k < s->len; k++){
    s->data[k] = s->data[k+1];
  }
  s->len--;
}

struct Set *set_union(const struct Set *s1, const struct Set *s2){
  struct Set *temp_set = malloc(sizeof(struct Set));
  temp_set->max_len = s1->max_len + s2->max_len;
  temp_set->len = 0;
  temp_set->data = malloc(temp_set->max_len * sizeof(int));
  int i = 0;
  int j = 0;
  while(i<s1->len && j<s2->len){
    if(s1->data[i] < s2->data[j]){
      temp_set->data[temp_set->len] = s1->data[i];
      i++;
      temp_set->len++;
    }
    if(s1->data[i] > s2->data[j]){
      temp_set->data[temp_set->len] = s2->data[j];
      j++;
      temp_set->len++;
    }
    if(s1->data[i] == s2->data[j]){
      temp_set->data[temp_set->len] = s2->data[j];
      j++;
      i++;
      temp_set->len++;
    }
  }
  if(i == s1->len){
    while(j<s2->len){
      temp_set->data[temp_set->len] = s2->data[j];
      j++;
      temp_set->len++;
    }
  }
  else{
    while(i<s1->len){
      temp_set->data[temp_set->len] = s1->data[i];
      i++;
      temp_set->len++;
    }
  }
  return temp_set;
}

struct Set *set_intersect(const struct Set *s1, const struct Set *s2){
  struct Set *temp_set = malloc(sizeof(struct Set));
  temp_set->max_len = s1->max_len + s2->max_len;
  temp_set->len = 0;
  temp_set->data = malloc(temp_set->max_len * sizeof(int));
  int i = 0;
  int j = 0;
  while(i<s1->len && j<s2->len){
    if(s1->data[i] < s2->data[j])
      i++;
    if(s1->data[i] > s2->data[j])
      j++;
    if(s1->data[i] == s2->data[j]){
      temp_set->data[temp_set->len] = s2->data[j];
      j++;
      i++;
      temp_set->len++;
    }
  }
  return temp_set;
}

void set_print(const struct Set *s){
  printf("[");
  int i = 0;
  while(i < s->len){
    if(i)
      printf(",");
    printf("%d", s->data[i]);
    i++;
  }
  printf("]\n");
}
