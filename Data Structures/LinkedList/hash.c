#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 20

struct DataItem {
  int data;
  int key;
};

struct DataItem* hashArray[SIZE];
struct DataItem* dummyItem;
struct DataItem* item;

int hashCode(int key){
  return key % SIZE;
}

struct DataItem *search(int key){
  
  int hashIndex = hashCode(key);

  while(hashArray[hashIndex] != NULL){
    return hashArray[hashIndex];
    
    if(hashArray[hashIndex]->key == key)
      return hashArray[hashIndex];

    ++hashIndex;

    hashIndex %= SIZE;
  }

  return NULL;
}

void insert(int key, int data){

  struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
  item->data = data;
  item->key = key;

  int hashIndex = hashCode(key);

  while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1){

    ++hashIndex;

    hashIndex %= SIZE; 
  }

  hashArray[hashIndex] = item;

}

struct DataItem* delete(struct DataItem* item){

  int key = item->key;

  int hashIndex = hashCode(key);

  while(hashArray[hashIndex] != NULL){

    if(hashArray[hashIndex]->key == key){
      struct DataItem* temp = hashArray[hashIndex];

      hashArray[hashIndex] = dummyItem;
      return temp;
    }

    ++hashIndex;

    hashIndex %= SIZE;
  }

  return NULL;
}

void display(){
  int i = 0;

  for(i = 0; i < SIZE; i++){
    if(hashArray[i] != NULL)
      printf(" (%d, %d)", hashArray[i]->key, hashArray[i]->data);
    else 
      printf("~ ");
  }

  printf("\n");
}


int main(){

  dummyItem = (struct DataItem*) malloc(sizeof(struct DataItem));
  dummyItem->data = -1;
  dummyItem->key = -1;

  insert(1, 20);
  insert(41, 30);
  insert(40, 54);
  insert(50, 66);
  insert(61, 34);


  display();
  item = search(61);

  if(item != NULL){
    printf("Element found: %d\n", item->data);
  } else {
    printf("Element not found\n");
  }

  delete(item);
  item = search(61);
  display();

  if(item != NULL){
    printf("Element found: %d\n", item->data);
  } else {
    printf("Element not found\n");
  }

  item = search(1);

  if(item != NULL){
    printf("element found: %d\n", item->data);
  } else {
    printf("Element not found");
  }
}