#include <stdio.h>


int power(int base, int exp)
{

  if(exp == 0)
    return 1;
  return power(base, exp - 1) * base;

}

int powerLess(int base, int exp)
{

  printf("powerLess base value = %d, powerLess exp value = %d\n", base, exp);

  if(exp == 0)
    return 1;
  if(exp % 2 == 0)
    return powerLess(base * base, exp/2);
  return base * powerLess(base*base, (exp - 1)/2);
}


int main()
{

  unsigned long long int y, z;
  int x = 9;
  y = power(2, x);
  printf("%llu\n", y);

  z = powerLess(2, x);
  printf("%llu ", z);
  return 0;
}