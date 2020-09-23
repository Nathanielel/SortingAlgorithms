/**
 *  Nathaniel Larsen - radix/bucket sort implementation - Sept. 2020
 *  Translation from Spring 2020 C++ project. sorts long ints in O(4n) time
 */
#include <stdio.h>

#include "stack.h"
#define StackT long int
#define BASE 65536  // number of possible values
#define BITS 16    // number of bits per "digit"
#define BYTES 4   // size of type being sorted

void radixBucketSort(StackT* nums, size_t len) {
  Stack working[BASE];  // make an array of BASE Stacks to serve as bins
  for (size_t i = 0; i < BASE; ++i){
    working[i] = newStack();
  }
  for (size_t dig = 0; dig < BYTES; ++dig) {
    for (size_t item = 0; item < len; ++item) {
      push_back(working[(nums[item] >> (BITS * dig) & (BASE-1))], nums[item]);
    }
    // clear nums
    for (size_t i = 0; i < len; ++i) nums[i] = 0;
    int cursor = 0;
    // refill nums, bin by bin
    for (size_t i = 0; i < BASE; ++i) {
      for (size_t j = 0, end = length(working[i]); j != end; ++j) {
        nums[cursor] = at(working[i], j);
        ++cursor;
      }
      clear(working[i]);
    }
  }
  for (size_t i = 0; i < BASE; ++i){
    freeStack(&working[i]);
  }
}
int main(){
  StackT nums[] = {10576795109086L, 9518605L, 67995186055109L, 9813745L, 18699813745837L,
      3141658105987016098L};
  radixBucketSort(nums, 6);
  for (int i = 0; i < 6; ++i)
    printf("%ld ", nums[i]);
  printf("\n");

  return 0;
}