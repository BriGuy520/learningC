#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

#define EMPTY_QUEUE INT_MIN

typedef struct queue {
  int *values;
  int num_items;
  int head;
  int tail;
  int size;
} Q;

bool isEmpty(Q *queue){
  return queue->num_items == 0;
}

bool isFull(Q *queue){
  return queue->num_items == queue->size;
}

void queue_init(Q *queue, int size){
  queue->size = size;
  queue->values = malloc(sizeof(Q)); 
  queue->num_items = 0;
  queue->tail = 0;
  queue->head = 0;
}

bool enqueue(Q *queue, int value){

  if(isFull(queue)) return false;

  queue->values[queue->tail] = value;
  queue->num_items++;
  queue->tail = (queue->tail + 1) % queue->size;

  return true;
}


int dequeue(Q *queue){

  if(isEmpty(queue)) return EMPTY_QUEUE;

  int result = queue->values[queue->head];
  queue->num_items--;
  queue->head = (queue->head + 1) % queue->size;

  return result;
}

int peek(Q *queue){
  return queue->values[queue->tail];
}

int main(){

  Q q1;

  queue_init(&q1, 6);

  enqueue(&q1, 11);
  enqueue(&q1, 67);
  enqueue(&q1, 32);
  enqueue(&q1, 23);
  enqueue(&q1, 22);
  enqueue(&q1, 40);
  enqueue(&q1, 78);

  dequeue(&q1);

  int t;

  while((t = dequeue(&q1)) != EMPTY_QUEUE){
    printf("%d ", t);
  }

  printf("\n");

}


