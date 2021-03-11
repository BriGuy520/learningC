#include <stdio.h>
#include <stdlib.h>

int main(){
  
  int *p, *q;

  int i, j, k;

  p = (int *) malloc(5 * sizeof(int));
  p[0] = 3; p[1] = 5; p[2] = 7; p[3] = 9; p[4] = 11;

  for(i = 0; i < 5; i++)
    printf("%d ", p[i]);

  printf("\n");

  q = (int *) malloc(10 * sizeof(int));

  for(j = 0; j < 5; j++){
    q[j] = p[j];
  }

  free(p);
  
  p = q;
  q = NULL;


  for(k = 0; k < 10; k++)
    printf("%d ", q[k]);

  printf("\n");

  return 0;
}