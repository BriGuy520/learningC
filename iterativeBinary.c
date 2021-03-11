#include <stdio.h>

int binarySearch(int arr[], int l, int size, int x){

 while(l <= size){
   int middle = l + (size - l) / 2;

   if(arr[middle] == x)
    return middle;

  if(arr[middle] < x)
    l = middle + 1;
  
  else 
    size = middle - 1;
 }

return -1;

}

int main(){

  int arr[] = { 2, 3, 5, 6, 7, 9, 11 };
  int n = sizeof(arr) / sizeof(arr[0]);
  int x = 11;
  int result = binarySearch(arr, 0, n - 1, x);
  (result == -1) ? printf("Element is not present in array") : printf("Element is present at index %d", result);

  return 0;

}