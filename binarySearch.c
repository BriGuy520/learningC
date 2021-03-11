#include <stdio.h>


int binarySearch(int arr[], int size, int idx, int answer){

  int mid = (size - idx) / 2;
  printf("This is the value of mid: %d\n", mid);

  
  if(arr[mid] == answer)
    return mid;

  if(arr[mid] > answer)
    return binarySearch(arr, size, mid, answer);  
  return binarySearch(arr, size + mid, 0, answer);
  
}


int main(){

  int x, find;

  x = 0;
  find = 11;

  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  int arrSize = sizeof(arr) / sizeof(arr[0]) - 1;
  printf("%d\n", arrSize);
  int result = binarySearch(arr, arrSize, x, find);

  printf("The answer is at index %d of the array.", result);

  return 0;
}