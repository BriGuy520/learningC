#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define QUEUE_EMPTY INT_MIN

typedef struct Q {
  int size;
  int num_items;
  int tail;
  int head;
  int *values;
} queue;

void init_queue(queue *q, int max_size){
  q->size = max_size;
  q->values = malloc(sizeof(int) * q->size); 
  q->num_items = 0;
  q->head = 0;
  q->tail = 0;
}

bool queue_full(queue *q){
  return q->size == q->num_items;
}

bool queue_empty(queue *q){
  return q->num_items == 0;
}

void queue_destroy(queue *q){
  free(q->values);
}

bool enqueue(queue *q, int item){

  if(queue_full(q)) return false;

  q->values[q->tail] = item;
  q->num_items++;
  q->tail = (q->tail + 1) % q->size; 

  return true;
}

int dequeue(queue *q){

  int result;

  if(queue_empty(q)) return QUEUE_EMPTY;

  result = q->values[q->head];
  q->head = (q->head + 1) % q->size;
  q->num_items--;

  return result;
}

int main(){

  queue q1;

  init_queue(&q1, 6);

  enqueue(&q1, 11);
  enqueue(&q1, 22);
  enqueue(&q1, 29);
  enqueue(&q1, 34);
  enqueue(&q1, 88);
  enqueue(&q1, 45);
  
  int t;

  while((t = dequeue(&q1)) != QUEUE_EMPTY){
    printf("t = %d\n", t);
  }

}