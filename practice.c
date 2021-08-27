#include <stdio.h>


int find(int a, int b){

  if(a + b == 11){

    return a + b;
  }

  if(a + b == 12){
    return a + b;
  }

  printf("THis is firing. :)");

}

int main(){

  find(11, 11);

}