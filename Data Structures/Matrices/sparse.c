#include <stdio.h>
#include <stdlib.h>

struct Element {
  int i;
  int j;
  int x;
};

struct Sparse {
  struct Element *E;
  int row;
  int column;
  int size;
};

void Create(struct Sparse *arr){  

  int i;

  printf("Enter column and row length: ");
  scanf("%d %d", &arr->column, &arr->row);
  printf("\nEnter number of values in matrix: ");
  scanf("%d", &arr->size);

  arr->E = (struct Element *) malloc(arr->size * sizeof(struct Element));

  for(i = 0; i < arr->size; i++){
    
    printf("Enter row index, column index, value\n");
    scanf("%d %d %d", &arr->E[i].i, &arr->E[i].j, &arr->E[i].x);
  }

  printf("\n\n");
} 

void Display(struct Sparse arr){
  int i, j, k = 0;

  for(i = 0; i < arr.row; i++){
    for(j = 0; j < arr.column; j++){
      if(arr.E[k].i == i && arr.E[k].j == j){
        printf("%d ", arr.E[k++].x); 
      } else {
        printf("0 ");
      }
    }
    printf("\n");
  }
}


int main(){

  struct Sparse s;

  Create(&s);
  Display(s);

}