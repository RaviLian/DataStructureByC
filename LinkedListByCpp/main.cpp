#include <stdio.h>
#include <stdlib.h>
#include "LinkedListImpl.h"
int main() {
/*    LNode *MyList;
    LNode *Kth;
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    createListT(MyList,a,10);
    PrintList(MyList);//1-->2-->3-->4-->5-->6-->NULL
    //createListH(MyList,a,6);
    //PrintList(MyList);//6-->5-->4-->3-->2-->1-->NULL

    printf("The length of the linked list is %d\n",Length(MyList));//10

    Kth = FindKtn(MyList,3);
    printf("The data of the third LNode is %d\n",Kth->data);

    int flag = FindElem(MyList,7);
    if(flag == 1)
        printf("success find the elem in your list.\n");
    else
        printf("bad request. Not Found.\n");

    Insert(MyList,89,5);
    PrintList(MyList);

    Delete(MyList,15);
    PrintList(MyList);*/
    LNode *ListA,*ListB,*Merge;
    int arr[5] = {17, 23, 44, 48, 59};
    int brr[7] = {3, 9, 18, 27, 31, 67, 109};
    createListT(ListA,arr,5);
    createListT(ListB,brr,7);
    //IncrementalMerge(ListA,ListB,Merge);
    DecreasingMerge(ListA,ListB,Merge);
    PrintList(Merge);
    PrintList(ListA);
    PrintList(ListB);
    return 0;
}

void DecreasingMerge(LNode *A, LNode *B, LNode *&C){
    LNode *p = A->next;
    LNode *q = B->next;
    LNode *s;
    C = A;
    C->next = NULL;
    while (p != NULL && q != NULL){
        if(p->data <= q->data){
            s = p;
            p = p->next;
            s->next = C->next;
            C->next = s;
        } else{
            s = q;
            q = q->next;
            s->next = C->next;
            C->next = s;
        }
    }
    while(p != NULL){
        s = p;
        p = p->next;
        s->next = C->next;
        C->next = s;
    }
    while (q != NULL){
        s = q;
        q = q->next;
        s->next = C->next;
        C->next = s;
    }
}

void IncrementalMerge(LNode *A, LNode *B, LNode *&C){
    //Pointer p tracks the smallest element node of linked list A
    LNode *p = A->next;
    //Pointer q tracks the smallest element node of linked list B
    LNode *q = B->next;
    //Pointer r tracks the end node of linked list C
    LNode *r;
    //Use the head node of linked list A as the head node of linked list C
    C = A;
    C->next = NULL;
    r = C;
    /***
     * Embodies the idea of tail insertion
     */
    while(p != NULL && q != NULL){
        if(p->data <= q->data){
            r->next = p;
            p = p->next;
            r = r->next;
        } else{
            r->next = q;
            q = q->next;
            r = r->next;
        }
    }
    r->next = NULL;
    /***
     * The linked list with remaining nodes should link to the end of C
     */
    if(p != NULL)
        r->next = p;
    if(q != NULL)
        r->next = q;
}

void createListT(LNode *&C,int a[],int n)
{   //s points to the newly applied node
    //r always points to the end node
    LNode *s, *r;
    int i;
    //Apply for the head node space of C
    C = (LNode *)malloc(sizeof(LNode));
    C->next = NULL;
    //r points to the head node. At this time, the head node is the end node
    r = C;
    //Loop application for n nodes to receive the elements in array a
    for(i = 0; i < n; ++i)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = a[i];
        r->next = s; //r points to the new node
        r = r->next; //r points to the end node to receive the next coming node
    }
    r->next = NULL;//End node points to NULL
}//end Create

void createListH(LNode *&C,int a[],int n){
    LNode *s;
    int i;
    C = (LNode *)malloc(sizeof(LNode));
    C->next = NULL;
    for(i = 0; i < n; i++){
        s = (LNode *)malloc(sizeof(LNode));
        s->data = a[i];
        s->next = C->next;
        C->next = s;
    }
}

void PrintList(LNode *&C){
    LNode *s = C;
    while (s->next != NULL) {
        s = s->next;
        printf("%d-->", s->data);
    }
    printf("NULL\n");
}

int Length(LNode *C){
    int len = 0;
    LNode *s = C;
    while (s->next != NULL){
        s = s->next;
        len++;
    }
    return len;
}

LNode* FindKtn(LNode *C, int k){
    int i = 0;
    LNode *s = C;
    while(s != NULL && i < k){
        s = s->next;
        i++;
    }
    if(i == k) return s;
    else return NULL;
}

int FindElem(LNode *C,int elem){
    LNode *s = C;
    while (s != NULL && s->data!=elem){
        s = s->next;
    }
    if(s != NULL)
        return 1;
    else
        return 0;
}

void Insert(LNode *&C, int elem, int pos){
    LNode *s;
    LNode *p;
    p = FindKtn(C,pos-1);
    if(p == NULL){
        printf("can not find the position.\n");
        return;
    } else{
        s = (LNode*)malloc(sizeof(LNode));
        s->data = elem;
        s->next = p->next;
        p->next = s;
        return;
    }
}

void Delete(LNode *&C, int pos){
    LNode *p,*s;
    p = FindKtn(C,pos-1);
    if(p == NULL){
        printf("Wrong location\n");
        return;
    } else if(p->next == NULL){
        printf("Node does not exist\n");
        return;
    } else{
        s = p->next;
        p->next = s->next;
        free(s);
        return;
    }
}