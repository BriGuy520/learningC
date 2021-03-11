#include <stdio.h>

int main(){

  char name[11];

  printf("Enter a name: ");
  gets(name);

  printf("\nYou entered: ");
  puts(name);

  return 0;
}