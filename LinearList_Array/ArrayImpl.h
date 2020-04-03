//
// Created by RaviLian on 2020/3/29.
//
#include <stdlib.h>
#ifndef LINEARLIST_ARRAY_ARRAYIMPL_H
#define LINEARLIST_ARRAY_ARRAYIMPL_H
#define MAXSIZE 100

struct LNode{
    int Data[MAXSIZE];
    int Last;  //代表数组下标
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
    for(j = PtrL->Last; j >= i-1; j--){/*将ai到an倒叙向后移动*/
        PtrL->Data[j+1] = PtrL->Data[j];
    }
    PtrL->Data[i-1] = X;	/*插入新元素*/
    PtrL->Last++;			/*令Last指向最后一个元素*/
    return;
}

void DeleteByPos(int i, List PtrL)	/*i实际上是下标+1*/
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

void DeleteByElem(int X, List PtrL)
{
    int i;
    int index = -1;
    for(i = 0; i <= PtrL->Last; i++){
        if(X == PtrL->Data[i])
            index = i;
    }
    if(index != -1){
        for(i = index; i <= PtrL->Last; i++)
            PtrL->Data[i] = PtrL->Data[i+1];
        PtrL->Last--;
    }
    return;
}

List CreateList(List EmptyList, int n){
    int num,i;
    printf("请输入线性表的数据:\n");
    for(i = 1; i <= n; i++){
        scanf("%d",&num);
        Insert(num,i,EmptyList);
    }
    return EmptyList;
}

void PrintList(List MyList){
    int length = MyList->Last + 1;
    for(int i = 0; i < length; i++){
        printf("%d",MyList->Data[i]);
        if(i != length-1)
            printf(" | ");
    }
}

#endif //LINEARLIST_ARRAY_ARRAYIMPL_H
