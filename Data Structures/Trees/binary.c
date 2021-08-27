#include <stdio.h>
#include <stdlib.h>

typedef struct DataItem {
  int data;

  struct DataItem *leftChild;
  struct DataItem *rightChild;
  
} DataItem;

DataItem *root = NULL;

void insert(int data){

  DataItem *tempData = (DataItem *) malloc(sizeof(DataItem));
  DataItem *current;
  DataItem *parent;

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

      if(parent->data < data){
        current = current->rightChild;

        if(current == NULL){
          parent->rightChild = tempData;
          break;
        }
      } else {

        current = current->leftChild;

        if(current == NULL){
          parent->leftChild = tempData;
          break;
        }
      }
    }
  }
}


DataItem *search(int data){

  DataItem *current = root;

  printf("Traversing through the Tree: ");

  while(current->data != data){

    printf("%d ", current->data);

    if(current->data < data){
      current = current->rightChild;
    } else {
      current = current->leftChild;
    }

    if(current == NULL){
      return NULL;
    }
  }

  return current;
}


int main(){


  insert(11);
  insert(12);
  insert(44);
  insert(30);
  insert(36);
  insert(87);
  insert(34);

  DataItem *find = search(36);

  if(find != NULL){
    printf("\n%d was found.\n", find->data);
  } else {
    printf("\nItem was not found");
  }

}