#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef char  ElemType; //数据类型

//定义二叉树结构
typedef struct BiTreeNode
{
    ElemType  data; //数据域
    struct BiTreeNode *l;
    struct BiTreeNode *r;
} BiTreeNode, *BiTree;
void CreateBiTree(BiTree *T);
void TraverseBiTree(BiTree T);
void InOrderBiTree(BiTree T); 
void PostOrderBiTree(BiTree T);

int main(void)
{
    BiTree T;
    
    printf("请输入先序遍历顺序下各个结点的值,#表示没有结点:\n");
    CreateBiTree(&T);
    printf("先序遍历二叉树:\n");
    TraverseBiTree(T);
    printf("\n");
    printf("中序遍历二叉树:\n");
    InOrderBiTree(T);
    printf("\n");
    printf("后序遍历二叉树:\n");
    PostOrderBiTree(T);
    printf("\n");

    return 0;
}

//先序创建二叉树
void CreateBiTree(BiTree *T)//要改变指针，所以要把指针的地址传进来
{
    ElemType ch;

    scanf("%c", &ch);//注意数据类型
    getchar();//吸收空格或者回车
    if (ch == '#')
        *T = NULL;
    else
    {
        *T = (BiTree)malloc(sizeof(BiTreeNode));

        if (!(*T))//检查是否分配成功
            exit(-1);

        (*T)->data = ch;
        CreateBiTree(&(*T)->l);//printf("输入%d的左孩子：", ch);
        CreateBiTree(&(*T)->r);//printf("输入%d的右孩子：", ch);
    }
}

//先序遍历二叉树
void TraverseBiTree(BiTree T)
{
    if (T == NULL)
        return ;
    printf("%c ", T->data);
    TraverseBiTree(T->l);
    TraverseBiTree(T->r);
}

//中序遍历二叉树
void InOrderBiTree(BiTree T)
{
    if (T == NULL)
        return ;
    InOrderBiTree(T->l);
    printf("%c ", T->data);
    InOrderBiTree(T->r);
}

//后序遍历二叉树
void PostOrderBiTree(BiTree T)
{
    if (T == NULL)
        return ;
    PostOrderBiTree(T->l);
    PostOrderBiTree(T->r);
    printf("%c ", T->data);
}


