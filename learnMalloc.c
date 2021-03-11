#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
  char *str;

  str = (char *) malloc(15);
  strcpy(str, "this is a st");
  printf("String = %s, Address = %u\n", str, str);

  str = (char *) realloc(str, 25);
  strcat(str, ".com");
  printf("\nString = %s, Address = %u", str, str);

  return 0;
 
}

