#include<stdio.h>
#include<stdlib.h>
#include"BTree.h"

int main() {
  BinTree myTree;
  BinTree newTree;
  CreateBinaryTree(&myTree);
  printf("\n");
  PreOrderTraversal(myTree);
  printf("\n");
  InOrderTraversal(myTree);
  printf("\n");
  PostOrderTraversal(myTree);
  printf("\n");
  PreOrderPrintLeaves(myTree);
  printf("\n");
  // int high = PostOrderGetHeight(myTree);
  // printf("The height of the tree: %4d", high);
  CopyBinaryTree(myTree, &newTree);
  printf("new Tree :\n");
  PreOrderTraversal(newTree);
  printf("\nExchange new Tree:\n");
  ExchangeChilden(newTree);
  PreOrderTraversal(newTree);
  return 0;
}
