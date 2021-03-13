#include <stdio.h>
#include <stdlib.h>

int main(){

  int i, j, size; 

  int k = 0;

  int sparse[4][5] = {{0, 0, 3, 0, 0}, {0, 0, 0, 0, 2}, {0, 4, 0, 0, 0}, {0, 0, 0, 0, 0}};

  for(i = 0; i < 4; i++){
    for(j = 0; j < 5; j++){
      if(sparse[i][j] != 0){
        size++;
      }
    }
  }

  int matrixValues[3][size];

  for(i = 0; i < 4; i++){
    for(j = 0; j < 5; j++){

      if(sparse[i][j] != 0){
        matrixValues[0][k] = i;
        matrixValues[1][k] = j;
        matrixValues[2][k] = sparse[i][j];
        k++;
      }
    }
  }

  for(i = 0; i < 3; i++){
    for(j = 0; j < size; j++){
      printf("%d ", matrixValues[i][j]);
    }
    printf("\n");
  }

}