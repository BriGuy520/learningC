#include<stdio.h>


typedef struct Array {
  int A[20];
  int size; 
  int length;
} arr_struct;


void minMax(arr_struct arr){

  int min = arr.A[0];
  int max = arr.A[0];

  for(int i = 0; i < arr.length;i++){
    if(arr.A[i] > max){
      max = arr.A[i];
    }

    if(arr.A[i] < min){
      min = arr.A[i];
    }
  }

    printf("Min: %d\n", min);
    printf("Max: %d", max);
  
}

int main(){


  arr_struct arr = {{5,6,2,3,5,7,8,3,5,10,19,12}, sizeof(int) * 12, 12};

  minMax(arr);

}