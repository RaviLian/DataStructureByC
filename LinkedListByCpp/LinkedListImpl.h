//
// Created by RaviLian on 2020/4/4.
//

#ifndef LINKEDLISTBYCPP_LINKEDLISTIMPL_H
#define LINKEDLISTBYCPP_LINKEDLISTIMPL_H
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode;

void createListT(LNode *&C,int a[],int n);
void PrintList(LNode *&C);
#endif //LINKEDLISTBYCPP_LINKEDLISTIMPL_H
