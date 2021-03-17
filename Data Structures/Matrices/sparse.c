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

void Add(struct Sparse *s1, struct Sparse *s2){

  int i = 0, j = 0, k = 0;

  if(s1->column != s2->column && s1->row != s2->row)
    return 0;

  struct Sparse s3;
  s3.size = s1->size + s2->size;

  s3.column = s1->column;
  s3.row = s1->row;
  s3.E = (struct Element *) malloc(s3.size * sizeof(struct Element)); 

  while(i < s1->size && j < s2->size){

    if(s1->E[i].i < s2->E[j].i){
      s3.E[k++] = s1->E[i++];
    } else if(s1->E[i].i > s2->E[j].i){
      s3.E[k++] = s2->E[j++];
    } else {
      if(s1->E[i].j < s2->E[j].j){
        s3.E[k++] = s1->E[i++];
      } else if(s1->E[i].j > s1->E[j].j){
        s3.E[k++] = s2->E[j++];
      } else {
        s3.E[k++].x = s1->E[i++].x + s2->E[j++].x;
      }
    }
  } 
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
  struct Sparse s2;

  Create(&s);
  Create(&s2);
  Display(s);

  Add(&s, &s2);

}