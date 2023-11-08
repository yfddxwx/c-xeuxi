#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef char  ElemType; //��������

//����������ṹ
typedef struct BiTreeNode
{
    ElemType  data; //������
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
    
    printf("�������������˳���¸�������ֵ,#��ʾû�н��:\n");
    CreateBiTree(&T);
    printf("�������������:\n");
    TraverseBiTree(T);
    printf("\n");
    printf("�������������:\n");
    InOrderBiTree(T);
    printf("\n");
    printf("�������������:\n");
    PostOrderBiTree(T);
    printf("\n");

    return 0;
}

//���򴴽�������
void CreateBiTree(BiTree *T)//Ҫ�ı�ָ�룬����Ҫ��ָ��ĵ�ַ������
{
    ElemType ch;

    scanf("%c", &ch);//ע����������
    getchar();//���տո���߻س�
    if (ch == '#')
        *T = NULL;
    else
    {
        *T = (BiTree)malloc(sizeof(BiTreeNode));

        if (!(*T))//����Ƿ����ɹ�
            exit(-1);

        (*T)->data = ch;
        CreateBiTree(&(*T)->l);//printf("����%d�����ӣ�", ch);
        CreateBiTree(&(*T)->r);//printf("����%d���Һ��ӣ�", ch);
    }
}

//�������������
void TraverseBiTree(BiTree T)
{
    if (T == NULL)
        return ;
    printf("%c ", T->data);
    TraverseBiTree(T->l);
    TraverseBiTree(T->r);
}

//�������������
void InOrderBiTree(BiTree T)
{
    if (T == NULL)
        return ;
    InOrderBiTree(T->l);
    printf("%c ", T->data);
    InOrderBiTree(T->r);
}

//�������������
void PostOrderBiTree(BiTree T)
{
    if (T == NULL)
        return ;
    PostOrderBiTree(T->l);
    PostOrderBiTree(T->r);
    printf("%c ", T->data);
}


