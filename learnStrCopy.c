#include <stdio.h>
#include <string.h>

int main(){
  char src[40];
  char dest[100];


  memset(dest, '\0', sizeof(dest));
  strcpy(src, "I'm learning how to use strcpy");
  puts(src);
  strcpy(src, dest);



  return(0);
}