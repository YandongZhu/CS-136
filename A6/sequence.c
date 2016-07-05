#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include "sequence.h"

void Seq_init(struct Sequence *s){
  s->max_len = 100;
  s->length = 0;
}; 

int Sequence_length(const struct Sequence *seq){
  return seq->length;
};

void Sequence_clear(struct Sequence *seq){
  int max_len = seq->max_len;
  for(int i = 0; i < max_len; i++){
    seq->arr[i] = 0;
  }
  seq->length = 0;
};

int Sequence_item_at(const struct Sequence *seq, int pos){
  assert(pos>=0&&pos<seq->length);
  int n = seq->arr[pos];
  return n;
};

void Sequence_insert_at(struct Sequence *seq, int pos, int val){
  assert(pos>=0);
  assert(pos<=seq->length);
  if (seq->length==seq->max_len){
    printf("Sequence Filled: max length is %d items.\n", seq->max_len);
    return;
  }
  int next = seq -> arr[pos];
  for(int i = pos; i < seq->length; i++){
    int n = next;
    next = seq->arr[i+1];
    seq->arr[i+1] = n;
  }
  seq->arr[pos] = val;
  seq->length++;
};

int Sequence_remove_at(struct Sequence *seq, int pos){
  int n = seq->arr[pos];
  for(int i = pos; i < seq->length; i++){
    int next = seq->arr[i+1];
    seq->arr[i] = next;
  }
  seq->arr[seq->length-1] = 0;
  seq->length--;
  return n;
};

void Sequence_print(const struct Sequence *seq){
  int len = seq->length;
  if(len == 0){
    printf("[empty]\n");
    return;
  }
  printf("[%d] ", len);
  for(int i = 0; i < len - 1; i++){
    printf("%d ", seq->arr[i]);
  }
  printf("%d\n", seq->arr[len-1]);
};
