/**
 *  Nathaniel Larsen - radix/bucket sort implementation - Sept. 2020
 *  Translation from Spring 2020 C++ project.
 */
#include <stdio.h>

#include "stack.h"
#define BASE 256  // number of possible values
#define BITS 8    // number of bits per "digit"
#define BYTES 4   // size of type being sorted

int getByte(int num, int digit) {
  return (num & (BASE - 1 << (BITS * (digit - 1)))) >> BITS * (digit - 1);
}

void radixBucketSort(int* nums, size_t len) {
  Stack working[BASE];  // make an array of BASE Stacks to serve as bins
  for (size_t dig = 1; dig < BYTES; ++dig) {
    for (size_t item = 0; item < len; ++item) {
      push_back(working[getByte(nums[item], dig)], nums[item]);
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
}