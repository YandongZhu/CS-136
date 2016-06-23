#include <stdbool.h>
#include <assert.h>
#include "sequence.h"


// a
  void Sequence_add_one(struct Sequence *seq) {
    int l = Sequence_length(seq);
    for (int i = 0; i < l; i++){
      int n = Sequence_item_at(seq, i);
      Sequence_remove_at(seq, i);
      n++;
      Sequence_insert_at(seq, i, n);
    }
}

// b
struct Sequence *Sequence_build(int n) {
  struct Sequence *s = Sequence_create();
  for(int i = 0; i < n; i++){
    Sequence_insert_at(s, i, i);
  }
  return s;
}

// c
void Sequence_map(int (*fp)(int), struct Sequence *seq) {
  int l = Sequence_length(seq);
  for(int i = 0; i < l; i++){
    int n = Sequence_item_at(seq, i);
    Sequence_remove_at(seq, i);
    n = fp(n);
    Sequence_insert_at(seq, i, n);
  }
}
 
// d
bool Sequence_equal(const struct Sequence *seq1, const struct Sequence *seq2) {
  int l1 = Sequence_length(seq1) - 1;
  int l2 = Sequence_length(seq2) - 1;
  if(l1 == l2){
    while(l1 >= 0&&l2 >= 0){
      int a1 = Sequence_item_at(seq1, l1);
      int a2 = Sequence_item_at(seq2, l2);
      if(a1 != a2) break;
      l1--;
      l2--;
    }
    return l1 == -1;
  }
  return false;
}

// e
void avg_and_variance(const struct Sequence *seq, 
                               int *avg, int *var) {
  int l = Sequence_length(seq);
  assert(l > 0);
  int sum = 0;
  int s = 0;
  for(int i = 0; i < l; i++){
    int a = Sequence_item_at(seq, i);
    sum += a;
  }
  *avg = sum / l;
  for(int j = 0; j < l; j++){
    int b = Sequence_item_at(seq, j) - *avg;
    s += (b * b);
  } 
  *var = s / l;
}

// f
void Sequence_filter(bool (*fp)(int), struct Sequence *seq) {
  int l = Sequence_length(seq);
  int i = 0;
  while(i < l){
    int n = Sequence_item_at(seq, i);
    Sequence_remove_at(seq, i);
    if(fp(n)){
      Sequence_insert_at(seq, i, n);
      i++;
    }
    else{
      l--;
    }
  }
}

// g
int Sequence_foldl(int (*fp)(int, int), int base, 
                   const struct Sequence *seq) {
  int l = Sequence_length(seq);
  for(int i = 0; i < l; i++){
    int n = Sequence_item_at(seq, i);
    base = fp(n, base);
  }
  return base;
}

// h
struct Sequence *Sequence_fib(int n) {
  int s0 = 0;
  int s1 = 1;
  struct Sequence *s = Sequence_create();
  if (n == 0){
    Sequence_insert_at(s, n, s0);
    return s;
  }
    Sequence_insert_at(s, 0, s0);
    Sequence_insert_at(s, 1, s1);
  if(n == 1){
    return s;
  }
  else{
    for (int i = 2; i < n; i++){
      int s2 = s0 + s1;
      s0 = s1;
      s1 = s2;
      Sequence_insert_at(s, i, s1);
    }
    return s;
  }
}

// i
void Sequence_reverse(struct Sequence *seq) {
  int l = Sequence_length(seq);
  while (l > 0){
    int first = Sequence_item_at(seq, 0);
    Sequence_insert_at(seq, l, first);
    Sequence_remove_at(seq, 0);
    l--;
  }
}
