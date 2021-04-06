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


int isFull(struct Stack *stack){

  return stack->top == stack->limit - 1;
}

int isEmpty(struct Stack *stack){

  return stack->top == -1;
}

int pop(struct Stack *stack){

  return stack->array[--stack->top];
}

void push(struct Stack *stack, int x){

  if(isFull(stack))
    return;
  stack->array[++stack->top] = x;
  printf("%d pushed to stack\n", x);
}

int main(){

  struct Stack *stack = createStack(100);

  push(stack, 29);
  push(stack, 45);
  push(stack, 54);

  printf("%d popped form stack\n", pop(stack));

  return 0;

}