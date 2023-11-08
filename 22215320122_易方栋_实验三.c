#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <time.h>
#define NoInfo 0         /* 用0表示没有结点 */
#define MAX_SIZE 30

//二叉树数据结构
typedef struct TNode* PositionT;
typedef PositionT BinTree; /* 二叉树类型 */
struct TNode { /* 树结点定义 */
	int Data; /* 结点数据 */
	BinTree left;     /* 指向左子树 */
	BinTree Right;    /* 指向右子树 */ 
};
typedef BinTree ElementType;
//队列相关数据结构 
typedef struct Node* PtrToNode;
struct Node { /* 队列中的结点 */
	ElementType data;
	PtrToNode next;
};
typedef PtrToNode PositionQ;
typedef struct QNode* PtrToQNode;
struct QNode {
	PositionQ front, rear;  /* 队列的头、尾指针 */
	int maxSize;                 /* 队列最大容量 */
};
typedef PtrToQNode Queue;


//二叉树操作
void InorderTraversal(BinTree BT);//中序遍历
void PreorderTraversal(BinTree BT);//先序遍历
void PostorderTraversal(BinTree BT);//后序遍历
void LevelorderTraversal(BinTree BT);//层序遍历
BinTree CreatBinTree();

//队列相关操作 
bool IsEmptyQueue(Queue Q);//队列判空函数
ElementType DeleteQ(Queue Q);//出队函数
Queue CreateQueue(int maxSize);//创建队列函数
bool IsFullQueue(Queue Q);//队列判满函数
bool AddQ(Queue Q, ElementType X);//入队函数

int main() {
	BinTree BT = CreatBinTree();
	printf("先序遍历结果\n");
	PreorderTraversal(BT);
	printf("\n");
	printf("中序遍历结果\n");
	InorderTraversal(BT);
	printf("\n");
	printf("后序遍历结果\n");
	PostorderTraversal(BT);
	printf("\n");
	printf("层序遍历结果\n");
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
		printf("队列空\n");
		return NULL;
	}
	else {
		FrontCell = Q->front;
		if (Q->front == Q->rear) /* 若队列只有一个元素 */
        Q->front = Q->rear = NULL; /* 删除后队列置为空 */
		else
		Q->front = Q->front->next;
		FrontElem = FrontCell->data;
		free(FrontCell);  /* 释放被删除结点空间  */
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
		printf("队列满\n");
		return false;
	}
	else {
		PositionQ newNode = (PositionQ)malloc(sizeof(struct Node));
		newNode->data = X;
		newNode->next = NULL;
		if (Q->front == NULL) {
			//整体为空
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
 * 二叉树的创建
 */
BinTree CreatBinTree()
{
	int Data;
	BinTree BT, T;
	Queue Q = CreateQueue(MAX_SIZE); /* 创建空队列 */

	/* 建立第1个结点，即根结点 */
	scanf_s("%d", &Data);//1.填入相应的语句
	if (Data != NoInfo) {
		/* 分配根结点单元，并将结点地址入队 */
		BT = (BinTree)malloc(sizeof(struct TNode));
		BT->Data = Data;
		BT->left = BT->Right = NULL;//2.填入相应的语句 
		AddQ(Q, BT);
	}
	else return NULL; /* 若第1个数据就是0，返回空树 */

	while (!IsEmptyQueue(Q)) {
		T = DeleteQ(Q); /* 从队列中取出一结点地址*/
		scanf_s("%d", &Data); /* 读入T的左孩子 */
		if (Data == NULL) T->left = NULL; //3.填入判断条件 
		else {  /* 分配新结点，作为出队结点左孩子；新结点入队 */
			T->left = (BinTree)malloc(sizeof(struct TNode));
			T->left->Data = Data;
			T->left->left = T->left->Right = NULL;//4.填入相应语句 
			AddQ(Q, T->left);
		}
		scanf_s("%d", &Data); /* 读入T的右孩子 */
		if (Data == NoInfo) T->Right = NULL;
		else {  /* 分配新结点，作为出队结点右孩子；新结点入队 */
			T->Right = (BinTree)malloc(sizeof(struct TNode));
			T->Right->Data = Data;
			T->Right->left=T->Right->Right=NULL;//5.填入相应语句
			AddQ(Q, T->Right);
		}
	} /* 结束while */


	return BT;
}
void PreorderTraversal(BinTree BT){
	if (BT != NULL) {
		printf("%d", BT->Data);
		PreorderTraversal(BT->left);
		PreorderTraversal(BT->Right);
	}
	else return;
}//先序遍历

void InorderTraversal(BinTree BT) {
	if (BT != NULL) {
		InorderTraversal(BT->left);
		printf("%d", BT->Data);
		InorderTraversal(BT->Right);
	}
}//中序遍历

void PostorderTraversal(BinTree BT) {
	if (BT != NULL) {
		PostorderTraversal(BT->left);
		PostorderTraversal(BT->Right);
		printf("%d", BT->Data);
	}
}//后序遍历

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
}//层序遍历
