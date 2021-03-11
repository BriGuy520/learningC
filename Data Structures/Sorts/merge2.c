#include <stdio.h>

void merge(int arr[], int l, int mid, int r){


  int i, j, k;
  int m = mid - 1 + 1; 
  int n = r - mid;

  int A[20], B[20];

  for(i = 0; i < m; i++)
    A[i] = arr[l + i];
  
  for(j = 0; j < n; j++)
    B[j] = arr[mid + 1 + j];
  
  i = 0;
  j = 0;
  k = l;

  while(i < m && j <n){
    if(A[i] <= B[j]){
      arr[k] = A[i];
      i++;
    } else {
      j++;
    }
    k++;
  }

  while(i < m){
    arr[k] = A[i];
    i++;
    k++;
  }

  while(j < m){
    arr[k] = B[j];
    j++;
    k++;
  }
}

void merge_sort(int arr[], int l, int r){

  if(l < r){

    int mid = l + (r - 1) / 2;

    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);
    merge(arr, l, mid, r);
  }
}

int main(){

  int arr[] = { 3, 8, 12, 9, 5, 26 };
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Array:\n");
  for(int i = 0; i < n; i++)
    printf("%d ", arr[i]);

  merge_sort(arr, 0, n - 1);

  printf("\nAfter performing the merge sort:\n");
  for(int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  
  return 0;
}