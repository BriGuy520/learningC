#include <stdio.h>

int main(){

  /* A nice long string */
  char string[256];

  printf("Please enter a long string: ");

  fgets(string, 256, stdin);

  printf("You entered a very long string, %s", string);

  getchar();


}