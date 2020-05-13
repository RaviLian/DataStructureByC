#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0

typedef int ElementType;
typedef int Position;
struct QNode {
    ElementType *Data;     /* 存储元素的数组 */
    Position Front, Rear;  /* 队列的头、尾指针 */
    int MaxSize;           /* 队列最大容量 */
};
typedef struct QNode *Queue;

Queue CreateQueue( int MaxSize )
{
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    Q->Front = Q->Rear = 0;
    Q->MaxSize = MaxSize;
    return Q;
}

int IsFull( Queue Q )
{
    return ((Q->Rear+1) % (Q->MaxSize) == Q->Front);
}

int AddQ( Queue Q, ElementType X )
{
    if ( IsFull(Q) ) {
        printf("The Queue is Full!");
        return false;
    }
    else {
        Q->Rear = (Q->Rear+1)%Q->MaxSize;
        Q->Data[Q->Rear] = X;
        return true;
    }
}

int IsEmpty( Queue Q )
{
    return (Q->Front == Q->Rear);
}

ElementType DeleteQ( Queue Q )
{
    if ( IsEmpty(Q) ) {
        printf("The Queue is Empty!");
        return false;
    }
    else  {
        Q->Front = (Q->Front+1) % (Q->MaxSize);
        return  Q->Data[Q->Front];
    }
}

int main(int argc, char const *argv[])
{
    int i;
    Queue test = CreateQueue(10);
    for (i = 0; i < 10; i++) {
        AddQ(test,i);
    }
    printf("\n");
    for(i = 0; i < 10; i++) {
        int value = DeleteQ(test);
        if (i >= test->MaxSize - 1 && value == 0 ) {
            printf("\n");
        }else {
            printf("%-4d",value);
        }
    }
    printf("\n");
    return 0;
}
