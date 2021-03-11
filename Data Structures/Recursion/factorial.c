#include <stdio.h>

int fact(int x)
{

  if(x <= 1)
    return 1;
  return fact(x - 1) * x;

}


int main()
{

  int y;
  unsigned long long int j;

  printf("%d\n ", sizeof(j));

  y = 10;
  j = fact(y);
  printf("%llu", j);
}