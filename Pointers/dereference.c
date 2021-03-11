#include <stdio.h>

int main(){

  int num = 10;

  printf("Value of num = %d\n", num);

  printf("Address of num = %d\n",&num);

  printf("Value of num = %d\n", *(&num));

}