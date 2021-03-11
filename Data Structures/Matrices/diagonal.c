#include <stdio.h>

struct Matrix {
  int A[10];
  int n;
};


void Set(struct Matrix *mtrx, int i, int j, int x){

    if(i == j){
      mtrx->A[i - 1] = x;
    }
}

void Get(struct Matrix mtrx, int i, int j){

  if(i == j){
      printf("Value at Matrix[%d][%d] is %d\n", i, j, mtrx.A[i]);
  }
}


void Display(struct Matrix mtrx){

  int i, j;

  for(i = 0; i < mtrx.n;i++){
    for(j = 0; j < mtrx.n;j++){
      if(i == j){
        printf("%d ", mtrx.A[i]);
      } else {
        printf("0 ");
      }
    }
    printf("\n");
  }

}


int main(){

  struct Matrix m;
  m.n = 4;

  Set(&m, 1, 1, 10);Set(&m, 2, 2, 11);Set(&m, 3,3,12);Set(&m,4,4,13);

  Get(m, 2, 2);

  Display(m);


}