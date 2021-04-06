#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Rectangle {
  int length;
  int width;
};

int area(struct Rectangle r1){

  r1.length++;

  return r1.length * r1.width;

}

int main(){


  struct Rectangle r = { 10, 5 };

  printf("%d is the area of the rectangle\n", area(r));
  printf("The value of r.length is %d", r.length);
}