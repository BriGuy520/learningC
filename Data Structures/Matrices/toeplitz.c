#include <stdio.h>
#include <stdlib.h>

struct Arrays {
  int *A;
  int n;
};

void Set(struct Arrays *arr, int i, int j, int x){

  if(j >= i && i == 1){
    arr->A[j - i] = x;
  } else if (j < i && j == 1){
    arr->A[i - j + arr->n - 1] = x;
  } 

}

void Display(struct Arrays arr){

  int i, j;

  for(i = 1; i <= arr.n;i++){
    for(j = 1; j <= arr.n; j++){
      if(j >= i){
        printf("%d ", arr.A[j - i]);
      } else {
        printf("%d ", arr.A[i - j + arr.n - 1]);
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