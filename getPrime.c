#include <stdio.h>

int checkPrime(int n){

  if(n == 0 || n == 1){
    return 0;
  }

  for(int i = 2; i < n / 2; i++){

    if(n % i == 0){
      return 0;
    }
  }

  return 1;

}

int getPrime(int n){

  if(n % 2 == 0){
    n++;
  }

  while(!checkPrime(n)){
    
    n += 2;
  
  }

  return n;
}


int main(){

  int x = 14; 

  printf("%d", getPrime(x));

}