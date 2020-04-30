//
// Created by RaviLian on 2020/4/9.
//
#ifndef STATICLINKLIST_STATICLINKLIST_H
#define STATICLINKLIST_STATICLINKLIST_H

#define MAXSIZE 1000

typedef struct 
{
  char data;
  int cur; //游标，相当于单链表中的next指针，为0时表示无指向
}Component, StaticLinkList[MAXSIZE];

int InitList (StaticLinkList space) {
  int i;
  for (i = 0; i < MAXSIZE-1; i++) {
    space[i].cur = i + 1;
  }
  space[MAXSIZE - 1].cur = 0; //静态链表为空，最后一个元素的cur为0
  return 1;
}

//若备用空间链表非空，则返回分配的结点下标，否则返回0
int Malloc_SLL (StaticLinkList space) {
  int i = space[0].cur; //保存当前数组第一个元素的cur游标值

  if (space[0].cur)
    space[0].cur = space[i].cur; //该空间被拿去使用，这时cur就前进1位

  return i;
}

int ListLength (StaticLinkList L) {
  int j = 0;
  int i = L[MAXSIZE-1].cur;
  while (i)
  {
    i = L[i].cur;
    j++;
  }
  return j;
}

//在L中第pos个元素之前插入新的数据元素e
int ListInsert (StaticLinkList L, int pos, char e) {
  int loca, preloca, i;
  preloca = MAXSIZE - 1;

  if (pos < 1 || pos > ListLength(L) + 1)
    return -1;
  
  loca = Malloc_SLL(L); //获得空闲分量的下标

  if(loca) {
    L[loca].data = e;
    for (i = 1; i <= pos-1; i++) {
      preloca = L[i].cur;//插入位置前元素的游标值，相当于next
    }

    L[loca].cur = L[preloca].cur; //先取到需要插入位置前的元素的游标给插入元素，相当于前一结点的next赋给新结点
    L[preloca].cur = loca; //前一结点的next此时再指向新结点

    return 1;
  }
  return -1;
}


#endif