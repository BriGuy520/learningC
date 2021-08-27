#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 5
#define EMPTY_STACK (-1)

int stack[SIZE];
int top = EMPTY_STACK;

bool isEmpty(){
  return top == EMPTY_STACK;
}

bool isFull(){
  return top + 1 >= SIZE;
}

bool push(int value){

  if(isFull()) return false;

  stack[++top] = value;

  return true;

}

int pop(){

  if(isEmpty()) return EMPTY_STACK;

  int value = stack[top--];

  return value;
}


int main(){

  push(30);
  push(45);
  push(76);
  push(21);
  push(54);
  push(44);

  pop();
  pop();

  for(int i = 0; i <= top; i++)
    printf("%d ", stack[i]);

}