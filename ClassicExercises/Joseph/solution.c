#include <stdio.h>
#include <stdlib.h>

struct _Node {
	int data;
	struct _Node *next;//自引用结构
};

typedef struct _Node node_t; //typedef ： 给 struct _Node 这个结构体赋予名字 node_t(现在，node_t就类似于int)

typedef struct _Linklist {
	node_t *phead;//指向整个struct _Node结点的指针
	node_t *ptail;
	int len;
} Linklist;

//申请空间并传入数据i
static node_t *GetNode(int i)
{
	node_t *pNode; // pNode 是指向结构体node_t的指针
	pNode = (node_t*) malloc(sizeof(node_t));//给node_t结构体动态分配内存，在malloc成功后返回一个node_t类型的指针
	if (!pNode) {
		printf("Error,the memory is not enough!\n");
		exit(-1);
	}
	pNode->data = i; //指向结构体的指针通过-> 引用结构体成员
	pNode->next = NULL;
	return pNode;
}

// 用第一个节点初始化循环单链表
void init_list(Linklist *plist)
{
	node_t *p;
	p = GetNode(1);
	plist->phead = p;
	plist->ptail = p;	//构造循环链表
	p->next = plist->phead;
	plist->len = 1;
}

// 把其余数据添加到循环单链表中
static void Create_List(Linklist *plist, int n)
{
	int i = 0;
	node_t *pNew;
	for (i = 2; i <= n; i++) {
		pNew = GetNode(i);
		plist->ptail->next = pNew;
		plist->ptail = pNew;
		pNew->next = plist->phead;
		plist->len ++;
	}
	printf("Finish!\n");
}

void Print_List(Linklist *plist)
{
	node_t *pCur = plist->phead;
	do {
		printf("The %d person.\n", pCur->data);
		pCur = pCur->next;
	} while (pCur != plist->phead);
	printf("The length of the List: %d\n", plist->len);
}

//约瑟夫回环函数实现
//时间复杂度O(m*(n-1))
void joseph(Linklist *plist, int m)
{
	node_t *pPre = plist->ptail;
	node_t *pCur = plist->phead;
	int i;
	while (plist->len != 1) { //剩余人数不为1
		i = 0;
		//根据报数最大值m，找到目标指针的前一个指针
		while (i < m - 1) {
			pPre = pPre->next;
			i++;
		}
		//找到目标指针
		pCur = pPre->next;
		//处理pCur指向的结点，输出，并释放
		pPre->next = pCur->next;
		printf("%2d was killed !\n",pCur->data);//打印每次被kill的人
		free(pCur);
		//令循环链表长度减一
		plist->len--;
	}
	printf("The last one is: %d\n", pPre->data);
}

void joseph_num(Linklist *plist, int m, int num)
{
	node_t *pPre = plist->ptail;
	node_t *pCur = plist->phead;
	int i;
	while (plist->len != num) { //剩余人数不为1
		i = 0;
		//根据报数最大值m，找到目标指针的前一个指针
		while (i < m - 1) {
			pPre = pPre->next;
			i++;
		}
		//找到目标指针
		pCur = pPre->next;
		//处理pCur指向的结点，输出，并释放
		pPre->next = pCur->next;
		printf("%2d was killed !\n",pCur->data);//打印每次被kill的人
		free(pCur);
		//令循环链表长度减一
		plist->len--;
	}
	for (i = 0; i < plist->len; i++,pPre = pPre->next){
		printf("The survivor is: %d\n", pPre->data);
	}
}

int main() {
	int m,n;
	printf("Please input the Length of the Circle list: ");
	scanf("%d", &n);
	printf("Please input the Stop point: ");
	scanf("%d", &m);
	Linklist pList;
	init_list(&pList);
	Create_List(&pList, n);
	Print_List(&pList);
	//joseph_num(&pList, m, 2);
	joseph(&pList, m);
	return 0;
}
