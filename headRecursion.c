#include <stdio.h>


void func1(int n){

  int i = 1;

  while(i < n){
    printf("%d\n", i);
    i++;
  }
}


void func2(int n){

  if(n > 0)
  {
    func2(n - 1); 
    printf("Hello: %d\n", n);
  }
}


int main(){

  int b = 11;
  int c = 12;

  func1(b);
  func2(c);
}