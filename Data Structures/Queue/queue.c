#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct Queue {
  int front, rear, size;
  unsigned capacity;
  int* array;
};

// function to create a queue
// of given capacity.
// It initializes size of queue as 0;
struct Queue *createQueue(unsigned capacity){

  struct Queue *q = (struct Queue*) malloc(sizeof(struct Queue));
  q->front = q->size = 0;
  q->capacity = capacity;

  // This is important, see the enqueue
  q->rear = capacity - 1;
  q->array = (int *) malloc(q->capacity * sizeof(int)); 

  return q;
}

int isEmpty(struct Queue *q){
  return q->size == 0;
}

int isFull(struct Queue *q){
  return (q->size == q->capacity);
}

void enqueue(struct Queue *q, int item){
  if(isFull(q))
    return;
  
  q->rear = (q->rear + 1) % q->capacity;
  q->array[q->rear] = item;
  q->size = q->size + 1;
}

int front(struct Queue *q){

  return q->array[q->front]; 
}

int rear(struct Queue *q){
  return q->array[q->rear];
}

int dequeue(struct Queue *q){

  int i;

  if(isEmpty(q))
    return INT_MIN;

  int item = q->array[q->front];
  q->front = (q->front + 1) % q->capacity;
  q->size = q->size - 1;
  
  return item;
}

void display(struct Queue *q){

  int i; 

  printf("\n");

  for(i = q->front; i <= q->rear; i++){
    printf("%d ", q->array[i]);
  }

}

int main(){
  
  struct Queue *q1 = createQueue(6);

  enqueue(q1, 10);
  enqueue(q1, 54);

  if(isEmpty(q1) == 1){
    printf("Queue is empty\n");
  } else {
    printf("Queue is not empty");
  }

  enqueue(q1, 100);
  enqueue(q1, 30);
  enqueue(q1, 15);
  enqueue(q1, 12);

  display(q1);

  dequeue(q1);
  dequeue(q1);
  dequeue(q1);

  // enqueue(q1, 78);

  if(isFull(q1) ==  1){
    printf("\nQueue is full");
  } else {
    printf("\nQueue is not full");
  }

  display(q1);

  printf("\nfront of the queue is %d and %d is the rear of the queue\n", front(q1), rear(q1));

}