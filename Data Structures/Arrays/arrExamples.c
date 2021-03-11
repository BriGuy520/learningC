#include <stdio.h>


int main()
{

  int A[5];
  int B[5] = { 1, 2, 3, 4, 5};
  int C[10] = {11, 12, 13};
  int D[] = { 20, 21, 22, 23, 24, 25}; 

  int i;
  int cSize = sizeof(C) / sizeof(C[0]);
  for(i = 0; i < cSize; i++){
    printf("%d\n", &C[i]);
  }
}