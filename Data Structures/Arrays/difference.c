#include <stdio.h>
#include <stdlib.h>


typedef struct Array { 
  int A[10];
  int size;
  int length;
} arr_struct;



arr_struct* difference(int low, arr_struct arr){

  arr_struct *tmpArr = (arr_struct *) malloc(sizeof(arr_struct));

  int gap = low;
  int i, k;

  // {5, 6, 8, 9, 10, 11, 14, 15}

  for(i = 0; i < arr.length; i++){ 
    if(arr.A[i] - i != gap){
      tmpArr->A[k++] = gap + i;
      gap++;
      i--;
    }
  }

  tmpArr->size = k * 4;
  tmpArr->length = k;

  return tmpArr;

}

void difference2(arr_struct arr){

  int diff = arr.A[0];
  int i;

  printf("\nThe missing elements in the array: ");

  for(i = 0; i < arr.length; i++){
    if(arr.A[i] - i != diff){
      while(diff < arr.A[i] - i){
        printf("%d ", diff + i);
        diff++;
      }
    }
  }

}

void hashDiff(arr_struct arr){
  
  int hash[16] = {0};
  int i;

  for(i = 0; i < arr.length; i++){
    hash[arr.A[i]]++;
  }

  printf("\nMissing elements found with hash table: ");

  for(i = arr.A[0]; i < 16;i++){
    if(hash[i] == 0){
      printf("%d ", i);
    } 
  }

}

void Display(arr_struct arr){

  int i; 

  printf("\nElements in the array: ");
  for(i = 0; i < arr.length; i++){
    printf("%d ", arr.A[i]);
  }
}

int main(){


  arr_struct arr = {{5, 6, 8, 9, 10, 11, 14, 15}, 32, 8 };

  arr_struct *arr2;

  arr2 = difference(arr.A[0], arr);

  Display(*arr2);

  difference2(arr);

  hashDiff(arr);


}