#include <stdio.h>
#include <stdlib.h>


struct Element {
  int i;
  int j;
  int x;
};

struct Sparse {
  struct Element *e;
  int size;
  int row;
  int column; 
};

void Create(struct Sparse *s){

  int i;

  printf("Enter Dimensions: ");
  scanf("%d %d", &s->row, &s->column);

  printf("Enter Number of Elements: ");
  scanf("%d", &s->size);
  s->e = (struct Element *) malloc(s->size * sizeof(struct Element));
  printf("Size of e: %d\n", s->size * sizeof(struct Element));

  for(i = 0; i < s->size;i++){
    printf("Add Row Column Value:\n");
    scanf("%d %d %d", &s->e[i].i, &s->e[i].j, &s->e[i].x);
  }
}

void Display(struct Sparse arr){

  int i, j, k = 0;

  for(i = 0; i < arr.column; i++){
    for(j = 0; j < arr.row; j++){
      if(i == arr.e[k].i && j == arr.e[k].j){
        printf("%d ", arr.e[k++].x);
      } else {
        printf("0 ");
      }
    }
    printf("\n");
  }
}


int main(){

  struct Sparse s; 
  int i, j;

  Create(&s);
  printf("\n\n");
  Display(s);


}