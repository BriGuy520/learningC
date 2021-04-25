#include <stdio.h>

int i = 5;

extern int callVar(){

  static int num = 0;

  num++;
  return num;
}

void foo(void);

int main(void){
  
  printf("%i ", i);
  foo();
  printf("%i ", i);

  for(int i = 0; i < 5; i++){

    printf("%d ", callVar());
  }

  return 1;
  
}