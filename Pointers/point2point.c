#include <stdio.h>


int main(){

  int num;
  
  int *ptr = &num;
  int **dPtr = &ptr;

  num = 10; 
  printf("Value of num = %d\n", num);
  printf("Value pointed by ptr = %d\n", *ptr);
  printf("Value of pointed by dPtr = %d\n\n", **dPtr);
  printf("Address of num = %x\n", num);
  printf("Address of ptr = %x\n", ptr);
  printf("Address of dPtr = %x\n", dPtr);
  }


