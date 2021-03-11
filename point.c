#include <stdio.h>

int main(){

  int* pc, c;

  c = 5;
  pc = &c;

  printf("%d", *pc);
  printf("\n%x, %p, %d\n", pc, pc, *pc);
  printf("%p, %d, %x\n", &c, c, c);

  int var1;
  char var2[10];

  printf("Address of var1 variable: %x\n", &var1);
  printf("Address of var2 variable: %x\n", &var2);

  printf("c: %d", c);

  c = 11;

  printf("c after: %d", c);

  return 0;

}