#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {

  int data;

  struct Node *prev;
  struct Node *next;

} Node;

Node *head = NULL;
Node *last = NULL;

void printForward(){

  Node *current = head;

  while(current != NULL){

    printf("%d -> ", current->data);

    current = current->next;
  }

  printf("\n");
}

void printBackward(){

  Node *current = last;

  while(current != NULL){

    printf("%d -> ", current->data);

    current = current->prev;
  }

  printf("\n");
}

void insertFirst(int data){

  Node *link = (Node *) malloc(sizeof(Node));

  link->data = data;
  link->prev = link->next = NULL;

  if(head == NULL){
    last = link;
  } else {
    head->prev = link;
  }

  link->next = head;
  head = link;
}

void insertLast(int data){

  Node *link = (Node *) malloc(sizeof(Node));

  link->data = data;
  link->prev = link->prev = NULL;

  if(last == NULL){
    last = link;
    head = last;
  } else {
    last->next = link;
    link->prev = last;
  }

  last = link;
}

bool insertAfter(int key, int item){

  Node *current = head;

  while(current->data != key){

    if(current->next == NULL){
      return false;
    }

    current = current->next;
  }

  Node *newLink = (Node *) malloc(sizeof(Node));
  
  newLink->data = item;
  newLink->prev = newLink->next = NULL;

  if(current == last){
    newLink->next = NULL;
    last = newLink;
  } else {
    newLink->next = current->next;
    current->next->prev = newLink;
  }

  newLink->prev = current;
  current->next = newLink;
  
  return true;

}

Node *delete(int data){

  Node *current = head;

  while(current->data != data){

    if(current->next == NULL){
      return NULL;
    }
  }

  Node *dummyData = (Node *) malloc(sizeof(Node));

  if(current == head){

  } else {

  }

  return dummyData;
}

Node *deleteLast(){
  
  Node *lastNode = last;

  if(lastNode == NULL){
    return NULL;
  } else {
    last->prev->next = NULL; 
    last = last->prev;
  }

  return lastNode;

}


int main(){

  insertLast(39);

  insertFirst(11);
  insertFirst(54);
  insertFirst(67);

  insertAfter(54, 33);

  insertAfter(39, 45);

  deleteLast();

  printForward();

  printBackward();
}
