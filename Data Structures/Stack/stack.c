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

  create->top = 0;
  create->limit = cap;
  create->array = (int *) malloc(create->limit * sizeof(int));
  return create;
}


void displayStack(struct Stack *stack){

  int i;

  for(i = 0; i < stack->top; i++){
    printf("%d ", stack->array[i]);
  }
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

  printf("%d ", stack->top);
  stack->array[stack->top++] = x;
  printf("%d pushed to stack\n", x);
}

int main(){

  struct Stack *stack = createStack(100);

  struct Stack *stack2 = createStack(-100);

  push(stack, 10);

  push(stack, 29);
  push(stack, 45);
  push(stack, 54);

  displayStack(stack);

  printf("\n%d popped from stack\n", pop(stack));

  displayStack(stack);

  return 0;
}