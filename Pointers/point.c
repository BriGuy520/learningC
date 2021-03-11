#include <stdio.h>


int main(){

  int num = 1;
  int *ptr = &num;

  printf("Value of num = %d\n", num);
  printf("Address of num = %x\n\n", &num);

  printf("The value of ptr = %x\n", ptr);
  printf("Address of ptr = %x\n", &ptr);
  printf("The value of the pointer = %d\n\n", *ptr);

  num = 10;
  printf("value of num = %d\n", num);
  printf("address of pointer = %x\n", &ptr);
  printf("value of pointer = %d\n\n", *ptr);


  *ptr = 100;
   printf("Value of num = %d\n", num);
   printf("Value of ptr = %x\n", ptr);
   printf("Value of pointer = %d\n", *ptr);
   printf("Address of ptr = %x\n", &ptr);
}