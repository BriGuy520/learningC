#include <stdio.h>


typedef struct Arrays {
  int A[20];
  int size;
  int length;
} arr_struct;


void findSum(arr_struct arr, int sum){

  int hash[10] = {0};
  int i;

  for(i = 0; i < arr.length;i++){
    if(hash[sum - arr.A[i]] != 0){
      printf("%d + %d = %d\n", arr.A[i], sum - arr.A[i] , sum);
    } else {
      hash[arr.A[i]]++;
    }
  }

  printf("\nHash Table: ");
  for(i = 0; i < 10; i++){
    printf("%d ", hash[i]);
  }
}

void findSum2(arr_struct arr, int sum){

  int i = 0;
  int j = arr.length - 1;

  printf("\nfind2 Sum:\n");
  while(i < j){

    if(arr.A[i] + arr.A[j] == sum){
      printf("%d + %d = %d\n", arr.A[i], arr.A[j], sum);
      i++;
      j--;
    } else if(arr.A[i] + arr.A[j] > sum){
      j--;
    } else {
      i++;
    }
  }   
}

int main(){

  int sum = 10;
  int sum2 = 11;

  arr_struct arr = {{2,8,3,7,1,9}, sizeof(int) * 8, 8};

  arr_struct arr2 = {{1,2,3,4,5,6,7,8,9,10}, sizeof(int) * 10, 10};

  findSum(arr, sum);
  findSum2(arr2,sum2);


}