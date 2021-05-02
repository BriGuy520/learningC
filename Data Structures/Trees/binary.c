#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *leftChild;
  struct node *rightChild;
};

struct node *root = NULL;

void insert(int data){

  struct node *tempData = (struct node *) malloc(sizeof(struct node));
  struct node *current;
  struct node *parent;

  tempData->data = data;
  tempData->leftChild = NULL;
  tempData->rightChild = NULL;

  if(root == NULL){
    root = tempData;
  } else {

    current = root;
    parent = NULL;

    while(1){

      parent = current;

      if(data < parent->data){
        current = current->leftChild;

        if(current == NULL){
          parent->leftChild = tempData;
          return;
        }
      } else {

        current = current->rightChild;

        if(current == NULL){
          parent->rightChild = tempData;
          return;
        }
      }
    }
  }
}

struct node *search(int data){

  struct node *current = root;
  printf("Traversing through the tree: ");

  while(current->data != data){
    if(current != NULL){
      printf("%d ", current->data);
    }

    if(current->data > data){
      current = current->leftChild;
    } else {
      current = current->rightChild;
    }

    if(current == NULL){
      return NULL;
    }

  }

  return current;

}

int main(){

  int i;
  int arr[8] = {11, 43, 22, 78, 3, 29, 93, 65 };

  for(i = 0; i < 8; i++){
    insert(arr[i]);
  }
  

}
