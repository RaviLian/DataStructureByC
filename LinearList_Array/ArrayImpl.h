//
// Created by RaviLian on 2020/3/29.
//
#include <stdlib.h>
#ifndef LINEARLIST_ARRAY_ARRAYIMPL_H
#define LINEARLIST_ARRAY_ARRAYIMPL_H
#define MAXSIZE 100

struct LNode{
    int Data[MAXSIZE];
    int Last;  //���������±�
};

typedef struct LNode *List;


//1.��ʼ���������յ�˳���
List MakeEmpty(){
    List PtrL;
    PtrL = (List)malloc(sizeof(struct LNode));
    PtrL->Last = -1;
    return PtrL;
}

//2.����
int Find(int X, List PtrL){
    int i = 0;
    while(i <= PtrL->Last && X != PtrL->Data[i])
        i++;
    if(i > PtrL->Last)
        return -1;     //���û�ҵ��ͷ���-1
    else
        return i;     //����ҵ��� �����±�
}

//3.���루�ڵ�i��1<i<n+1����λ���ϲ���һ��ֵΪX��Ԫ�أ�
void Insert(int X, int i, List PtrL)
{
    int j;
    if(PtrL->Last == MAXSIZE-1){	/*��ռ����������ܲ���*/
        printf("����");
        return;
    }
    if(i < 1 || i > PtrL->Last+2){	/*������λ�õĺϷ���*/
        printf("λ�ò��Ϸ�");
        return;
    }
    for(j = PtrL->Last; j >= i-1; j--){/*��ai��an��������ƶ�*/
        PtrL->Data[j+1] = PtrL->Data[j];
    }
    PtrL->Data[i-1] = X;	/*������Ԫ��*/
    PtrL->Last++;			/*��Lastָ�����һ��Ԫ��*/
    return;
}

void DeleteByPos(int i, List PtrL)	/*iʵ�������±�+1*/
{
    int j;
    if(i < 1 || i > PtrL->Last+1){
        printf("�����ڵ�%d��Ԫ��",i);	/*���ɾ��λ�õĺϷ���*/
        return;
    }
    for(j = i; j <= PtrL->Last; j++)
        PtrL->Data[j-1] = PtrL->Data[j];	/*ai+1��an��ǰŲ*/
    PtrL->Last--;							/*������λ�õĺϷ���*/
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
    printf("���������Ա������:\n");
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
