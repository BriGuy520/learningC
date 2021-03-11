#include <stdio.h>


int sum(int n)
{

  if(n == 0)
    return 0;
  return sum(n - 1) + n;
}

int constantSum(int n){

  return n * (n + 1) / 2;
}


int main()
{
  int b, r;
  b = 5;
  r = sum(b);
  int a = constantSum(b);

  printf("%d\n", r);
  printf("constantSum: %d\n", a);
  
  return 0;
}