//
// Created by xiaoyumei on 2020/3/29.
//
#include <stdlib.h>
#ifndef LINEARLIST_ARRAY_ARRAYIMPL_H
#define LINEARLIST_ARRAY_ARRAYIMPL_H
#define MAXSIZE 100

struct LNode{
    int Data[MAXSIZE];
    int Last;
};

typedef struct LNode *List;


//1.初始化（建立空的顺序表）
List MakeEmpty(){
    List PtrL;
    PtrL = (List)malloc(sizeof(struct LNode));
    PtrL->Last = -1;
    return PtrL;
}

//2.查找
int Find(int X, List PtrL){
    int i = 0;
    while(i <= PtrL->Last && X != PtrL->Data[i])
        i++;
    if(i > PtrL->Last)
        return -1;     //如果没找到就返回-1
    else
        return i;     //如果找到了 返回下标
}

//3.插入（在第i（1<i<n+1）个位置上插入一个值为X的元素）
void Insert(int X, int i, List PtrL)
{
    int j;
    if(PtrL->Last == MAXSIZE-1){	/*表空间已满，不能插入*/
        printf("表满");
        return;
    }
    if(i < 1 || i > PtrL->Last+2){	/*检查插入位置的合法性*/
        printf("位置不合法");
        return;
    }
    for(j = PtrL->Last-1; j >= i-1; j--){/*将ai到an倒叙向后移动*/
        PtrL->Data[j+1] = PtrL->Data[j];
    }
    PtrL->Data[i-1] = X;	/*插入新元素*/
    PtrL->Last++;			/*令Last指向最后一个元素*/
    return;
}

void Delete(int i, List PtrL)	/*i实际上是下标+1*/
{
    int j;
    if(i < 1 || i > PtrL->Last+1){
        printf("不存在第%d个元素",i);	/*检查删除位置的合法性*/
        return;
    }
    for(j = i; j <= PtrL->Last; j++)
        PtrL->Data[j-1] = PtrL->Data[j];	/*ai+1到an向前挪*/
    PtrL->Last--;							/*检查插入位置的合法性*/
    return;
}



#endif //LINEARLIST_ARRAY_ARRAYIMPL_H
