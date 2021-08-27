#include <stdio.h>
#include <stdlib.h>

#define SIZE 11

void insert(int A[], int n){

  int temp = A[n];
  int i = n;

  while(i > 1 && temp > A[i / 2]){

    A[i] = A[i / 2];
    i = i / 2;

  }

  A[i] = temp;

}

int delete(int A[], int n){

  int top = A[1];
  A[1] = A[n];
  A[n] = top;
  int i = 1;
  int j = i * 2;

  while(j < n - 1){

    if(A[j + 1] > A[j]){
      j = j + 1;
    }

    if(A[i] < A[j]){
      int temp = A[i];
      A[i] = A[j];
      A[j] = temp;

      i = j;
      j = j * 2;
    } else {
      break;
    }
  }

  return top;

}

int main(){

  int heap[SIZE] = {0, 3, 54, 6, 21, 32, 42, 9, 10, 2, 56 };

  int i;

  for(i = 2; i < SIZE; i++){
    insert(heap, i);
  }

  printf("Before heap sort: ");

  for(i = 1; i < SIZE; i++){
    printf("%d ", heap[i]);
  }

  printf("\nAfter heap sort: ");

  for(i = SIZE - 1; i > 1; i--){
    delete(heap, i);
  }

  for(i = 1; i < SIZE; i++){
    printf("%d ", heap[i]);
  }

}