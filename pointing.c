#include <stdio.h>

int main(){

  int x = 11;
  int a = 10;

  int *p, *j;

  p = &a;
  j = &x;

  printf("this is what the value of a is stored in p %d\n", *p);
  printf("this is what the value is in memory %d\n", p);
  printf("This is what the value is x is stored in j %d\n", *j);
  printf("This is what the memory location of j is %d", j);
}