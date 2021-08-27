#include <stdio.h>
#include <stdlib.h>

struct Set {
  int key;
  int data;
};

struct Set *arr;
int capacity = 10;
int size = 0;

int hashFunction(int key){
  return (key % capacity);
}

int checkPrime(int n){

  int i;
  
  if(n == 1 || n == 0){
    return 0;
  }

  for(i = 2; i < n / 2; i++){
    if(n % i == 0){
      return 0;
    }
  }

  return 1;
}

int getPrime(int n){

  if(n % 2 == 0){
    n++;
  }

  while(!checkPrime(n)){
    n += 2;
  }

  return n;
}

void init_array(){

  capacity = getPrime(capacity);

  arr = (struct Set *) malloc(capacity * sizeof(struct Set));

  for(int i = 0; i < capacity; i++){
    arr[i].key = 0;
    arr[i].data = 0;
  }
}

void insert(int key, int data){

  int index = hashFunction(key);

  if(arr[index].data == 0){
    arr[index].key = key;
    arr[index].data = data;
    size++;
    printf("\n Key (%d) has been inserted\n", key);
  } else if(arr[index].key == key){
    arr[index].data = data;
  } else {
    printf("\n Collison occured\n");
  }
}

void remove_element(int key){

  int index = hashFunction(key);
  
  if(arr[index].data == 0){
    printf("\n This key does not exist");
  } else {
    arr[index].key = 0;
    arr[index].data = 0;
    size--;
    printf("\n Key (%d) has been removed\n", key);
  }
}

void display(){

  int i;

  for(i = 0; i < capacity; i++){

    if(arr[i].data == 0){
      printf("\n array[%d]: / ", i);
    } else {
      printf("\nKey:%d array[%d]: %d\t", arr[i].key, i, arr[i].data);
    }
  }
}

int size_of_hashtable(){

  return size;
}

int main(){

  int choice, key, data, n;
  int c = 0;
  init_array();

  do
  {
    printf("1. Insert item in the Hash Table\n2.Remove item from the Hash Table\n3. Check the size of Hash Table\n4. Display a Hash Table\n");

    scanf("%d", &choice);

    switch(choice){

      case 1:
      
        printf("Enter key: ");
        scanf("%d", &key);
        printf("Enter data: ");
        scanf("%d", &data);
        insert(key, data);

        break;
      
      case 2:

        printf("Enter the key to delete: ");
        scanf("%d", &key);
        remove_element(key);

        break;

      case 3:
        size_of_hashtable();
        break;

      case 4:
        display();

        break;
      
      default: 

        printf("Invalid Input\n");
    }

    printf("\nDo you want to continue (press 1 for yes): ");
    scanf("%d", &c);
  } while(c == 1);
}