#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack {
  int top;
  unsigned limit;
  int *array;
};

struct Stack *createStack(unsigned cap){
  struct Stack *create = (struct Stack *) malloc(sizeof(struct Stack));

  create->top = -1;
  create->limit = cap;
  create->array = (int *) malloc(cap * sizeof(int));
  return create;
}

int main(){

  struct Stack *stack = createStack(100);

}