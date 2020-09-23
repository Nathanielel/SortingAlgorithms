#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#define StackT long int

typedef struct StackObj* Stack;
// Constructor / Destructor
Stack newStack();
void freeStack(Stack* pS);

// Accessor Functions
size_t length(Stack S);
StackT at(Stack S, size_t n); 

// Mutator Functions
void push_back(Stack S, StackT n);
StackT pop_back(Stack S);
void clear(Stack S);

#endif