#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

  struct Node *leftChild;
  struct Node *rightChild;

  int data;
  int height;

} Node;


Node *root = NULL;

int nodeHeight(Node *p){

  int hl, hr;

  hl = p && p->leftChild ? p->leftChild->height : 0;
  hr = p && p->rightChild ? p->rightChild->height : 0;

  return hr > hl ? hr + 1 : hl + 1;

}


int loadBalancer(Node *p){

  int hl, hr;

  hl = p && p->leftChild ? p->leftChild->height : 0;
  hr = p && p->rightChild ? p->rightChild->height : 0;

  return hl - hr;
}

Node *LLRotation(Node *p){

  Node *pl = p->leftChild;

  p->leftChild = pl->rightChild;
  pl->rightChild = p;

  pl->height = nodeHeight(pl);
  p->height = nodeHeight(p); 

  if(root == p){
    root = pl;
  }

  return pl;

}

Node *LRRotation(Node *p){

  Node *pl = p->leftChild;
  Node *plr = pl->rightChild;

  pl->rightChild = p->rightChild;
  p->leftChild = pl->leftChild;

  plr->rightChild = p;
  plr->leftChild = pl;

  plr->height = nodeHeight(plr);
  pl->height = nodeHeight(pl);
  p->height = nodeHeight(p);

  if(root == p){

    root = plr;
  }

  return plr;

}

Node *RRRotation(Node *p){

  Node *pr = p->rightChild;

  p->rightChild = p->leftChild;
  pr->leftChild = p;

  p->height = nodeHeight(p);
  pr->height = nodeHeight(pr);

  if(root == p){
    root = pr;
  }

  return pr;
}

Node *RLRotation(Node *p){

  Node *pr = p->rightChild;
  Node *prl = pr->leftChild;

  p->rightChild = pr->rightChild;
  pr->leftChild = p->leftChild;

  prl->leftChild = p;
  prl->rightChild = pr;

  prl->height = nodeHeight(prl);
  pr->height = nodeHeight(pr);
  p->height = nodeHeight(p);

  if(p == root){
    root = prl;
  }

  return prl;
}


Node *RInsert(Node *p, int data){

  Node *t = NULL;

  if(p == NULL){

    t = (Node *) malloc(sizeof(Node));

    t->data = data;
    t->height = 1;
    t->leftChild = t->rightChild = NULL;
    
    return t;
  }

  if(data < p->data){
    p->leftChild = RInsert(p->leftChild, data);
  } else if (data > p->data){
    p->rightChild = RInsert(p->rightChild, data);
  }

  p->height = nodeHeight(p);


  if(loadBalancer(p) == 2 && loadBalancer(p->leftChild) == 1){
    return LLRotation(p);
  } else if(loadBalancer(p) == 2 && loadBalancer(p->leftChild) == -1){
    return LRRotation(p);
  } else if(loadBalancer(p) == -2 && loadBalancer(p->rightChild) == -1){
    return RRRotation(p);
  } else if(loadBalancer(p) == -2 && loadBalancer(p->rightChild) == 1){
    return RLRotation(p);
  }

  return p;

}

void inorder(Node *p){

  if(p != NULL){
    inorder(p->leftChild);
    printf("%d ", p->data);
    inorder(p->rightChild);
  }

}


int main(){

  root = RInsert(root, 40);
  RInsert(root, 80);
  RInsert(root, 60);

  inorder(root);

}