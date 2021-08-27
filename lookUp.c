#include <stdio.h>

#define MAX_SIZE 5

const char *messages[] = {
  "This is not a party", 
  "This is a ONE hell of a party",
  "This is starting to get fun", 
  "This is a great party", 
  "Call the fire department"
};

void people_at_party(size_t people){

  if(people > MAX_SIZE - 1){
    printf("%s\n", messages[MAX_SIZE - 1]);
  } else {
    printf("%s\n", messages[people]);
  }
}


int main(){


  people_at_party(0);
  people_at_party(1);
  people_at_party(2);
  people_at_party(3);
  people_at_party(4);
  people_at_party(5);
  people_at_party(35);

}