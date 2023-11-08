#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <time.h>
#define NoInfo 0         /* 用0表示没有结点 */
#define MAX_SIZE 30

//二叉树数据结构
typedef struct TNode *PositionT;
typedef PositionT BinTree; /* 二叉树类型 */
struct TNode{ /* 树结点定义 */
	int Data; /* 结点数据 */
	BinTree Left;     /* 指向左子树 */
	BinTree Right;    /* 指向右子树 */
}; 
typedef BinTree ElementType; 

//二叉树操作
void InorderTraversal( BinTree BT ); 
void PreorderTraversal( BinTree BT );
void PostorderTraversal( BinTree BT );
void LevelorderTraversal ( BinTree BT );
BinTree CreatBinTree();

//队列相关数据结构 
typedef struct Node *PtrToNode;
struct Node { /* 队列中的结点 */
	ElementType data;
	PtrToNode next;
};
typedef PtrToNode PositionQ;
typedef struct QNode *PtrToQNode;
struct QNode {
	PositionQ front, rear;  /* 队列的头、尾指针 */
	int maxSize;                 /* 队列最大容量 */
};
typedef PtrToQNode Queue;

//队列相关操作 
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
		printf("队列空\n");
		return NULL;
	} else {
		FrontCell = Q->front;
		if ( Q->front == Q->rear ) /* 若队列只有一个元素 */
			Q->front = Q->rear = NULL; /* 删除后队列置为空 */
		else                     
			Q->front = Q->front->next;
		FrontElem = FrontCell->data;
		free( FrontCell );  /* 释放被删除结点空间  */
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
		} else {
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
	
	printf("开始创建二叉树（层次）\n");
	
	/* 建立第1个结点，即根结点 */
	printf("请输入根结点的值："); 
	scanf("%d", &Data);
	if( Data != NoInfo ){
		/* 分配根结点单元，并将结点地址入队 */
		BT = (BinTree)malloc(sizeof(struct TNode));
		BT->Data = Data;
		BT->Left = BT->Right = NULL;
		AddQ( Q, BT );
	}
	else return NULL; /* 若第1个数据就是0，返回空树 */

	while( !IsEmptyQueue(Q) ){
		T = DeleteQ(Q); /* 从队列中取出一结点地址*/
		printf("请输入左孩子的值：");
		scanf("%d", &Data); /* 读入T的左孩子 */
		if( Data == NoInfo ) T->Left = NULL;
		else {  /* 分配新结点，作为出队结点左孩子；新结点入队 */
			T->Left = (BinTree)malloc(sizeof(struct TNode));
			T->Left->Data = Data;
			T->Left->Left = T->Left->Right = NULL;
			AddQ( Q, T->Left );
		}
		printf("请输入右孩子的值：");
		scanf("%d", &Data); /* 读入T的右孩子 */
		if( Data == NoInfo ) T->Right = NULL;
		else {  /* 分配新结点，作为出队结点右孩子；新结点入队 */
			T->Right = (BinTree)malloc(sizeof(struct TNode));
			T->Right->Data = Data;
			T->Right->Left = T->Right->Right = NULL;
			AddQ( Q, T->Right );
		}
	} /* 结束while */
	
	printf("创建二叉树（层次）完成\n");
	
	return BT;
}
