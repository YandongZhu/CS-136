#include <stdio.h>
#include <stdlib.h>

void to_array(struct pq *pqueue, int **arr_ptr, int *len){
  *len = pq_length(pqueue);
  *arr_ptr = malloc((*len)*sizeof(int));
  int i = 0;
  while(i < *len){
    (*arr_ptr)[i] = pq_remove(pqueue);
    i++;
  }
  free(pqueue);
}

struct pq **k_way_split(struct pq *pqueue, const int k){
  struct pq **pq_arr = malloc(k * sizeof(struct pq*));
  for (int i = 0; i < k; i++){
    struct pq *new_pq = pq_create();
    pq_arr[i] = new_pq;
  }
  int len = pq_length(pqueue);
  int j = 0;
  while (j < len){
    int p = pq_front_priority(pqueue);
    int v = pq_remove(pqueue);
    pq_add(pq_arr[j % k], v, p);
    ++j;
  }
  free(pqueue);
  return pq_arr;
}
