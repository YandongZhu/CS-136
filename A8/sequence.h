#include "stack.h"
#include <stdbool.h>

struct squeue {
  struct stack *main;
  struct stack *help;
  int front;
};

// squeue_create(void) creates a struct squeue and returns a pointer to it.
// Time: O(1).
struct squeue *squeue_create(void); 

//squeue_is_empty returns true is no element exists in queue. False otherwise.
// Time: O(1).
bool squeue_is_empty(const struct squeue *q) ;

//squeue_add adds an item to the queue. This item will be the last of all items added so far
// to be removed.
// Time: O(1).
void squeue_add(int item, struct squeue *q); 

// squeue_front returns the front item on the queue (the one that was first to be added, 
// and not yet removed), but does not remove it from the queue.
// Time: O(1).
int squeue_front(const struct squeue *q) ;
 
// squeue_remove_front removes the front item from the queue.
//Time: O(n), with n being the number of items in the queue.
int squeue_remove_front(struct squeue *q) ;

// squeue_destroy frees the all data allocated for the queue.
// Time: O(1)
void squeue_destroy(struct squeue *q) ;
 
