#include <stdbool.h>
#include <assert.h>

// check the given number word can be compose by given
// s0 or s1 or not
// requires: s0 > 0, s1 > 0
bool fib_word(int s0, int s1, int word){
  assert(s0 > 0);
  assert(s1 > 0);
  while(s1 < word){
    int d = 1; /* the cloest 2's exponential number greater than s1 */ 
    int s2 = 1; // the next fib_word
    do{
      d = d * 2;
    }while (d <= s0);
    s2 = s0 + s1 * d;
    s0 = s1;
    s1 = s2;
  }
  return s1 == word;
}
