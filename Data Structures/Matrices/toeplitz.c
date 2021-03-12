#include <stdio.h>
#include <stdlib.h>

struct Arrays {
  int *A;
  int n;
};

void Set(struct Arrays *arr, int i, int j, int x){

  if(i >= j){
    arr->A[i - j] = x;
  } else {
    arr->A[j - i + arr->n] = x;
  } 

}

void Display(struct Arrays arr){

  int i, j;

  for(i = 1; i <= arr.n;i++){
    for(j = 1; i <= arr.n; j++){
      if(i >= j){
        printf("%d ", arr.A[i - j]);
      } else {
        printf("%d ", arr.A[j - i + arr.n]);
      }
    }
    printf("\n");
  }
}

int main(){

  int i,j,x;
  struct Arrays arr;

  printf("Enter Dimension: ");
  scanf("%d", &arr.n);
  arr.A = (int *) malloc((arr.n + arr.n - 1) * sizeof(int));

  printf("Enter Elements in %d x %d toeplitz matrix:\n", arr.n, arr.n);
  for(i = 1; i <= arr.n;i++){
    for(j = 1; j <= arr.n;j++){
      scanf("%d", &x);
      Set(&arr, i, j, x);
    }
  }

  printf("\n\n");
  Display(arr);
}