//
// Created by RaviLian on 2020/4/4.
//

#ifndef LINKEDLISTBYCPP_LINKEDLISTIMPL_H
#define LINKEDLISTBYCPP_LINKEDLISTIMPL_H
/***
 *Linked list with head node
 */
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode;

/***
 * Tail insertion method to build linked list C
 * @param C Reference of linked list C
 * @param a An array of elements inserted into the linked list
 * @param n Number of elements
 */
void createListT(LNode *&C,int a[],int n);

/***
 * Head insertion method to build linked list C
 * @param C Reference of linked list C
 * @param a An array of elements inserted into the linked list
 * @param n Number of elements
 */
void createListH(LNode *&C,int a[],int n);

/***
 * Print linked list
 * @param C
 */
void PrintList(LNode *&C);

/***
 * Get the length of the linked list
 * @param C
 * @return
 */
int Length(LNode *C);

/***
 * Get the pointer of the Kth linked list
 * @param C
 * @param k
 * @return
 */
LNode* FindKtn(LNode *C, int k);

/***
 * Get the pointer to a given linked list element
 * @param C
 * @param elem
 * @return
 */
int FindElem(LNode *C,int elem);

/***
 * Insert a given element into a given position in the linked list
 * @param C
 * @param elem
 * @param pos
 */
void Insert(LNode *&C, int elem, int pos);

/***
 * Delete the element at the given position of the linked list
 * @param C
 * @param pos
 */
void Delete(LNode *&C, int pos);

/***
 * Merge list A and list B to make merged list C incremental and orderly
 * Embodies the idea of tail insertion
 * @param A Ordered list A of increasing elements
 * @param B Ordered list B of increasing elements
 * @param C Incremental and ordered merge list C
 */
void IncrementalMerge(LNode *A, LNode *B, LNode *&C);

/***
 *Merge list A and list B to make merged list C Decreasing and orderly
 * Embodies the idea of head insertion
 * @param A Ordered list A of increasing elements
 * @param B Ordered list B of increasing elements
 * @param C Decreasing and ordered merge list C
 */
void DecreasingMerge(LNode *A, LNode *B, LNode *&C);
#endif //LINKEDLISTBYCPP_LINKEDLISTIMPL_H
