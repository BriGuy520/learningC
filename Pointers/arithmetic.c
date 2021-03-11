#include <stdio.h>


int main(){

  int num = 5;
  int *ptr;

  ptr = &num;
  printf("Memory Address: %x\n",ptr);
  ptr++;
  printf("Memory Address: %x\n", ptr);
  ptr--;
  printf("Memory Address: %x\n", ptr);


}