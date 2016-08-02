#include <stdio.h>

struct node{
  int item;
  struct node *next;
};

struct mmstack {
  struct node *front;
  int len;
  int *min;
  int min_len;
  int min_len_max;
  int *max;
  int max_len;
  int max_len_max;
};

MMStack create_MMStack(void){
  struct mmstack *s = malloc(sizeof(struct mmstack));
  s->len = 0;
  s->min_len = 0;
  s->max_len = 0;
  s->max_len_max = 16;
  s->min_len_max = 16;
  s->front = NULL;
  s->min = malloc(s->min_len_max * sizeof(int));
  s->max = malloc(s->max_len_max * sizeof(int));
  return s;
}


void destroy_MMStack(MMStack mms){
  struct node *temp = mms->front;
  while (temp){
    struct node *after = temp->next;
    free(temp);
    temp = after;
  }
  free(mms->min);
  free(mms->max);
  free(mms);
}


int mms_length(MMStack mms) {
  assert(mms);
  return mms->len;
}


void mms_push(MMStack mms, int i){
  assert(mms);
  struct node *new = malloc(sizeof(struct node));
  new->item = i;
  new->next = mms->front;
  mms->front = new;
  mms->len++;
  if (mms->min_len == 0&&mms->max_len == 0){
    mms->min[mms->min_len] = i;
    mms->max[mms->max_len] = i;
    mms->min_len++;
    mms->max_len++;
    return;
  }
  if (i >= mms->max[mms->max_len - 1])
  {
    mms->max[mms->max_len] = i;
    mms->max_len++;
  }
  if (i <= mms->min[mms->min_len - 1])
  {
    mms->min[mms->min_len] = i;
    mms->min_len++;
  }
  if (mms->min_len == mms->min_len_max) {
      mms->min_len_max *= 2;
      mms->min = realloc(mms->min, mms->min_len_max * sizeof(int));
    }
  if (mms->max_len == mms->max_len_max) {
      mms->max_len_max *= 2;
      mms->max = realloc(mms->max, mms->max_len_max * sizeof(int));
    }
}


int mms_pop(MMStack mms) {
   assert(mms);
   assert(mms->front);
   struct node *pop = mms->front;
   int a = pop->item;
   mms->front = pop->next;
   free(pop);
   mms->len--;
   if (a == mms->min[mms->min_len-1])
   {
    mms->min_len--;
    mms->min[mms->min_len] = 0;
   }
   if (a == mms->max[mms->max_len-1])
   {
     mms->max_len--;
     mms->max[mms->max_len] = 0;
   }
   return a;
}


int mms_min(MMStack mms) {
   assert(mms);
   assert(mms->front);
   return mms->min[mms->min_len-1];
}


int mms_max(MMStack mms) {
   assert(mms);
   assert(mms->front);
   return mms->max[mms->max_len-1];
}
