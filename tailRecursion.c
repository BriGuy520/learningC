#include <stdio.h>


void func1(int n){

  while(n > 0){

    printf("%d\n", n);
    n--;
  }
}

void func2(int n){

  if(n > 0){

    printf("N: %d\n", n);
    func2(n - 1);
  }
}


int main(){

  int a = 11;

  func1(a);

  func2(a);
}