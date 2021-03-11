#include <stdio.h>
#include <stdlib.h>


int main(){

  // Static 

  // the size of the array is decided at compile time

  int A[5] = { 2, 4, 6, 8, 10 };
  // this gets memory allocated in the stack
  int *p;
  int i;

  for(i = 0; i < sizeof(A) / sizeof(A[0]); i++){
    printf("This is the value at index %d: %d\n", i, A[i]);
  }

  p = (int *) malloc(5 * sizeof(int));
  p[0] = 11;
  p[1] = 12;
  p[2] = 13;

  printf("\n");

  for(i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    printf("This is the value at index %d: %d\n", i, p[i]);

  printf("This the value of p: %d", p);



  // Dynamic
  // In C++ we can make array run at run time. 

  int B[] = {};


  return 0;
}