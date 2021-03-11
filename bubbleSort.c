#include <stdio.h>

void swap(int *xp, int *yp){
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void printArray(int arr[], int size){

  int i;

  for(i = 0; i < size; i++)
    printf("%d ", arr[i]);
    printf("\n");
}

void bubbleSort(int arr[], int n){
  int i, j;

  for(i = 0; i < n - 1; i++)
    for(j = 0; j < n - i - 1; j++)
      if(arr[j] > arr[j + 1])
        swap(&arr[j], &arr[j + 1]);
}


int main(){

  int arr[] = { 2, 5, 10, 40, 11, 12, 29, 48, 46, 252, 263, 11, 24, 19, 23, 45 };
  int n = sizeof(arr) / sizeof(arr[0]);
  bubbleSort(arr, n);
  printf("Sorted array: \n");
  printArray(arr, n);
  return 0;

  
}