#include <stdio.h>
#include <stdlib.h>


typedef struct Node {

  int data;
  int height;

  struct Node *leftChild;
  struct Node *rightChild;
} Node;

Node *root = NULL;

int nodeHeight(Node *p){

  int hl, hr;

  hl = p && p->leftChild ? p->leftChild->height : 0;
  hr = p && p->rightChild ? p->rightChild->height : 0;

  return hl > hr ? hl + 1 : hr + 1;
}

int balanceFactor(Node *p){

  int hl, hr;

  hl = p && p->leftChild ? p->leftChild->height : 0;
  hr = p && p->rightChild ? p->rightChild->height : 0;

  return hl - hr;
}

Node *LLRotation(Node *p){

  Node *pl = p->leftChild;
  Node *plr = pl->rightChild;

  pl->rightChild = p;
  p->leftChild = plr;
  p->height = nodeHeight(p);
  pl->height = nodeHeight(pl);

  if(root == p){
    root = pl;
  }

  return pl;
}

Node *LRRotation(Node *p){

  Node *pl = p->leftChild;
  Node *plr = pl->rightChild;

  pl->rightChild = plr->leftChild;
  p->leftChild = plr->rightChild;

  pl->height = nodeHeight(pl);
  p->height = nodeHeight(p);
  plr->height = nodeHeight(plr);

  if(root == p){
    root = plr;
  }

  return plr;
}

Node *RRRotation(Node *p){
  return NULL;
}

Node *RLRotation(Node *p){
  return NULL;
}


Node *RInsert(Node *p, int key){

  Node *t = NULL;

  if(p == NULL){
    
    t = (Node *) malloc(sizeof(Node));

    t->data = key;
    t->height = 1;
    t->leftChild = t->rightChild = NULL;

    return t;
  }

  if(key < p->data){
    p->leftChild = RInsert(p->leftChild, key);
  } else if(key > p->data){
    p->rightChild = RInsert(p->rightChild, key);
  }

  p->height = nodeHeight(p);

  if(balanceFactor(p) == 2 && balanceFactor(p->leftChild) == 1){
    return LLRotation(p);
  } else if(balanceFactor(p) == 2 && balanceFactor(p->leftChild) == -1){
    return LRRotation(p);
  } else if(balanceFactor(p) == -2 && balanceFactor(p->rightChild) == -1){
    return RRRotation(p);
  } else if (balanceFactor(p) == -2 && balanceFactor(p->rightChild) == 1){
    return RLRotation(p);
  }

  return p;
}

int main(){

  root = RInsert(root, 10);
  RInsert(root, 5);
  RInsert(root, 2);

  return 0;
}