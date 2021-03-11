#include <stdio.h>


int main(){

  char *str1 = "Hello World!";
  char str2[] = "Hello World!";

  printf("%s\n", str1);
  printf("%s", str2);

  return 0;
}