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

struct Node *Delete(int x){
  
  struct Node *current = head;
  struct Node *previous = NULL;

  while(current->data != x){
    if(current->next != NULL){
      previous = current;
      current = current->next;
    } else {
      return NULL;
    }
  }

  if(current == head){
    head = head->next;
  } else {
    previous->next = current->next; 
  }

  return current;
}

int Length(){

  struct Node *list;
  int count = 0;

  if(head == NULL){
    return count;
  }

  for(list = head; list != NULL; list = list->next){
    count++;
  }

  return count;
}

void Sort(){

  int i, j, k, tempData;
  struct Node *list;
  struct Node *next;
  int size = Length();
  k = size;

  for(i= 0; i < size - 1;i++, k--){
    list = head;
    next = head->next;
    
    for(j = 1; j < k; j++){
      if(list->data > next->data){
        tempData = list->data;
        list->data = next->data;
        next->data = tempData;
      } 
        list = list->next;
        next = next->next;
    }
  }


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

  Sort();

  Print();

  Delete(15);
  Delete(13);

  Print();


  return 0;
  
}