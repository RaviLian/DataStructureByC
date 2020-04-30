#include<stdio.h>
#include"staticLinkList.h"

/*
*   | 6| h 2 | e 3 | l 4 | l 5 | o 0|
*    0    1     2     3     4     5
*/
int main() {

  StaticLinkList sll;
  InitList(sll);
  sll[0].cur = 6;
  sll[5].cur = 0;
  sll[1].data = 'h';
  sll[2].data = 'e';
  sll[3].data = 'l';
  sll[4].data = 'l';
  sll[5].data = 'o';
  
  return 0;
}