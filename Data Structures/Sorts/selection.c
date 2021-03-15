#include <stdio.h>
#include <stdlib.h>


int main(){

  int i, j, temp; 
  int arr[] = {5, 3, 2, 9, 1};
  int size = sizeof(arr) / sizeof(arr[0]);
  int current = 0;
  int minIdx;
 
  for(i = 0; i < size - 1; i++){
    minIdx = i;
    for(j = i + 1; j < size; j++){
      if(arr[j] < arr[minIdx]){
        minIdx = j;
      }
    }
    temp = arr[i];
    arr[minIdx] = arr[i];
    arr[i] = temp;   
  }

  for(i = 0; i < size; i++){
    printf("%d ", arr[i]);
  }
}