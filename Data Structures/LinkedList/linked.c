#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *head = NULL;
struct Node *current = NULL;


bool isEmpty(){
  return head == NULL;
}

int Length(){

  int count = 0;
  
  for(current = head; current != NULL; current = current->next){
    count++;
  }

  return count;
}

void Insert(int x){

  struct Node *link = (struct Node *) malloc(sizeof(struct Node));

  link->data = x;
  link->next = head;

  head = link;

}

struct Node *Delete(int x){

  struct Node *current = head;
  struct Node *previous;


  while(current->data != x){
    if(current->next == NULL){
      return NULL;
    } else {
      previous = current;
      current = current->next;
    }
  }

  previous->next = current->next;

  return previous;

}

int Sum(){

  struct Node *list = head;
  int sum = 0;

  while(list != NULL){
    sum += list->data;
    list = list->next;
  }

  return sum;
}

int Max(){

  struct Node *list = head;
  int max = 0;

  while(list != NULL){
    if(list->data > max){
      max = list->data;
    }

    list = list->next;
  }

  return max;
}

void Sort(){

  int i, j, k, tempData;
  int size = Length();
  k = size;
  
  struct Node *current;
  struct Node *next;

  for(i = 0; i < size; i++, k--){

    current = head;
    next = head->next;

    for(j = 1; j < k; j++){
      if(current->data > next->data){
        tempData = current->data;
        current->data = next->data;
        next->data = tempData;
      }

      current = current->next;
      next = next->next;
    }
  }
}

void Print(){

  struct Node *current = head;

  if(current == NULL){
    printf("list is empty"); 
  }

  while(current != NULL){
    printf("%d -> ", current->data);
    current = current->next;
  }

  printf("\n");
}

int main(){

  if(isEmpty() == 0){
    printf("The list is not empty\n");
  } else {
    printf("The list is empty\n");
  }

  Insert(11);
  Insert(12);
  Insert(13);

  printf("Length of list is %d\n", Length());

  Insert(45);

  Print();

  printf("Sorted linked list: ");
  Sort();

  Print();

  if(isEmpty() == 0){
    printf("The list is not empty\n");
  } else {
    printf("The list is empty\n");
  }

  printf("Sum of list is %d\n", Sum());

  printf("Max value in list is %d\n", Max());

} 