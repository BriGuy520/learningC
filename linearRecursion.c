#include <stdio.h>


void func(int x){

  if(x > 0){

    printf("First printf: %d\n", x);
    func(x - 1);
    printf("Second printf: %d\n", x);
    func(x - 1);
  }
}

int main(){

  int v = 3;

  func(v);
}