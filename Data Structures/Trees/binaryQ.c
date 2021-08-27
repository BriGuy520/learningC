#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"

Node *root = NULL;

void createTree(){

  Node *p, *t; 
  int x;
  Q q;
  create(&q, 100);

  printf("Enter root value: ");
  scanf("%d", &x);

  root = (Node *) malloc(sizeof(Node));

  root->data = x;
  root->leftChild = root->rightChild = NULL;
  enqueue(&q, root);

  while(!isEmpty(q)){

    p = dequeue(&q);
    printf("Enter left child of %d ", p->data);
    scanf("%d", &x);
    
    if(x != -1){

      t = (Node * ) malloc(sizeof(Node));
      t->data = x;
      t->leftChild = t->rightChild = NULL;
      p->leftChild = t;

      enqueue(&q,t);
    }

    printf("Enter right child of %d ", p->data);
    scanf("%d", &x);

    if(x != -1){

      t = (Node *) malloc(sizeof(Node));
      t->data = x;
      t->leftChild = t->rightChild = NULL;
      p->rightChild = t;

      enqueue(&q, t);
    }
  }
}

void preorder(Node *p){

  if(p){
    printf("%d ", p->data);
    preorder(p->leftChild);
    preorder(p->rightChild);
  }
}

void inorder(Node *p){

  if(p){
    preorder(p->leftChild);
    printf("%d ", p->data);
    preorder(p->rightChild);
  }
}

void postorder(Node *p){

  if(p){
    preorder(p->leftChild);
    preorder(p->rightChild);
    printf("%d ", p->data);
  }
}



int main(){

  createTree();
  printf("preorder traversal: ");
  preorder(root);
  printf("\npostorder traversal: ");
  postorder(root);
  printf("\ninorder traversal: ");
  inorder(root);
  
}