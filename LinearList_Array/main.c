#include <stdio.h>
#include "ArrayImpl.h"
int main() {
    List MyList;
    //初始化线性表
    MyList = MakeEmpty();

    //创建线性表
    CreateList(MyList,5);

    //打印线性表
    PrintList(MyList);

    //查找操作测试
    int X; //保存查找元素
//    printf("\n输入需要查找的元素的值:");
//    scanf("%d",&X);
//    int flag = Find(X,MyList);
//    if(flag == -1){
//        printf("\n该元素不在列表中...\n");
//    } else{
//        printf("\n该元素的在线性表中的位置是:第%d位\n",flag+1);
//    }

    //删除数据
//    printf("\n输入需要删除的元素的位置:");
//    scanf("%d",&X);
//    DeleteByPos(X,MyList);
//    printf("\n");
//    PrintList(MyList);

    //插入数据--表头
    //Insert(123,1,MyList);
    //插入数据--表尾
    //Insert(123,6,MyList);
    //插入数据--中间
//    Insert(123,3,MyList);

//新增按值删除测试
    DeleteByElem(15,MyList);
    printf("\n");
    PrintList(MyList);
    return 0;
}
