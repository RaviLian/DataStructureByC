#include<stdio.h>
#include<stdlib.h>
#define ERROR 0
#define OK 1
#define MAXSIZE 100

typedef char ElementType;
typedef int Position;
struct SNode {
    ElementType *Data; /* 存储元素的数组 */
    Position Top;      /* 栈顶指针 */
    int MaxSize;       /* 堆栈最大容量 */
};
typedef struct SNode *Stack;

typedef struct DoubleStack *DStack;
struct DoubleStack
{
    ElementType Data[MAXSIZE];
    int Top1; //DStack.Top1 = -1
    int Top2; // DStack.Top2 = MAXSIZE
};

void PushD (DStack PtrDS, ElementType item, int Tag);
ElementType PopD (DStack PtrDS, int Tag);
DStack CreateDStack();

Stack CreateStack( int MaxSize );
int IsFull( Stack S );
int Push( Stack S, ElementType X );
int IsEmpty( Stack S );
ElementType Pop( Stack S );


int main() {
    Stack sa;
    sa = CreateStack(5);
    int i;
    if(IsEmpty(sa))
        printf("\nThe Stack is Empty!\n");


    char ch[5] = {'e','l','p','p','a'};
    for (i = 0; i < 5; i++) {
        Push(sa,ch[i]);
    }

    printf("\nPrint the stack:\n");
    for (i = 0; i < 5; i++)
        printf("%c",sa->Data[i]);

    if(IsFull(sa))
        printf("\nThe Stack is Full!\n");

    printf("\nPoP the Elements:\n");
    for (i = 0; i < 5; i++)
        printf("%c",Pop(sa));
    printf("\n");
    DStack ds;
    ds = CreateDStack();
    char ch1[50] = {'a','t','t','a','c','k'};
    char ch2[50] = {'b','a','n','a','n','a'};
    int j = 0;
    int k = 0;

    while (ch1[j] != '\0')
    {
        PushD(ds, ch1[j], 1);
        j++;
    }
    while (ch2[k] != '\0')
    {
        PushD(ds, ch2[k], 2);
        k++;
    }
    //Test for Stack 2
    // for (k = MAXSIZE - 1; k >= ds->Top2; k--)
    // {
    //     printf("%c",ds->Data[k] );
    // }

    printf("\n");

    for(j = 0; j < 6; j++)
    {
        printf("%c",PopD(ds,1) );
    }
    printf("\n");
    for (k = 0; k < 6; k++)
    {
        printf("%c",PopD(ds,2) );
    }


    return 0;
}



Stack CreateStack( int MaxSize )
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    S->Top = -1;
    S->MaxSize = MaxSize;
    return S;
}

int IsFull( Stack S )
{
    return (S->Top == S->MaxSize-1);
}

int Push( Stack S, ElementType X )
{
    if ( IsFull(S) ) {
        printf("\nThe Stack is Full!\n");
        return ERROR;
    }
    else {
        S->Data[++(S->Top)] = X;
        return OK;
    }
}

int IsEmpty( Stack S )
{
    return (S->Top == -1);
}

ElementType Pop( Stack S )
{
    if ( IsEmpty(S) ) {
        printf("The Stack is Empty!");
        return ERROR;
    }
    else
        return ( S->Data[(S->Top)--] );
}

void PushD (DStack PtrDS, ElementType item, int Tag)
{
    //Tag == 1,压入左边的栈，Tag == 2,压入右边的栈
    //先判断栈是否满
    if (PtrDS->Top1 == PtrDS->Top2)
    {
        printf("The Double Stack is Full!\n");
        return;
    }
    if (Tag == 1)
        PtrDS->Data[++(PtrDS->Top1)] = item;
    if (Tag == 2)
        PtrDS->Data[--(PtrDS->Top2)] = item;
}

ElementType PopD (DStack PtrDS, int Tag)
{
    if (Tag == 1)
    {
        if (PtrDS->Top1 == -1)
        {
            printf("The Stack 1 is Empty!\n");
            return ERROR;
        }
        else
        {
            return PtrDS->Data[(PtrDS->Top1)--];
        }
    }
    if (Tag == 2)
    {
        if (PtrDS->Top2 == MAXSIZE)
        {
            printf("The Stack 2 is Empty!\n");
            return ERROR;
        }
        else
        {
            return PtrDS->Data[(PtrDS->Top2)++];
        }
    }

    return ERROR;
}

DStack CreateDStack() {
    DStack DS = malloc (sizeof(struct DoubleStack));
    DS->Top1 = -1;
    DS->Top2 = MAXSIZE;
    return DS;
}
