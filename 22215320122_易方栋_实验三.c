#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <time.h>
#define NoInfo 0         /* ��0��ʾû�н�� */
#define MAX_SIZE 30

//���������ݽṹ
typedef struct TNode* PositionT;
typedef PositionT BinTree; /* ���������� */
struct TNode { /* ����㶨�� */
	int Data; /* ������� */
	BinTree left;     /* ָ�������� */
	BinTree Right;    /* ָ�������� */ 
};
typedef BinTree ElementType;
//����������ݽṹ 
typedef struct Node* PtrToNode;
struct Node { /* �����еĽ�� */
	ElementType data;
	PtrToNode next;
};
typedef PtrToNode PositionQ;
typedef struct QNode* PtrToQNode;
struct QNode {
	PositionQ front, rear;  /* ���е�ͷ��βָ�� */
	int maxSize;                 /* ����������� */
};
typedef PtrToQNode Queue;


//����������
void InorderTraversal(BinTree BT);//�������
void PreorderTraversal(BinTree BT);//�������
void PostorderTraversal(BinTree BT);//�������
void LevelorderTraversal(BinTree BT);//�������
BinTree CreatBinTree();

//������ز��� 
bool IsEmptyQueue(Queue Q);//�����пպ���
ElementType DeleteQ(Queue Q);//���Ӻ���
Queue CreateQueue(int maxSize);//�������к���
bool IsFullQueue(Queue Q);//������������
bool AddQ(Queue Q, ElementType X);//��Ӻ���

int main() {
	BinTree BT = CreatBinTree();
	printf("����������\n");
	PreorderTraversal(BT);
	printf("\n");
	printf("����������\n");
	InorderTraversal(BT);
	printf("\n");
	printf("����������\n");
	PostorderTraversal(BT);
	printf("\n");
	printf("����������\n");
	LevelorderTraversal(BT);
	return 0;
}

bool IsEmptyQueue(Queue Q)
{
	return (Q->front == NULL);
}

bool IsFullQueue(Queue Q)
{
	PositionQ p = Q->front;
	int count = 0;
	while (p != NULL) {
		p = p->next;
		count++;
	}
	return count == Q->maxSize;
}

ElementType DeleteQ(Queue Q) {
	PositionQ FrontCell;
	ElementType FrontElem;
	if (IsEmptyQueue(Q)) {
		printf("���п�\n");
		return NULL;
	}
	else {
		FrontCell = Q->front;
		if (Q->front == Q->rear) /* ������ֻ��һ��Ԫ�� */
        Q->front = Q->rear = NULL; /* ɾ���������Ϊ�� */
		else
		Q->front = Q->front->next;
		FrontElem = FrontCell->data;
		free(FrontCell);  /* �ͷű�ɾ�����ռ�  */
		return  FrontElem;
	}
}

Queue CreateQueue(int maxSize)
{
	Queue Q = (Queue)malloc(sizeof(struct QNode));
	Q->front = Q->rear = NULL;
	Q->maxSize = maxSize;
	return Q;
}



bool AddQ(Queue Q, ElementType X)
{
	if (IsFullQueue(Q)) {
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
		}
		else {
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

	/* ������1����㣬������� */
	scanf_s("%d", &Data);//1.������Ӧ�����
	if (Data != NoInfo) {
		/* �������㵥Ԫ����������ַ��� */
		BT = (BinTree)malloc(sizeof(struct TNode));
		BT->Data = Data;
		BT->left = BT->Right = NULL;//2.������Ӧ����� 
		AddQ(Q, BT);
	}
	else return NULL; /* ����1�����ݾ���0�����ؿ��� */

	while (!IsEmptyQueue(Q)) {
		T = DeleteQ(Q); /* �Ӷ�����ȡ��һ����ַ*/
		scanf_s("%d", &Data); /* ����T������ */
		if (Data == NULL) T->left = NULL; //3.�����ж����� 
		else {  /* �����½�㣬��Ϊ���ӽ�����ӣ��½����� */
			T->left = (BinTree)malloc(sizeof(struct TNode));
			T->left->Data = Data;
			T->left->left = T->left->Right = NULL;//4.������Ӧ��� 
			AddQ(Q, T->left);
		}
		scanf_s("%d", &Data); /* ����T���Һ��� */
		if (Data == NoInfo) T->Right = NULL;
		else {  /* �����½�㣬��Ϊ���ӽ���Һ��ӣ��½����� */
			T->Right = (BinTree)malloc(sizeof(struct TNode));
			T->Right->Data = Data;
			T->Right->left=T->Right->Right=NULL;//5.������Ӧ���
			AddQ(Q, T->Right);
		}
	} /* ����while */


	return BT;
}
void PreorderTraversal(BinTree BT){
	if (BT != NULL) {
		printf("%d", BT->Data);
		PreorderTraversal(BT->left);
		PreorderTraversal(BT->Right);
	}
	else return;
}//�������

void InorderTraversal(BinTree BT) {
	if (BT != NULL) {
		InorderTraversal(BT->left);
		printf("%d", BT->Data);
		InorderTraversal(BT->Right);
	}
}//�������

void PostorderTraversal(BinTree BT) {
	if (BT != NULL) {
		PostorderTraversal(BT->left);
		PostorderTraversal(BT->Right);
		printf("%d", BT->Data);
	}
}//�������

void LevelorderTraversal(BinTree BT) {
	Queue Q;
	BinTree T;
	if (!BT) {
		return;
	}
	Q = CreateQueue(MAX_SIZE);
	AddQ(Q, BT);
	while (!IsEmptyQueue(Q)) {
		T = DeleteQ(Q);
		printf("%d", T->Data);
		if (T->left) {
			AddQ(Q, T->left);
		}
		if (T->Right) {
			AddQ(Q, T->Right);
		}
	}
}//�������
