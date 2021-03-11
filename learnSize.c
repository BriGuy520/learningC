#include <stdio.h>
#include <string.h>

int main(){
  int a = 16;
  int b = 2094399434;
  double c = 2.45;
  char hello[15] = "hello";

  puts(hello);

  printf("Size of variable a: %d\n", sizeof(a));
  printf("Size of hello: %d\n", sizeof(hello));
  printf("Size of int b is: %d\n", sizeof(b));
  printf("Size of double c: %d\n", sizeof(c));
  printf("Size of int data type: %d\n", sizeof(int));
  printf("Size of char data type: %d\n", sizeof(char));
  printf("Size of float data type: %d\n", sizeof(float));
  printf("Size of double data type: %d\n", sizeof(double));

  return 0;
}