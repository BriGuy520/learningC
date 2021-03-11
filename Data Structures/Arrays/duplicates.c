#include <stdio.h>
#include <stdlib.h>


typedef struct Arrays {
  int A[20];
  int size; 
  int length;
} arr_struct;


void findDuplicates(arr_struct arr){

  int hash[10] = {0};
  int i,j;

  // {9,1,2,3,4,1,8,7,6,2,9}

  for(i = 0; i < arr.length; i++){
    hash[arr.A[i]]++;
  }

  for(i = 0; i < 10; i++){
    if(hash[i] > 1){
      printf("%d ", i);
    }
  }


}


int main(){

  arr_struct arr = {{9,1,2,3,4,1,8,7,6,2,9},72,12};

  findDuplicates(arr);

}