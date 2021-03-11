#include <stdio.h>


struct Rectangle {
  int length; 
  int width;
};

void changeLength(struct Rectangle *p, int l){
  p->length = l;
}

int area(struct Rectangle r1){
  return r1.length * r1.width;
}

void initialize(struct Rectangle *r1, int x, int y){
  
  r1->length = x;
  r1->width = y;
}


int main(){

  struct Rectangle r;


  initialize(&r, 10, 5);

  printf("This is the length of the rectangle %d and this is the width %d of the rectangle for an area of %d", r.length, r.width, area(r));

  changeLength(&r, 20);

  printf("\nThis is the new length of the rectangle: %d. It has a new area of %d", r.length, area(r));
}
