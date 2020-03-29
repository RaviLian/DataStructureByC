#include <stdio.h>
#include "ArrayImpl.h"
int main() {
    List MyList;
    MyList = MakeEmpty();
    int num,i;
    for(i = 1; i <= 3; i++){
        scanf("%d",&num);
        Insert(num,i,MyList);
    }
    for(i = 0; i < 3; i++){
        printf("%d",MyList->Data[i]);
        if(i != 2)
            printf(" | ");
    }
    return 0;
}
