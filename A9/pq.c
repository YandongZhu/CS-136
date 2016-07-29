#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>

struct node{
  int priority;
  int item;
  struct node *next;
};

struct pq{
  struct node *seq;
  int len;
};

struct pq *pq_create(void){
  struct pq *q = malloc(sizeof(struct pq));
  q->seq = NULL;
  q->len = 0;
  return q;
}

void pq_destroy(struct pq *pqueue){
  struct node *temp = pqueue->seq;
  while(temp){
    struct node *cur = temp->next;
    free(temp);
    temp = cur;
  }
  free(pqueue);
}

void pq_add(struct pq *pqueue, int item, int priority){
  struct node *new = malloc(sizeof(struct node));
  new->item = item;
  new->priority = priority;
  pqueue->len++;
  if(pqueue->seq == NULL||priority < pqueue->seq->priority){
    new->next = pqueue->seq;
    pqueue->seq = new;
    return;
  }
  struct node *pre = pqueue->seq;
  struct node *after = pqueue->seq->next;
  while (after != NULL&&priority >= after->priority){
    pre = pre->next;
    after = after->next;
  }
  pre->next = new;
  new->next = after;
}

int pq_remove(struct pq *pqueue){
  int a = pqueue->seq->item;
  struct node *after = pqueue->seq->next;
  free(pqueue->seq);
  pqueue->len--;
  pqueue->seq = after;
  return a;
}

bool pq_is_empty(const struct pq *pqueue){
  return pqueue->seq == NULL;
}

int pq_length(const struct pq *pqueue){
  return pqueue->len;
}

void pq_print(const struct pq *pqueue){
  assert(pqueue->seq != NULL);
  int c_p = pqueue->seq->priority;
  struct node *temp = pqueue->seq;
  printf("[%d]", c_p);
  while (temp){
    if (temp->priority != c_p){
      c_p = temp->priority;
      printf("\n");
      printf("[%d]", c_p);  
    }
    printf(" %d", temp->item);
    temp = temp->next;
  }
  printf("\n");
}

int pq_front_priority(const struct pq *pqueue){
  assert(pqueue->seq != NULL);
  return pqueue->seq->priority;
}

int pq_front_item(const struct pq *pqueue){
  assert(pqueue->seq != NULL);
  return pqueue->seq->item;
}
