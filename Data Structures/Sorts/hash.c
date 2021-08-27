#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

void display(){

  int i; 

  for(i = 0; i < SIZE; i++){

    if(hashArray[i] != NULL){
      printf("(%d, %d) ", hashArray[i]->key, hashArray[i]->data);
    } else {
      printf(" - ");
    }

  }

  printf("\n");


}

struct DataItem *delete(int key){

  int hashIndex = hashCode(key);


  while(hashArray[hashIndex] != NULL){
    
    if(hashArray[hashIndex]->key == key){
      struct DataItem *temp;

      hashArray[hashIndex] = dummyItem;
      return temp;

      ++hashIndex;

      hashIndex %= SIZE;
    }

  }

  return NULL;

}

void insert(int key, int data){

  struct DataItem *item = (struct DataItem *) malloc(sizeof(struct DataItem));
  item->key = key;
  item->data = data;

  int hashIndex = hashCode(key);

  while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1){

    ++hashIndex;

    hashIndex %= SIZE;
  }

  hashArray[hashIndex] = item;
}

int main(){

  dummyItem = (struct DataItem *) malloc(sizeof(struct DataItem));
  dummyItem->key = -1;
  dummyItem->data = -1;

  insert(1, 20);
  insert(2, 70);
  insert(17, 18);
  insert(49, 20);
  insert(14, 32);
  insert(9, 22);

  delete(17);

  display();

}