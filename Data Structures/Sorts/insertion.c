#include <stdio.h>


#define MAX 8

int arr[MAX] = {3, 4, 2, 1, 7, 3, 10, 11 };


void printLine(int count){

  for(int i = 0; i < count; i++){
    printf("=");
  }

  printf("\n");
}


void display(){

  for(int i = 0; i < MAX; i++){
    printf("%d ", arr[i]);
  }

  printf("\n");
}

void insertionSort(){

  int holePosition, i, valueToInsert;

  for(i = 1; i < MAX; i++){

    valueToInsert = arr[i];

    holePosition = i;

    while(holePosition > 0 && arr[holePosition - 1] > valueToInsert){

      arr[holePosition] = arr[holePosition - 1];
      holePosition--;

    } 

    if(holePosition != i){
      arr[holePosition] = valueToInsert;
    }
  }
}


int main(){

  printLine(50);

  printf("Array before sort: ");
  display();
  insertionSort();
  printf("Array after sort: ");
  display();
  printLine(50);


}