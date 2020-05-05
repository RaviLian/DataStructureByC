#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct TNode *Position; /* 结构体指针 */
typedef Position BinTree; /* 二叉树类型 */
struct TNode{ /* 树结点定义 */
    ElementType Data; /* 结点数据 */
    BinTree Left;     /* 指向左子树 */
    BinTree Right;    /* 指向右子树 */
}TNode;

//尾递归实现二叉搜索树查找，效率不高，尾递归都可以改为循环迭代实现
Position Find (ElementType x, BinTree BST) {
    if ( !BST ) return NULL; //查找失败
    if ( x > BST->Data ) //x比当前元素大，到右子树去查找
        return Find(x, BST->Right);
    else if ( x < BST->Data) //x比当前元素小，到左子树去查找
        return Find(x, BST->Left);
    else
        return BST; //查找成功
}

//迭代实现查找
//查找效率取决于树的高度
Position iterFind (ElementType x, BinTree BST) {
    while (BST) {
        if ( x > BST->Data ) //x比当前元素大，到右子树去查找
            BST = BST->Right;
        else if ( x < BST->Data) //x比当前元素小，到左子树去查找
            BST = BST->Left;
        else
            return BST; //查找成功
    }
    return NULL;
}

//递归查找最小值
Position FindMin (BinTree BST) {
    if (!BST) return NULL; //空二叉树，返回空
    else if (!BST->Left)
        return BST; //找到最左叶结点，并返回
    else
        return FindMin(BST->Left); //沿着左分支继续查找
}

//迭代查找最大值的位置
Position FindMax (BinTree BST) {
    if (BST) {
        while (BST->Right) { //沿着右分支查找 直到右结点
            BST = BST->Right;
        }
    }
    return BST;
}
/*--------将X插入二叉搜索树BST并返回结果树的根结点指针-------*/
BinTree Insert( BinTree BST, ElementType X )
{
    if( !BST ){ /* 若原树为空，生成并返回一个结点的二叉搜索树 */
        BST = (BinTree)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = BST->Right = NULL;
    }
    else { /* 开始找要插入元素的位置 */
        if( X < BST->Data )
            BST->Left = Insert( BST->Left, X );   /*递归插入左子树*/
        else  if( X > BST->Data )
            BST->Right = Insert( BST->Right, X ); /*递归插入右子树*/
        /* else X已经存在，什么都不做 */
    }
    return BST;
}

/**
 * 考虑三种情况：
 * 1. 删除的是叶子结点，直接删除，再修改其父结点指针指向NULL
 * 2.删除的结点只有一个孩子结点，将指向被删除结点的指针置为指向被删除结点的孩子
 * 3.删除的结点有左右两颗子树：用一个结点替代被删除元素，如右子树的最小元素或左子树的最大元素
 * 特点：右子树的最小元素或左子树的最大元素一定不是有两个儿子
*/
BinTree Delete( BinTree BST, ElementType X )
{
    Position Tmp;

    if( !BST )
        printf("Not Found!");
    else {
        if( X < BST->Data )
            BST->Left = Delete( BST->Left, X );   /* 从左子树递归删除 */
        else if( X > BST->Data )
            BST->Right = Delete( BST->Right, X ); /* 从右子树递归删除 */
        else { /* BST就是要删除的结点 */
            /* 如果被删除结点有左右两个子结点 */
            if( BST->Left && BST->Right ) {
                /* 从右子树中找最小的元素填充删除结点 */
                Tmp = FindMin( BST->Right );
                BST->Data = Tmp->Data;
                /* 从右子树中删除最小元素 */
                BST->Right = Delete( BST->Right, BST->Data );
            }
            else { /* 被删除结点有一个或无子结点 */
                Tmp = BST;
                if( !BST->Left )       /* 只有右孩子或无子结点 */
                    BST = BST->Right;
                else if ( !BST->Right ) /* 只有左孩子 */
                    BST = BST->Left;
                free( Tmp );
            }
        }
    }
    return BST;
}

void PreOrderTraversal ( BinTree BT ) {
    if ( BT ) {
        printf("%-4d", BT->Data);
        PreOrderTraversal( BT->Left );
        PreOrderTraversal( BT->Right );
    }
}

//二叉树中序遍历递归算法
void InOrderTraversal ( BinTree BT ) {
    if ( BT ) {
        InOrderTraversal( BT->Left );
        printf("%-4d", BT->Data);
        InOrderTraversal( BT->Right );
    }
}



int main(int argc, char const *argv[]) {
    //测试数据：
    int a[10] = {5, 8, 6, 2, 4, 1, 0, 10, 9, 7};
    BinTree BST, MinPos, MaxPos, Temp;
    int i;
    BST = NULL;

    for (i = 0; i < 10; i++)
        BST = Insert(BST, a[i]);
    printf("\nPreOrder:\n");
    PreOrderTraversal(BST);
    printf("\nInOrder:\n");
    InOrderTraversal(BST);

    MaxPos = FindMax(BST);
    MinPos = FindMin(BST);
    printf("\nThe Largest number in BST is %d \n",MaxPos->Data);
    printf("\nThe Smallest number in BST is %d \n",MinPos->Data);

    int Y = 6;
    Temp = Find(Y,BST);
    if( Temp == NULL )
        printf("%d is Not Found!\n",Y);
    else
        printf("Find %d!\n",Y);

    int Z = 9;
    BST = Delete(BST,Z);
    printf("\nInOrder:\n");
    InOrderTraversal(BST);
    return 0;
}
