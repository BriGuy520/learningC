#include <stdio.h>

struct Rectangle {
  int length;
  int width;
};


void changeLength(struct Rectangle *p, int l){
  p->length = l;
}



int main(){

  struct Rectangle r = { 10, 5 };

  printf("The length of the rectangle is %d and the width is %d", r.length, r.width);

  changeLength(&r, 20);


  printf("\nThe new length of the rectangle is %d", r.length);


}