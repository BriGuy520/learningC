#include <stdio.h>
#include <string.h>


int main(){

  char str[] = "welcome";
  char str2[] = "hello world";
  char str3[] = "fInaLLy we haVe tHiS";
  int i, j;
  char temp;
  int length = 0;

  for(i = 0; str[i] != '\0'; i++){
    length++;
  }

  for(i = 0, j = length - 1; i < j; i++, j--){
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
  }

  printf("%d\n", str2[0]);

  for(i = 0; str2[i] != '\0'; i++){
    if(i == 0 || str2[i - 1] == ' '){
      str2[i] = str2[i] - 32;
    }
  }

  for(i = 0; str3[i] !='\0'; i++){

    if(str3[i] >= 65 && str3[i] <= 90){
        str3[i] = str3[i] + 32;
    } else if(str3[i] >= 97 && str3[i] <= 122){
        str3[i] -= 32;
    }
  }

  printf("%s\n", str2);
  printf("%d\n", str[0]);

  printf("%d\n", str3[0]);

  printf("str3: %s\n", str3);

  printf("The length of the string %s is %d\n", str, length);
  printf("This is the reverse of the string: %s", str);
}