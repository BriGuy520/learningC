#include <stdio.h>

void funcA(double n);
void funcB(float m);


void funcA(double n){

  if(n > 0){
    printf("This is firing from funcA: %.4lf\n", n);
    funcB(n - 1);
  }
}


void funcB(float m){

  if(m > 1){
    printf("This is firing from funcB: %3.2f\n", m);
    funcA(m / 2);
  }
}


int main(){

  int a = 40;

  funcA(a);

  return 0;

}