//
// Created by RaviLian on 2020/4/4.
//

#ifndef LINKEDLIST_DOUBLELINKEDLISTIMPL_H
#define LINKEDLIST_DOUBLELINKEDLISTIMPL_H
typedef struct DLNode
{
    int data;
    struct DLnode *prior;
    struct DLnode *next;
}DLNode;
#endif //LINKEDLIST_DOUBLELINKEDLISTIMPL_H
