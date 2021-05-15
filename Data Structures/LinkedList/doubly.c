#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
  int data;

  struct Node *prev;
  struct Node *next;
};

struct Node *head = NULL;
struct Node *last = NULL;

bool isEmpty(){
  return head == NULL;
}

void printForward(){

  struct Node *current = head;

  while(current != NULL){
    printf("%d ", current->data);
    current = current->next;
  }

  printf("\n");

}

void printBackward(){

  struct Node *current = last;

  while(current != NULL){
    printf("%d ", current->data);
    current = current->prev;
  }

  printf("\n");

}


void insertFirst(int data){

  struct Node *link = (struct Node *) malloc(sizeof(struct Node));

  link->data = data;
  link->prev = NULL;
  link->next = NULL;

  if(isEmpty()){
    last = link;
  } else {
    head->prev = link;
  }

  link->next = head;
  head = link;
}

void insertLast(int data){

  struct Node *link = (struct Node *) malloc(sizeof(struct Node));

  link->data = data;
  link->prev = NULL;
  link->next = NULL;

  if(isEmpty()){
    last = link;
  } else {
    last->next = link;
  } 

  link->prev = last;
  last = link;

}

void deleteLast(){

  if(isEmpty()){
    printf("No nodes to delete\n");
  } else {
    last->prev->next = NULL;
  }
}

void deleteFirst(){

  if(isEmpty()){
    printf("No nodes to delete.\n");
  } else {
    head = head->next;
    head->prev = NULL;
  }
}

int main(){


  insertFirst(11);
  insertFirst(23);
  insertFirst(54);

  printForward();

  printBackward();

  insertLast(87);
  insertLast(11);
  insertLast(82);

  printForward();

  printBackward();

  deleteLast();

  printForward();

  deleteFirst();

  printForward();
}