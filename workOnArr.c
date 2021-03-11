#include <stdio.h>

int main(){

  int SIZE = 5;
  double balance[5] = { 1000.764736, 2.0, 3.4, 7.0, 50.8 };

  for(int i = 0; i < SIZE; i++){
    printf("The array %f\n", balance[i]);
  }
}