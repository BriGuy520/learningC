#include <stdio.h>


struct Rectangle {
  int width;
  int length;
};

int main(){

  struct Rectangle r;
  struct Rectangle rect = {10, 5};

  printf("This is the value of r: %d\n", rect.width);
  printf("This is the value of Rect length: %d", rect.length);

  r.length = 20;
  r.width = 40;

  printf("this isthe value of r: %d\n", r.length);
  printf("this is the value r width: %d", r.width);


}