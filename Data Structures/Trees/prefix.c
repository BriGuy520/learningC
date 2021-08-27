#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CHARS 256

typedef struct trienode {
  struct trienode *children[MAX_CHARS];
  bool terminal;
} trienode;


trienode *createNode(){
  trienode *newnode = malloc(sizeof *newnode);

  for(int i = 0; i < MAX_CHARS; i++){

  }
}


int main(){
  
}
