#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#define DEFAULT_SIZE 16

typedef struct StackObj {
  StackT* data;
  size_t size;
  size_t max;
} StackObj;

Stack newStack() {
  Stack new = malloc(sizeof(StackObj));
  new->data = calloc(DEFAULT_SIZE, sizeof(StackT));
  new->size = 0;
  new->max = DEFAULT_SIZE;
  return new;
}

void freeStack(Stack* pS) {
  if (pS == NULL || *pS == NULL) return;
  free((*pS)->data);
  free(*pS);
  *pS = NULL;
}

size_t length(Stack S) { return S->size; }

// danger, needs bounds check
StackT at(Stack S, size_t n) { return S->data[n]; }

void push_back(Stack S, StackT n) {
  if (S->size == S->max) {
    S->data = realloc(S->data, S->size << 1);
    S->max = S->max << 1;
  }
  S->data[S->size] = n;
  ++S->size;
}

StackT pop_back(Stack S){
  StackT result = S->data[S->size-1];
  --S->size;
  return result;
}

void clear(Stack S){ S->size = 0; }
