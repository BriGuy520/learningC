#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 6

int intArray[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;

int peek(){
  return intArray[front];
}

bool isEmpty(){
  return itemCount == 0;
}

bool isFull(){
  return itemCount == MAX;
}

int size(){
  return itemCount;
}

void insert(int data){
  
  if(!isFull()){

    if(rear == MAX - 1){
      rear = -1;
    }

    intArray[++rear] = data;
    itemCount++;
  }
}

int removeData(){
  int data = intArray[front++];

  if(front == MAX){
    front = 0;
  }

  itemCount--;
  return data;
}

int main(){
  /* insert 5 items */

  insert(5);
  insert(3);
  insert(9);
  insert(1);
  insert(12);

  printf("front: %d, rear: %d, First Element in Queue: %d, last element in queue: %d \n", front, rear, intArray[0], intArray[MAX - 2]);

  removeData();

  printf("front: %d, rear: %d, First Element in Queue: %d, last element in queue: %d ", front, rear, intArray[0], intArray[MAX - 2]);
}



