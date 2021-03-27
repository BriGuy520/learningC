#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *head = NULL;

void Insert(int data){

  struct Node *link = (struct Node *) malloc(sizeof(struct Node));

  link->data = data;
  link->next = head;

  head = link;

}

void Delete(int x){
  
  struct Node *current = head;
  struct Node *previous = (struct Node *) malloc(sizeof(struct Node));

  while(current->data != x){
    if(current->next != NULL){
      previous = current;
      current = current->next;
    } else {
      return NULL;
    }
  }

  previous->next = current; 
}

void Print(){
  
  struct Node *link = head;

  while(link != NULL){
    printf("%d -> ", link->data);
    link = link->next;
  }
  printf("\n");
}

int main(){


  Insert(11);
  Insert(13);
  Insert(14);

  Print();

  Insert(15);
  Insert(19);

  Print();
  
  
}