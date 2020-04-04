#include <stdio.h>
#include <stdlib.h>
#include "LinkedListImpl.h"
int main() {
    LNode *MyList;
    int a[6] = {1,2,3,4,5,6};
    createListT(MyList,a,6);
    PrintList(MyList);
    return 0;
}
void createListT(LNode *&C,int a[],int n)
{
    LNode *s, *r;
    int i;
    C = (LNode *)malloc(sizeof(LNode));
    C->next = NULL;
    r = C;
    for(i = 0; i < n; ++i)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = a[i];
        r->next = s;
        r = r->next;
    }
    r->next = NULL;
}

void PrintList(LNode *&C){
    while (C->next != NULL) {
        C = C->next;
        printf("%d-->", C->data);
    }
    printf("NULL");
}
