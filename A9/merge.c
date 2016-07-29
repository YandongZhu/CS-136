#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// return the length of the list;
static int length(struct llist *lst) {
    int length = 0;
    struct llnode *node = lst->front;
    while (node) {
++length;
      node = node->next;
    }
    return length;
  }

void merge(struct llist *dest, struct llist *src1, struct llist *src2){
  assert(dest != NULL);
  assert(src1 != NULL);
  assert(src2 != NULL);
  struct llnode *temp1 = src1->front;
  struct llnode *temp2 = src2->front;
  if (temp1->item < temp2->item){
    dest->front = temp1;
    temp1 = temp1->next;
  }
  else{
    dest->front = temp2;
    temp2 = temp2->next;
  }
  struct llnode *c_temp = dest->front;
  while (temp1 != NULL || temp2 != NULL){
    if (temp2 == NULL||(temp1 != NULL && temp1->item < temp2->item)){
      c_temp->next = temp1;
      temp1 = temp1->next;
      c_temp = c_temp->next;
    }
    else{
      c_temp->next = temp2;
      temp2 = temp2->next;
      c_temp = c_temp->next;
    }
  }
}

void merge_sort(struct llist *lst){
  int len = length(lst);
  if(len <= 1) return;
  int llen = len / 2;
  
  struct llist *left = malloc(sizeof(struct llist));
  struct llist *right = malloc(sizeof(struct llist));
  
  struct llnode *pre = lst->front;
  struct llnode *after = pre->next;
  left->front = pre;
  
  for (int i = 0; i < llen - 1; i++){
    pre = pre->next;
    after = after->next;
  }
  
  pre->next = NULL;
  right->front = after;
  
  merge_sort(left);
  merge_sort(right);
  
  merge(lst, left, right);
  
  free(left);
  free(right);
}
