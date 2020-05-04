#include<stdio.h>
#include<stdlib.h>
#include"BTree.h"

int main() {
  BinTree myTree;
  printf("Create your Binary Tree:\n");
  CreateBinaryTree(&myTree);
  printf("\n PreOrder:");
  PreOrderTraversal(myTree);
  printf("\n InOrder:");
  InOrderTraversal(myTree);
  printf("\n PostOrder:");
  PostOrderTraversal(myTree);
  printf("\n Leaves:");
  PreOrderPrintLeaves(myTree);
  printf("\n");
  int high = PostOrderGetHeight(myTree);
  printf("The height of the tree: %4d", high);
  return 0;
}
