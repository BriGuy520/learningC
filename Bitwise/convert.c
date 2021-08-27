#include <stdio.h>
#include <math.h>

int convertDecimal(long long value){

  int dec = 0, i = 0, rem; 

  while(value != 0){
    rem = value % 8;
    printf("value = %d; rem = %d\n", value, rem);
    value /= 8;
    dec += rem * pow(2, i);
    ++i;
  } 

  return dec;
}

int main(){

  long long n;
  printf("Enter a binary number: ");
  scanf("%lld", &n);
  printf("\nBinary: %lld, Decimal: %d", n, convertDecimal(n));

}