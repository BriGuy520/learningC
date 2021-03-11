#include <stdio.h>
#include <stdlib.h>


struct Array {
  int *A;
  int size;
};


void Set(struct Array *arr, int i, int j, int x){
  
  if(i == j){
    arr->A[arr->size - 1 + i] = x;
  } else if(i - j == 1){
    arr->A[2 * arr->size - 1 + i] = x;
  } else if(i - j == -1){
    arr->A[i - 1] = x;
  }
}

void Display(struct Array arr){

  int i, j;

  for(i = 1; i <= arr.size; i++){
    for(j = 1; j <= arr.size;j++){
      if(i == j){
        printf("%d ", arr.A[arr.size - 1 + i]);
      } else if(i - j == 1) {
        printf("%d ", arr.A[2 * arr.size - 1 + i]);
      } else if (i - j == -1){
        printf("%d", arr.A[i - 1]);
      }
    }
    printf("\n");
  }

}

int main(){

  struct Array arr;
  int i, j, x;

  printf("Enter Dimension: ");
  scanf("%d", &arr.size);
  arr.A = (int *) malloc(3 * arr.size - 2 * sizeof(int));

  printf("Enter Integers in %d x %d TriDiagonal Matrix:\n", arr.size, arr.size);
  for(i = 1; i  <= arr.size;i++){
    for(j = 1; j <= arr.size;j++){
      scanf("%d", &x);
      Set(&arr, i, j, x);
      printf("i: %d, j: %d \n", i, j);
    }
  }

  printf("\n\nthis is called");
  Display(arr);
}