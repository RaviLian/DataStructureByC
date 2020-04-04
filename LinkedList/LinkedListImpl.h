//
// Created by RaviLian on 2020/4/3.
//

#ifndef LINKEDLIST_LINKEDLISTIMPL_H
#define LINKEDLIST_LINKEDLISTIMPL_H
//Linked list with leading nodes
typedef struct LNode
{
    int data;
    struct Lnode *next;
}LNode;

/***
 * Create a linked list by tail interpolation
 * @param C New linked list address
 * @param a Save the data inserted into the linked list
 * @param n Number of data
 */
LNode* createListT(int a[],int n);

void PrintList(LNode *C);

#endif //LINKEDLIST_LINKEDLISTIMPL_H
