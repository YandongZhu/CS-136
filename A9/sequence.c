#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Sequence 
{
	struct node *seq;
};

struct node
{
  int item;
  struct node *next;
};

struct Sequence *Sequence_create(void){
	struct Sequence *s = malloc(sizeof(struct Sequence));
	s->seq = NULL;
	return s;
}

void Sequence_destroy(struct Sequence *seq){
	struct node *c_Seq = seq->seq;
	while (c_Seq){
		struct node *n_Seq = c_Seq->next;
		free(c_Seq);
		c_Seq = n_Seq;
	}
  free(seq);
}

int Sequence_length(const struct Sequence *seq){
	int len = 0;
	struct node *temp = seq->seq;
	while (temp){
		++len;
		temp = temp->next;
	}
	return len;
}

int Sequence_item_at(const struct Sequence *seq, int pos){
	assert(pos >= 0&&pos < Sequence_length(seq));
	struct node *temp = seq->seq;
	while (pos > 0){
		temp = temp->next;
		pos--;
	}
	return temp->item;
}

void Sequence_insert_at(struct Sequence *seq, int pos, int val){
	assert(pos >= 0&&pos <= Sequence_length(seq));
  struct node *new = malloc(sizeof(struct node));
  new->item = val;
	struct node *pre = seq->seq;
  if(pos == 0){
    new->next = pre;
    seq->seq = new;
    return;
  }
  struct node *after = seq->seq->next;
  while (pos > 1){
    pre = pre->next;
    after = after->next;
    pos--;
  }
  pre->next = new;
  new->next = after;
}

int Sequence_remove_at(struct Sequence *seq, int pos){
  assert(pos >= 0&&pos < Sequence_length(seq));
  int a = 0;
  if (pos == 0){
    a = seq->seq->item;
    struct node *first = seq->seq->next;
    free(seq->seq);
    seq->seq = first;
    return a;
  }
  struct node *pre = seq->seq;
  struct node *cur = seq->seq->next;
  while (pos > 1){
    pos--;
    pre = pre->next;
    cur = cur->next;
  }
  a = cur->item;
  struct node *after = cur->next;
  free(cur);
  pre->next = after;
  return a;
}

void Sequence_print(const struct Sequence *seq){
	int len = Sequence_length(seq);
	if(len == 0){
		printf("[empty]\n");
		return;
	}
	printf("[%d]", len);
	struct node *temp = seq->seq;
	while(temp){
		printf(" %d", temp->item);
		temp = temp->next;
	}
  printf("\n");
}
