#include<stdlib.h>
#include<stdio.h>
#define true 1
#define false 0

typedef int ElementType;
typedef struct SNode *PtrToSNode;
struct SNode {
    ElementType Data;
    PtrToSNode Next;
};
typedef PtrToSNode Stack;

/* 构建一个堆栈的头结点，返回该结点指针，该结点并不保存元素 */
Stack CreateStack( )
{ 
    Stack S;

    S = (Stack)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}

/* 判断堆栈S是否为空，若是返回1；否则返回0 */
int IsEmpty ( Stack S )
{ 
    return ( S->Next == NULL );
}

/* 将元素X压入堆栈S */
int Push( Stack S, ElementType X )
{ 
    PtrToSNode TmpCell;

    TmpCell = (PtrToSNode)malloc(sizeof(struct SNode));
    TmpCell->Data = X;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
    return true;
}

/* 删除并返回堆栈S的栈顶元素 */
ElementType Pop( Stack S )
{ 
    PtrToSNode FirstCell;
    ElementType TopElem;

    if( IsEmpty(S) ) {
        printf("The Stack is Empty!\n");
        return false;
    }
    else {
        FirstCell = S->Next;
        TopElem = FirstCell->Data;
        S->Next = FirstCell->Next;
        free(FirstCell);
        return TopElem;
    }
}

int main(int argc, char const *argv[])
{   
    int i;
    Stack sk = CreateStack();
    if (!IsEmpty)
        printf("The Stack is Empty! Input your elements!\n");
    for (i = 0; i < 10; i++)
        Push(sk, i*i);
    for (i = 0; i < 10; i++)
        printf("%-4d",Pop(sk));
    return 0;
}

