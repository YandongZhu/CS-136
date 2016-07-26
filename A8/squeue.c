#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "squeue.h"

struct squeue *squeue_create(void){
  struct squeue *ini = malloc(sizeof(struct squeue));
  ini->main = create_stack();
  ini->help = create_stack();
  return ini;
} 

bool squeue_is_empty(const struct squeue *q){
  int main_check = stack_is_empty(q->main);
  int help_check = stack_is_empty(q->help);
  return main_check&&help_check;
}

void squeue_add(int item, struct squeue *q){
  if(stack_is_empty(q->main)){
    q->front = item;
    stack_push(item, q->main);
  }
  else
    stack_push(item, q->main);
}

int squeue_front(const struct squeue *q){
  return q->front;
}

int squeue_remove_front(struct squeue *q){
  int i = q->front;
  while(stack_is_empty(q->main) == 0){
    stack_push(stack_pop(q->main), q->help);
  }
  stack_pop(q->help);
  if(stack_is_empty(q->help))
    q->front = 0;
  else
    q->front = stack_top(q->help);
  while(stack_is_empty(q->help) == 0){
    stack_push(stack_pop(q->help), q->main);
  }
  return i;
}
