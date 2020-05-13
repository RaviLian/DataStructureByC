#include<stdio.h>
#include<stdlib.h>
#define ERROR 0
#define OK 1
#define OVERFLOW -1

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node { /* 队列中的结点 */
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode Position;

struct QNode {
    Position Front, Rear;  /* 队列的头、尾指针 */
};
typedef struct QNode *Queue;

Queue CreateQueue() {
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->Front = Q->Rear = (Position)malloc(sizeof(struct Node));
    if(!Q->Front) exit(OVERFLOW);
    Q->Front->Next = NULL;
    return Q;
}

int IsEmpty( Queue Q )
{
    return ( Q->Front == Q->Rear);
}

void AddQ(Queue Q, ElementType X) {
    Position item = (Position)malloc(sizeof(struct Node));
    item->Data = X;
    item->Next = NULL;
    Q->Rear->Next = item;
    Q->Rear = item;
}

ElementType DeleteQ( Queue Q )
{
    Position FrontCell;
    ElementType FrontElem;

    if  ( IsEmpty(Q) ) {
        printf("The Queue is Empty!");
        return ERROR;
    }
    else {
        FrontCell = Q->Front->Next;
        FrontElem = FrontCell->Data;
        Q->Front->Next = FrontCell->Next;

        if(Q->Rear == FrontCell) /* 若仅一个元素在队列中，删除后令Rear指向头结点 */
            Q->Rear = Q->Front;
        free( FrontCell );  /* 释放被删除结点空间  */
        return  FrontElem;
    }
}

int main(int argc, char const *argv[])
{
    int i;
    Queue test = CreateQueue();
    for ( i = 0; i < 10; i++)
    {
        AddQ(test,i);
        printf("Add %d \n", i+1);
    }
    for ( i = 0; i < 10; i++)
    {
        ElementType value = DeleteQ(test);
        printf("%-4d",value);
    }
    for ( i = 5; i < 10; i++)
    {
        AddQ(test,i);
    }
    ElementType value = DeleteQ(test);
    printf("%-4d",value);
    return 0;
}
