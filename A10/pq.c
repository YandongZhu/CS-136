#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
  
struct node
{
  int val;
  int prior;
};
  
struct pq {
  int len;
  int max_len;
  struct node **arr;
};


PQ pq_create(void) {
  struct pq *new = malloc(sizeof(struct pq));
  new->len = 0;
  new->max_len = 32;
  new->arr = malloc(new->max_len * sizeof(struct node*));
  return new;
}

void pq_destroy(PQ pqueue) {
    int i = 0;
    while (i < pqueue->len){
      free(pqueue->arr[i]);
      i++;
    }
    free(pqueue->arr);
    free(pqueue);
}

void pq_switch(PQ pqueue, int parent, int children){
      struct node *temp = pqueue->arr[parent];
      (pqueue->arr)[parent] = pqueue->arr[children];
      (pqueue->arr)[children] = temp;
}

void pq_add(PQ pqueue, int item, int priority) {
    assert(pqueue);
    assert(priority > 0);
    struct node *new = malloc(sizeof(struct node));
    new->val = item;
    new->prior = priority;
    pqueue->arr[pqueue->len] = new;
    int parent = (pqueue->len-1)/2;
    int children = pqueue->len;
    while (children){
      if ((pqueue->arr)[parent]->prior <= (pqueue->arr)[children]->prior)
        break;
      pq_switch(pqueue, parent, children);
      children = parent;
      parent = (parent-1)/2;
    }
    pqueue->len++;
    if (pqueue->len == pqueue->max_len){
      pqueue->max_len *= 2;
      pqueue->arr = realloc(pqueue->arr, pqueue->max_len * sizeof(struct node*));
    }
}

static int min_of_three(int a, int b, int c){
  if (a<=b)
  {
    if (a<=c)
      return 1;
    else 
      return 3;
  }
  else {
    if (b<=c)
      return 2;
    else 
      return 3;
  }
}

static void pq_arrange(PQ pqueue){
    int parent = 0;
    while(parent*2+1 < pqueue->len){
      if (parent*2+2 >= pqueue->len)
      {
        if((pqueue->arr)[parent]->prior > (pqueue->arr)[parent*2+1]->prior)
          pq_switch(pqueue, parent, parent*2+1);
        return;
      }
      int check = min_of_three((pqueue->arr)[parent]->prior, (pqueue->arr)[parent*2+1]->prior, (pqueue->arr)[parent*2+2]->prior);
      if (check == 1) return;
      if (check == 2) {
        pq_switch(pqueue, parent, parent*2+1);
        parent = parent*2+1;
      }
      if (check == 3) {
        pq_switch(pqueue, parent, parent*2+2);
        parent = parent*2+2;
      }
    }
}

int pq_remove(PQ pqueue) {
    assert(pqueue);
    pqueue->len--;
    pq_switch(pqueue, 0, pqueue->len);
    struct node *temp = (pqueue->arr)[pqueue->len];
    int a = temp->val;
    free(temp);
    pqueue->arr[pqueue->len] = NULL;
    pq_arrange(pqueue);
    return a;
}


bool pq_is_empty(const PQ pqueue) {
   assert(pqueue);
   return pqueue->len == 0;
}



void pq_print(const PQ pqueue) {
  assert(pqueue);
  int i = 0;
  printf("[");
  while (i < pqueue->len){
    if(i)
      printf(",");
    printf("(%d,%d)", (pqueue->arr)[i]->val, (pqueue->arr)[i]->prior);
    i++;
  }
  printf("]\n");
}


int pq_length(const PQ pqueue) {
   assert(pqueue);
   return pqueue->len;
}



int pq_front_priority(const PQ pqueue) {
   assert(pqueue);
   assert(pqueue->len);
   return (pqueue->arr)[0]->prior;
}


int pq_front_item(const PQ pqueue) {
   assert(pqueue);
   assert(pqueue->len);
   return (pqueue->arr)[0]->val;
}
