#include <stdio.h>
#include <stdlib.h>

int main(){
  int *p; // This is setting a pointer
  p = (int *) malloc(5 * sizeof(int));


  printf("%d\n", *p);
  printf("%d", p);
}