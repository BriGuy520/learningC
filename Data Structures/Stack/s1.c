#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 5

int stack[SIZE];
int tail = 0; 

bool isEmpty(){
  return tail == 0;
}

bool isFull(){
  return tail == SIZE;
}

int push(int value){

  if(!isFull()) {
    stack[tail++] = value;
  } else {
    printf("Stack is full.\n");
  }
  
  return value;
}

int pop(){

  int value = stack[tail--];

  return value;
  
}


int main(){

  push(11);
  push(64);
  push(56);
  push(23);
  push(87);
  push(92);

  pop();

  for(int i = 0; i < 6; i++){
    printf("%d ", stack[i]);
  }

  printf("\n");

}