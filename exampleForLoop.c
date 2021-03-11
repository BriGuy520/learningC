#include <stdio.h>


int main() {
  int n = 200;
  int i, count, countTwo;

  for(i = n; i > 1; i = i / 2){
    count++;
    printf("the value at for loop %d is %d\n", count, i);
  }

  while(n > 1){
    
    printf("the value at while loop %d is %d\n", countTwo, n);

    n = n / 3;


  }


}