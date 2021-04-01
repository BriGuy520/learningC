#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *head = NULL;
struct Node *current = NULL;

int Length(){

  int count = 0;
  
  for(current = head; current != NULL; current = current->next){
    count++;
  }

  return count;
}

void *Insert(int x){

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

void Sort(){

  int i, j, k, tempData;
  int size = Length();
  k = size;

  struct Node *current = head;
  struct Node *next = head->next;

  for(i = 0; i < size - 1; i++){

      for(j = 0; j < k; j++){
        if(current->data > next->data){

        }
      
      }
  }



}



void Print(){

  struct Node *current = head;

  while(current != NULL){
    printf("%d -> ", current->data);
    current = current->next;
  }
}

int main(){

  Insert(11);
  Insert(12);
  Insert(13);

  printf("Length of list is %d\n", Length());

  Insert(45);
  Insert(23);
  Insert(19);

  Delete(23);

  Print();
} 