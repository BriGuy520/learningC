#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

  char str[] = "HELLO";
  char revStr[strlen(str)];
  int i, k, l;
  
  l = 0;

  for(i = 0; str[i] != '\0'; i++)
    if(str[i] >= 97 && str[i] <= 122)
      str[i] = str[i] - 32;
    else if(str[i] >= 65 && str[i] <= 90)
      str[i] = str[i] + 32;

  // Reverse the string
  for(k = i - 1; k >= 0; k--){
    revStr[l] = str[k];
    l++;
  }

  printf("\n");

  printf("This is the string uppercase %s\n", str);
  printf("This is the string reversed: %s\n", revStr);
  printf("Length of the string is %d\n", i);

  printf("This is the character: %c, This is the ASCII value: %d", str[0], str[0]);

}