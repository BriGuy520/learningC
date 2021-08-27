#ifndef Queue_h
#define Queue_h

typedef struct Node {
  struct Node *leftChild;
  struct Node *rightChild;
  int data;
} Node;

typedef struct Queue {
  int rear;
  int front;
  Node **values;
  int size;
} Q;

int isEmpty(Q q){
  return q.front == q.rear;
} 

Q *create(Q *q, int size){

  q->size = size;
  q->rear = q->front = 0;
  q->values = (Node **) malloc(sizeof(Node *) * q->size);
  
}

void enqueue(Q *q, Node * data){

  if((q->rear + 1) % q->size == q->front){
    printf("Queue is full");
  } else {
    q->values[q->rear] = data;
    q->rear = (q->rear + 1) % q->size;
  }
}

Node *dequeue(Q *q){

  Node *x = NULL; 

  if(q->rear == q->front){
    printf("Queue is empty");
  } else {
    x = q->values[q->front];
    q->front = (q->front + 1) % q->size;
    return x;
  }
}

#endif