#include <stdio.h>
#include <stdlib.h>

struct Arrays {
   int *A;
   int size;
};

void Set(struct Arrays *arr, int i, int j, int x){

  if(i >= j){
    arr->A[i * (i - 1) / 2 + j - 1] = x;
  } 
} 

void Display(struct Arrays arr){

  int i, j;

  for(i = 1; i <= arr.size;i++){
    for(j = 1; j <= arr.size;j++){
      if(i >= j){
        printf("%d ", arr.A[i * (i- 1) / 2 + j - 1]);
      } else {
        printf("0 ");
      }
    }
    printf("\n");
  }
}

int main(){

  int i, j, x;

  struct Arrays arr; 

  printf("Enter Dimension: ");
  scanf("%d", &arr.size);
  arr.A = (int *) malloc((arr.size * arr.size) * sizeof(int));

  printf("Size: %d\n", arr.size);

  printf("Print Lower Diagonal Matrix\n");
  for(i = 1; i<=arr.size;i++){
    for(j = 1; j<=arr.size;j++){
      scanf("%d", &x);
      Set(&arr, i, j, x);
    }
  }

  printf("\n\n");
  Display(arr);
  return 0;
}