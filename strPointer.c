#include <stdio.h>

// Accessing string via pointer

int main(void){

  // string variable 
  char str[6] = "Hello";

  // pointer variable
  char *ptr = str;

  // print the string
  while(*ptr != '\0'){
    printf("%c\n", *ptr);

    ptr++;
  }

  return 0;

}