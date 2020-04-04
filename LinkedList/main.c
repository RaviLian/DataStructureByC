#include <stdio.h>
#include <stdlib.h>
#include "LinkedListImpl.h"
int main() {
    int arr[6] = {1, 2, 3, 4, 5, 6};
    LNode *MyLink;
    MyLink = createListT(arr,6);
    //PrintList(MyLink);
    return 0;
}

LNode* createListT(int a[],int n)
{
    LNode *head, *node, *end;
    head = (LNode *)malloc(sizeof(LNode));
    head->next = NULL;
    end = head;
    for (int i = 0; i < n; i++) {
        node = (LNode *)malloc(sizeof(LNode));
        node->data = a[i];
        end->next = node;
        end = node;
    }
    end->next = NULL;
    return head;
}

//void PrintList(LNode *head){
//    while(head->next != NULL){
//        printf("%d-->",head->data);
//    }
//    printf("NULL\n");
//}