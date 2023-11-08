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
 BinTree Left;     /* 指向左子树 */
 BinTree Right;    /* 指向右子树 */
};
typedef BinTree ElementType;

//二叉树操作
void InorderTraversal(BinTree BT);//中序遍历
void PreorderTraversal(BinTree BT);//先序遍历
void PostorderTraversal(BinTree BT);//后序遍历
void LevelorderTraversal(BinTree BT);//层序遍历
BinTree CreatBinTree();


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
