#include <stdio.h>
#include "ArrayImpl.h"
int main() {
    List MyList;
    //��ʼ�����Ա�
    MyList = MakeEmpty();

    //�������Ա�
    CreateList(MyList,5);

    //��ӡ���Ա�
    PrintList(MyList);

    //���Ҳ�������
    int X; //�������Ԫ��
//    printf("\n������Ҫ���ҵ�Ԫ�ص�ֵ:");
//    scanf("%d",&X);
//    int flag = Find(X,MyList);
//    if(flag == -1){
//        printf("\n��Ԫ�ز����б���...\n");
//    } else{
//        printf("\n��Ԫ�ص������Ա��е�λ����:��%dλ\n",flag+1);
//    }

    //ɾ������
//    printf("\n������Ҫɾ����Ԫ�ص�λ��:");
//    scanf("%d",&X);
//    DeleteByPos(X,MyList);
//    printf("\n");
//    PrintList(MyList);

    //��������--��ͷ
    //Insert(123,1,MyList);
    //��������--��β
    //Insert(123,6,MyList);
    //��������--�м�
//    Insert(123,3,MyList);

//������ֵɾ������
    DeleteByElem(15,MyList);
    printf("\n");
    PrintList(MyList);
    return 0;
}
