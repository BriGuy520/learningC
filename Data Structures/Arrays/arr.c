#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Array {
  int A[20];
  int size;
  int length;
};

typedef struct Array arr_short;

void Display(arr_short arr){
  int i;

  printf("Elements in array: ");
  for(i = 0; i < arr.length; i++)
    printf("%d ", arr.A[i]);
  printf("\n");
}

void Insert(int index, int value, arr_short *arr){

  int i;

  if(index < arr->length && index >= 0)
    arr->length++;
    for(i = arr->length; i > index; i--)
      arr->A[i] = arr->A[i - 1];
    arr->A[index] = value;

}

void Append(arr_short *arr, int x){

  if(arr->length < arr->size)
    arr->A[arr->length] = x;
    arr->length++;

}

void Remove(arr_short *arr, int index){

  int i;

  if(index < arr->length)
    for(i = index; i < arr->length; i++)
      arr->A[i] = arr->A[i + 1];
     arr->length--;

}

int LinearSearch(arr_short arr, int value){

  int i;

  for(i = 0; i < arr.length; i++)
    if(arr.A[i] == value)
      return printf("The value %d is at index %d\n", value, i);

  return printf("The value %d is not in the array\n", value);
}

void swap(int *x, int *y){
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;  
}

void sorted(arr_short *arr){

  int i, j;

  for(i = 0; i < arr->length; i++)
    for(j = 0; j < arr->length - i; j++)
      if(arr->A[j] > arr->A[j + 1] && j + 1 < arr->length)
        swap(&arr->A[j], &arr->A[j + 1]);

}

int isSorted(arr_short arr){

  int i;

  for(i = 0; i < arr.length; i++){
      if(arr.A[i] > arr.A[i + 1])
        return 0;
  }

  return 1;
}

int BinarySearch(arr_short arr, int low, int high, int x){

  int mid = (high + low) / 2; 

  if(arr.A[mid] == x)
    return printf("The value %d is at index %d\n", x, mid);
    

  if(arr.A[mid] > x) 
    return BinarySearch(arr, 0, mid, x);
  return BinarySearch(arr, mid, arr.length - 1, x);
}

int Sum(arr_short arr){

  int i;
  int total = 0;

  for(i = 0; i < arr.length; i++)
    total = total + arr.A[i];

  return total;
}

double Avg(arr_short arr){
  return Sum(arr) / arr.length;
}

int Max(arr_short arr){

  int high, i;

  for(i = 0; i < arr.length; i++)
    if(arr.A[i] > high)
      high = arr.A[i];

  return high;
}

void ReverseArr(arr_short *arr){
  int B[arr->length];
  int i, j, k;

  for(i = arr->length - 1, j = 0; i >= 0 && j < arr->length; i--, j++)
    B[j] = arr->A[i];

  for(k = 0; k < arr->length; k++)
    arr->A[k] = B[k];
}

void InsertSort(arr_short *arr, int x){

  int i = arr->length - 1;

  if(arr->length == arr->size)
    return;

  while(i >= 0 && arr->A[i] > x){
    arr->A[i + 1] = arr->A[i];
    i--; 
  }
  arr->A[i + 1] = x;
}

void Rearrange(arr_short *arr){
  int i, j;
  i = 0;
  j = arr->length - 1;

  while(i < j){
    while(arr->A[i] <= 0) i++;
    while(arr->A[j] >= 0) j--;
    if(i < j) swap(&arr->A[i], &arr->A[j]);

  }
}


arr_short* Union(arr_short *arr, arr_short *arr2){

  arr_short *arr6 = (arr_short *) malloc(sizeof(arr_short));

  int i, j, k;
  i = j = k = 0; 


  while(i < arr->length && j < arr2->length){
    if(arr->A[i] < arr2->A[j]){
      arr6->A[k++] = arr->A[i++]; 
    } else if(arr->A[i] > arr2->A[j]) {
      arr6->A[k++] = arr2->A[j++];
    } else {
      arr6->A[k++] = arr->A[i++];
      j++;
    }
  }

  for(; i < arr->length; i++){
    arr6->A[k++] = arr->A[i++];
  }

  for(; j < arr2->length; j++){
    arr6->A[k++] = arr2->A[j++];
  }

  arr6->length = k;
  arr6->size = arr->size + arr2->size;

  return arr6;
}

