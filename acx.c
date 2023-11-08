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
 BinTree Left;     /* ָ�������� */
 BinTree Right;    /* ָ�������� */
};
typedef BinTree ElementType;

//����������
void InorderTraversal(BinTree BT);//�������
void PreorderTraversal(BinTree BT);//�������
void PostorderTraversal(BinTree BT);//�������
void LevelorderTraversal(BinTree BT);//�������
BinTree CreatBinTree();


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
