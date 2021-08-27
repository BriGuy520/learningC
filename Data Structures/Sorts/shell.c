#include <stdio.h>
#include <stdbool.h>

#define MAX 7

int intArray[MAX] = {4, 6, 3, 2, 1, 9 , 7};

void printLine(int count){

  for(int i = 0; i < count; i++){
    printf("=");
  }

  printf("\n");
}


void display(){

  printf("[ ");

  for(int i = 0; i < MAX; i++){
    printf("%d ", intArray[i]);
  }

  printf("]\n");
}


void shellSort(){
  int inner, outer;
  int valueToInsert;
  int interval = 1;
  int elements = MAX;
  int i = 0;

  while(interval <= elements/3){
    interval = interval * 3 + 1;
  }

  while(interval > 0){
    printf("iteration %d#", i);

    display();

    for(outer = interval; outer < elements; outer++){
      valueToInsert = intArray[outer];
      inner = outer;

      // intArray = {4, 6, 3, 2, 1, 9, 7};
      //             0  1  2  3  4  5  6

      while(inner > interval - 1 && intArray[inner - interval] >= valueToInsert){
        intArray[inner] = intArray[inner - interval];
        inner -= interval;
        printf("item moved: %d\n", intArray[inner]);
      }

      intArray[inner] = valueToInsert;
      printf("item inserted %d at position %d\n", valueToInsert, inner);
    }

    interval = (interval - 1) / 3;
    i++;
  }
}

int main(){
  printf("Input Array: ");
  display();
  printLine(50);
  shellSort();
  printf("Output Array: ");
  display();
  printLine(50);
  return 1;
}

