#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int intArray[SIZE] = {5, 3, 6, 29, 92, 18, 73, 42, 1, 2};


void printLine(int count){

  for(int i = 0; i < count; i++){
    printf("=");
  }

  printf("\n");
}


void display(){

  for(int i = 0; i < SIZE; i++){
    printf("%d ", intArray[i]);
  }

  printf("\n");
}

void selectionSort(){

  int i, j, minIdx;

  for(i = 0; i < SIZE; i++){

    minIdx = i;

    for(j = i + 1; j < SIZE; j++){
      if(intArray[j] < intArray[minIdx]){
        minIdx = j;
      }
    }

    if(minIdx != i){
      int temp = intArray[i];
      intArray[i] = intArray[minIdx];
      intArray[minIdx] = temp;
    }
  }
}

int main(){

  printLine(50);
  printf("Array before selection sort: ");
  display();
  printf("Array after selection sort: ");
  selectionSort();
  display();
  printLine(50);
}