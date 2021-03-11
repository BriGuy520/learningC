#include <stdio.h>


int Sum(int* arr){

  int i, sum = 0;

  for(i = 0; i < 5; i++){
    sum += arr[i];
  }

  return sum;
}


int main(){

  int A[] = {1,2,3,4,5};
  int total = Sum(A);
  printf("Sum of array is %d\n", total);

}