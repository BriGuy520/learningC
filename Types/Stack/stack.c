#include <stdio.h>

int MAXSIZE = 8;
int stack[8];
int top = -1;

int isempty(){
  if(top == -1)
    return 1;
  return 0;
}

int isfull(){

  if(top == MAXSIZE)
    return 1;
  return 0;
}

int peek(){
  return stack[top];
}

int pop(){

  int data;

  if(!isempty()){
    data = stack[top];
    top = top - 1;
    return data;
  } else {
    printf("Could not retrieve data, Stack is empty.\n");
    return 0;
  }
}

void printArr(int arr[], int size){
  int i;

  for(i = 0; i <= size; i++){
    printf("%d ", arr[i]);
  }

  printf("\n");
}

void push(int data){

  if(!isfull()){
    top = top + 1;
    stack[top] = data;
  } else {
    printf("Could not insert data, Stack is full.\n");
  }
}

int main(){

    printf("Stack empty: %s\n", isempty() ? "true" : "false");


  // push items on to the stack
  push(3);
  push(5);
  push(6);
  push(7);
  push(8);
  push(1);
  push(11);
  push(10);
  push(20);
  pop();
  pop();

  int size = sizeof(stack) / sizeof(stack[0]);

  printArr(stack, size);

  printf("Stack full: %s\n", isfull()? "true" : "false");
  printf("Stack empty: %s\n", isempty() ? "true" : "false");

  printf("Element at top of the stack: %d\n", peek());
  printf("Elements: \n");

  //print stack data
  while(!isempty()){
    int data = pop();
    printf("%d\n", data);
  }

  printf("Stack full: %s\n", isfull()? "true" : "false");
  printf("Stack empty: %s\n", isempty() ? "true" : "false");

  return 0;
}