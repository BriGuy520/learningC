#include <stdio.h>
#include <stdbool.h>

void insert(int x){

  int i;

}

bool isSorted(int arr[], int size){

  int i; 

  for(i = 0; i < size; i++){
    if(arr[i] > arr[i + 1]){
      return false;
    } 
  }

  return true;
}

int main(){

  int arr[] = { 1, 2, 4, 5, 6, 3, 7, 8, 0 };
  int size = sizeof(arr) / sizeof(arr[0]);

  bool result = isSorted(arr, size);

  printf("This is filler.");
}