#ifndef BINARYTREE_BTREE_H
#define BINARYTREE_BTREE_H


typedef char ElementType;

typedef struct TNode *Position;
typedef Position BinTree; /* 二叉树类型 */
struct TNode{ /* 树结点定义 */
    ElementType Data; /* 结点数据 */
    BinTree Left;     /* 指向左子树 */
    BinTree Right;    /* 指向右子树 */
}TNode;


/**
 * 二叉树的建立，实质建立了扩展二叉树
 * 按照先序输入二叉树结点的数据，#表示空树
 * 前中后序遍历的不同之在于递归的顺序
*/
void CreateBinaryTree ( BinTree *T ) {
    ElementType ch;
    scanf("%c",&ch);

    if (ch == '#')
        *T = NULL;
    else {
        *T = (BinTree)malloc(sizeof(TNode));
        (*T)->Data = ch;
        CreateBinaryTree(&((*T)->Left));
        CreateBinaryTree(&((*T)->Right));
    }
}

/**
 * 二叉树的先中后序遍历中
 * 经过的结点路径是一样的，但是访问各结点的时机不同
 * 每个结点都会被经过三次，第一次经过就printf是先序
 * 同理第二次printf是中序，第三次是后序
 * 堆栈非递归实现是保存左孩子
 * 队列非递归实现是保存右孩子
*/

//二叉树先序遍历递归算法
void PreOrderTraversal ( BinTree BT ) {
    if ( BT ) {
        printf("%c", BT->Data);
        PreOrderTraversal( BT->Left );
        PreOrderTraversal( BT->Right );
    }
}

//二叉树中序遍历递归算法
void InOrderTraversal ( BinTree BT ) {
    if ( BT ) {
        PreOrderTraversal( BT->Left );
        printf("%c", BT->Data);
        PreOrderTraversal( BT->Right );
    }
}

//二叉树后序遍历递归算法
void PostOrderTraversal ( BinTree BT ) {
    if ( BT ) {
        PostOrderTraversal( BT->Left );
        PostOrderTraversal( BT->Right );
        printf("%c", BT->Data);
    }
}

//队列实现
//二叉树层次遍历
void LevelOrderTraversal (BinTree BT);

//求二叉树的叶子结点
void PreOrderPrintLeaves ( BinTree BT ) {
    if ( BT ) {
        if ( !BT->Left && !BT->Right )
            printf("%c", BT->Data);
    PreOrderPrintLeaves( BT->Left );
    PreOrderPrintLeaves( BT->Right );
    }
}

//后序遍历求树的高度
int PostOrderGetHeight ( BinTree BT) {
    int HL, HR, MaxH;

    if ( BT ) {
        HL = PostOrderGetHeight( BT->Left );
        HR = PostOrderGetHeight( BT->Right );
        MaxH = ( HL > HR ) ? HL : HR;
        return (MaxH + 1);
    }
    else
        return 0;
}

//将二叉树复制给另一个树
void CopyBinaryTree ( BinTree BT, BinTree *newBT) {
    if (BT == NULL) {
        *newBT = NULL;
        return;
    }
    else {
        *newBT = (BinTree)malloc(sizeof(TNode));
        ( (*newBT)->Data ) = BT->Data;
        CopyBinaryTree(BT->Left, &((*newBT)->Left));
        CopyBinaryTree(BT->Right, &((*newBT)->Right));
    }
}

//左右子树互换
void ExchangeChilden (BinTree BT) {
    BinTree p;
    if (BT != NULL) {
        p = BT->Left;
        BT->Left = BT->Right;
        BT->Right = p;

        ExchangeChilden(BT->Left);
        ExchangeChilden(BT->Right);
    }
}

#endif //BINARYTREE_BTREE_H