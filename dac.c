#include <stdio.h>


int DAC_Max(int a[], int index, int l){

  int max;

  if(index >= l - 2){
    if(a[index] > a[index + 1])
      return a[index];
    else
      return a[index + 1];
  }

  max = DAC_Max(a, index + 1, l);

  if(a[index] > max)
    return a[index];
  else 
    return max;
}

int DAC_Min(int a[], int index, int l){

  int min;

  if(index >= l - 2){
    if(a[index] < a[index + 1])
      return a[index];
    else 
      return a[index + 1];
  }


  min = DAC_Min(a, index + 1, l);

  if(a[index] < min)
    return a[index];
  else
    return min;
}

int main(){

  int min, max, N;

  int a[7] = { 70, 250, 50, 80, 140, 12, 14 };

  max = DAC_Max(a, 0, 7);
  min = DAC_Min(a, 0, 7);
  
  printf("The minimum number in a given array is : %d\n", min);
  printf("The maximum number in a given array is : %d", max);
}