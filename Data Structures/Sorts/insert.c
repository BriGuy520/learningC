#include <stdio.h>

#define SIZE 10

int sort[SIZE] = {4, 3, 1, 4, 2, 5, 8, 7, 4, 11};


void printLine(int count){

  for(int i = 0; i < count; i++){
    printf("=");
  }

  printf("\n");
}


void display(){

  for(int i = 0; i < SIZE; i++){
    printf("%d ", sort[i]);
  }

  printf("\n");
}

void insertionSort(){


  for(int i = 1; i < SIZE; i++){

    int valueToInsert = sort[i];
    int holePosition = i;

    while(i > 0 && sort[holePosition - 1] > valueToInsert){

      sort[holePosition] = sort[holePosition - 1];
      holePosition--;

    }

    if(i != holePosition){
      sort[holePosition] = valueToInsert;
    }

  }

}

int main(){


  printLine(50);
  printf("Array before insertion sort: ");
  display();
  insertionSort();
  printf("Array after insertion sort: ");
  display();
  printLine(50);

}