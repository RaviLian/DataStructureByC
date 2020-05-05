#include <stdio.h>
#include <stdlib.h>
/*
  二叉搜索树，可以为空，如果不空，应该满足以下性质：
  非空左子树所有键值小于其根节点的键值，非空右子树所有键值大于其根节点的键值
  左右子树都是二叉搜索树
*/
typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode
{
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

void PreorderTraversal(BinTree BT);
void InorderTraversal(BinTree BT);

BinTree Insert(BinTree BST, ElementType X);
BinTree Delete(BinTree BST, ElementType X);
Position Find(BinTree BST, ElementType X);
Position FindMin(BinTree BST);
Position FindMax(BinTree BST);

int main()
{
	BinTree BST, MinP, MaxP, Tmp;
	ElementType X;
	int N, i;

	BST = NULL;
	scanf("%d", &N);
	for (i = 0; i<N; i++) {
		scanf("%d", &X);
		BST = Insert(BST, X);
	}
	printf("Preorder:"); PreorderTraversal(BST); printf("\n");
	MinP = FindMin(BST);
	MaxP = FindMax(BST);
	scanf("%d", &N);
	for (i = 0; i<N; i++) {
		scanf("%d", &X);
		Tmp = Find(BST, X);
		if (Tmp == NULL) printf("%d is not found\n", X);
		else {
			printf("%d is found\n", Tmp->Data);
			if (Tmp == MinP) printf("%d is the smallest key\n", Tmp->Data);
			if (Tmp == MaxP) printf("%d is the largest key\n", Tmp->Data);
		}
	}
	scanf("%d", &N);
	for (i = 0; i<N; i++) {
		scanf("%d", &X);
		BST = Delete(BST, X);
	}
	printf("Inorder:"); InorderTraversal(BST); printf("\n");

	return 0;
}

/*--------将X插入二叉搜索树BST并返回结果树的根结点指针-------*/
BinTree Insert(BinTree BST, ElementType X)
{
	if (!BST)
	{
		BST = (BinTree)malloc(sizeof(struct TNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	}
	else
	{
		if (X < BST->Data)
		{
			BST->Left = Insert(BST->Left, X);
		}
		else if (X > BST->Data)
		{
			BST->Right = Insert(BST->Right, X);
		}
	}
	return BST;
}

Position Find(BinTree BST, ElementType X)
{
	while (BST)
	{
		if (X > BST->Data)
		{
			BST = BST->Right;
		}
		else if (X < BST->Data)
		{
			BST = BST->Left;
		}
		else
		{
			return BST;
		}
	}
	return NULL;
}

Position FindMin(BinTree BST)
{
	while (BST)
	{
		if (!BST->Left)
		{
			return BST;
		}
		else
		{
			BST = BST->Left;
		}
	}
	return NULL;
}

Position FindMax(BinTree BST)
{
	while (BST)
	{
		if (!BST->Right)
		{
			return BST;
		}
		else
		{
			BST = BST->Right;
		}
	}
	return NULL;
}

BinTree Delete(BinTree BST, ElementType X)
{
	Position Tmp;
	if (!BST)
	{
		printf("Not Found\n");
	}
	else if (X < BST->Data)
	{
		BST->Left = Delete(BST->Left, X);   // 递归删除左子树
	}
	else if (X > BST->Data)
	{
		BST->Right = Delete(BST->Right, X); // 递归删除右子树
	}
	// 找到要删除的节点
	else
	{
		// 如果被删除节点有子数，寻找下一个节点填充删除节点
		if (BST->Left && BST->Right)
		{
			Tmp = FindMin(BST->Right);  // 在被删除节点的右子数中找最小的元素填充删除节点
			BST->Data = Tmp->Data;
			BST->Right = Delete(BST->Right, BST->Data);  // 递归删除右子树最大值
		}
		else
		{
			// 如果被删除结点有一个或者没有儿子
			Tmp = BST;
			if (!BST->Left)
			{
				BST = BST->Right;   // 如果这个子数没有左儿子，将右儿子的指针赋给它，Free它
			}
			else if (!BST->Right)
			{
				BST = BST->Left;   // 如果这个子数没有右儿子，将左儿子的指针赋给它，Free它
			}
			free(Tmp);             // 这两种写法已经包括了有一个子数
		}
	}
	return BST;
}

void PreorderTraversal(BinTree BT)
{
	if (!BT)
		return;
	printf(" %d", BT->Data);
	PreorderTraversal(BT->Left);
	PreorderTraversal(BT->Right);
}

void InorderTraversal(BinTree BT)
{
	if (!BT)
		return;
	InorderTraversal(BT->Left);
	printf(" %d", BT->Data);
	InorderTraversal(BT->Right);
}
