#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <time.h>
#define NoInfo 0         /* ��0��ʾû�н�� */
#define MAX_SIZE 30

//���������ݽṹ
typedef struct TNode *PositionT;
typedef PositionT BinTree; /* ���������� */
struct TNode{ /* ����㶨�� */
	int Data; /* ������� */
	BinTree Left;     /* ָ�������� */
	BinTree Right;    /* ָ�������� */
}; 
typedef BinTree ElementType; 

//����������
void InorderTraversal( BinTree BT ); 
void PreorderTraversal( BinTree BT );
void PostorderTraversal( BinTree BT );
void LevelorderTraversal ( BinTree BT );
BinTree CreatBinTree();

//����������ݽṹ 
typedef struct Node *PtrToNode;
struct Node { /* �����еĽ�� */
	ElementType data;
	PtrToNode next;
};
typedef PtrToNode PositionQ;
typedef struct QNode *PtrToQNode;
struct QNode {
	PositionQ front, rear;  /* ���е�ͷ��βָ�� */
	int maxSize;                 /* ����������� */
};
typedef PtrToQNode Queue;

//������ز��� 
bool IsEmptyQueue( Queue Q ); 
ElementType DeleteQ( Queue Q );
Queue CreateQueue( int maxSize );
bool IsFullQueue( Queue Q );
bool AddQ( Queue Q, ElementType X );

int main() {
	
	BinTree BT = CreatBinTree();


	return 0;
} 

bool IsEmptyQueue( Queue Q )
{
	return ( Q->front == NULL);
}

ElementType DeleteQ( Queue Q ) {
	PositionQ FrontCell; 
	ElementType FrontElem;
	if  ( IsEmptyQueue(Q) ) {
		printf("���п�\n");
		return NULL;
	} else {
		FrontCell = Q->front;
		if ( Q->front == Q->rear ) /* ������ֻ��һ��Ԫ�� */
			Q->front = Q->rear = NULL; /* ɾ���������Ϊ�� */
		else                     
			Q->front = Q->front->next;
		FrontElem = FrontCell->data;
		free( FrontCell );  /* �ͷű�ɾ�����ռ�  */
		return  FrontElem;
	}
}

Queue CreateQueue( int maxSize )
{
	Queue Q = (Queue)malloc(sizeof(struct QNode));
	Q->front = Q->rear = NULL;
	Q->maxSize = maxSize;
	return Q;
}

bool IsFullQueue( Queue Q )
{
	PositionQ p = Q->front;
	int count = 0;
	while (p != NULL) {
		p = p->next;
		count++;
	}
	return count == Q->maxSize;
}

bool AddQ( Queue Q, ElementType X )
{
	if ( IsFullQueue(Q) ) {
		printf("������\n");
		return false;
	}
	else {
		PositionQ newNode = (PositionQ)malloc(sizeof(struct Node));
		newNode->data = X;
		newNode->next = NULL;
		if (Q->front == NULL) {
			//����Ϊ��
			Q->front = newNode;
			Q->rear = newNode; 
		} else {
			Q->rear->next = newNode;
			Q->rear = Q->rear->next;
		}
		return true;
	}
}



/*
 * �������Ĵ���
 */ 
BinTree CreatBinTree()
{
	int Data;
	BinTree BT, T;
	Queue Q = CreateQueue(MAX_SIZE); /* �����ն��� */
	
	printf("��ʼ��������������Σ�\n");
	
	/* ������1����㣬������� */
	printf("�����������ֵ��"); 
	scanf("%d", &Data);
	if( Data != NoInfo ){
		/* �������㵥Ԫ����������ַ��� */
		BT = (BinTree)malloc(sizeof(struct TNode));
		BT->Data = Data;
		BT->Left = BT->Right = NULL;
		AddQ( Q, BT );
	}
	else return NULL; /* ����1�����ݾ���0�����ؿ��� */

	while( !IsEmptyQueue(Q) ){
		T = DeleteQ(Q); /* �Ӷ�����ȡ��һ����ַ*/
		printf("���������ӵ�ֵ��");
		scanf("%d", &Data); /* ����T������ */
		if( Data == NoInfo ) T->Left = NULL;
		else {  /* �����½�㣬��Ϊ���ӽ�����ӣ��½����� */
			T->Left = (BinTree)malloc(sizeof(struct TNode));
			T->Left->Data = Data;
			T->Left->Left = T->Left->Right = NULL;
			AddQ( Q, T->Left );
		}
		printf("�������Һ��ӵ�ֵ��");
		scanf("%d", &Data); /* ����T���Һ��� */
		if( Data == NoInfo ) T->Right = NULL;
		else {  /* �����½�㣬��Ϊ���ӽ���Һ��ӣ��½����� */
			T->Right = (BinTree)malloc(sizeof(struct TNode));
			T->Right->Data = Data;
			T->Right->Left = T->Right->Right = NULL;
			AddQ( Q, T->Right );
		}
	} /* ����while */
	
	printf("��������������Σ����\n");
	
	return BT;
}