arr_short* Intersection(arr_short *arr, arr_short *arr2){

  arr_short *arr9 = (arr_short *) malloc(sizeof(arr_short));

  int i, j, k;
  i = j = k = 0; 


  while(i < arr->length && j < arr2->length){
    if(arr->A[i] < arr2->A[j]){
      i++;
    } else if(arr->A[i] > arr2->A[j]) {
      j++;
    } else {
      arr9->A[k++] = arr->A[i++];
    }
  }

  for(; i < arr->length; i++){
    arr9->A[k++] = arr->A[i++];
  }

  arr9->length = k;
  arr9->size = arr->size + arr2->size;

  return arr9;
}

arr_short* Difference(arr_short *arr, arr_short *arr2){

  arr_short *arr12 = (arr_short *) malloc(sizeof(arr_short));

  int i, j, k;
  i = j = k = 0; 


  while(i < arr->length && j < arr2->length){
    if(arr->A[i] == arr2->A[j]){
        j++;
        i++;
    } else if(arr->A[i] < arr2->A[j]) {
        i++;
    } else {

    }
  }

  for(; i < arr->length; i++){
    arr12->A[k++] = arr->A[i++];
  }

  arr12->length = k;
  arr12->size = arr->size + arr2->size;

  return arr12;
}


arr_short* merge(arr_short *arr, arr_short *arr2){

  arr_short *arr3 = (arr_short *) malloc(sizeof(arr_short));

  int i, j, k;
  i = j = k = 0; 


  while(i < arr->length && j < arr2->length){
    if(arr->A[i] < arr2->A[j]){
      arr3->A[k++] = arr->A[i++]; 
    } else {
      arr3->A[k++] = arr2->A[j++];
    }
  }

  for(; i < arr->length; i++){
    arr3->A[k++] = arr->A[i++];
  }

  for(; j < arr2->length; j++){
    arr3->A[k++] = arr2->A[j++];
  }

  arr3->length = k;
  arr3->size = arr->size + arr2->size;

  return arr3;
}

int main()
{

  arr_short arr = {{42,3,74,-55,6},20,5};  
 
  int arrEx[15] = {20, 40, 50, 18, 17, 29, 19, 54, 32, 91, 23, 1, 3, 5, 6};

  arr_short arr2 = {{ 14, 53, 25, 32, 53}, 20, 5 };

  arr_short *arr3; 

  sorted(&arr);

  Display(arr);

  sorted(&arr2);

  arr3 = merge(&arr, &arr2);

  Display(*arr3);

  arr_short arr4 = {{ 4, 6, 1, 9, 11}, 20, 5 };

  arr_short arr5 = {{ 10, 23, 2, 4, 1}, 20, 5 };

  sorted(&arr5);

  sorted(&arr4);

  arr_short *arr6;

  arr6 = Union(&arr4, &arr5);

  Display(*arr6);

  arr_short arr7 = {{ 4, 6, 1, 9, 11}, 20, 5 };

  arr_short arr8 = {{ 10, 23, 1, 4, 11}, 20, 5 };

  arr_short *arr9;

  sorted(&arr7);
  sorted(&arr8);

  Display(arr7);
  Display(arr8);

  arr9 = Intersection(&arr7, &arr8);

  Display(*arr9);

  arr_short arr10 = {{ 4, 6, 1, 9, 11}, 20, 5 };

  arr_short arr11 = {{ 10, 23, 1, 4, 11}, 20, 5 };

  arr_short *arr12;

  arr12 = Difference(&arr10, &arr11);

  Display(*arr12);

  BinarySearch(arr, 0, arr.length - 1, 34);

  printf("This is the sum of the elements in the array: %d\n", Sum(arr));

  printf("This is the average of the elements in the array: %d\n", Avg(arr));

  printf("The highest element in the array is: %d\n", Max(arr));

  Display(arr);

  return 0;
}