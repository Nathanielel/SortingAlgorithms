//#include "binsort.c"
#include "stack.h"
#include <stdio.h>

int main()
{
  Stack s = newStack();
  for (int i = 21; i > 0; --i)
  {
    push_back(s, i);
  }
  for (int i = 0; i < length(s); ++i)
    printf("%d ", at(s, i));
  printf("\n");
  
  //clear(s);
  for (int i = 0; i < length(s); ++i) printf("%d ", at(s, i));
  printf("\n");

  freeStack(&s);
  return 0;
}