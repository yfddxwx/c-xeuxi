//(无头结点)链队：初始化 
#include <stdio.h>
#include <malloc.h>

typedef int ElementType;

typedef struct Node * Position;//结构指针 (队列结点)
struct Node{//队列中的结点 
	ElementType Data;//数据域 
	Position Next;//指针域 
}; 
typedef struct QNode * Queue; //结构指针 
struct QNode{
	Position Front,Rear;
	ElementType Maxsize;
}; 

Queue CreateQueue();
int IsEmpty(Queue Q );
void AddQ(Queue Q,ElementType X); 
ElementType DeleteQ(Queue Q); 

int main(){
	 int n,j;
	 ElementType data;
	 
	 Queue Q = CreateQueue(); 	
	
	 printf("将N个元素依次入队，请输入入队元素的个数：");
	 scanf("%d",&n);
	 for(j = 1;j < n+1; j++ ){
	 	printf("请输入入队元素的值：");
	     scanf("%d",&data);
	 	 AddQ(Q,data); 
	 }
	 
	 for(j = 1;j < n+1; j++ ){
	 	ElementType del = DeleteQ( Q); 
	 	if(del != -1) 
	 	printf("出队元素值为：%d\n",del);
	 }
	 
	return 0;
} 

Queue CreateQueue(){

	printf("开始初始化链队\n"); 
	Queue Q = (Queue)malloc(sizeof(struct QNode));
	Q->Front = Q->Rear = NULL;
	Q->Maxsize = 0; 
	printf("初始化链队完成\n");

	return Q;
} 

int IsEmpty(Queue Q ){
	if(Q->Front == NULL && Q->Rear == NULL){
		return 0;
	}else{
		return -1;
	}
}

void AddQ(Queue Q,ElementType X){
	Position TmpCell = (Position)malloc(sizeof(struct Node));
	TmpCell->Data = X;
	TmpCell->Next = NULL;
	printf("入队前，队列中的元素个数为%d\n",Q->Maxsize);
	if(IsEmpty(Q) == 0){
		Q->Front = Q->Rear = TmpCell;	
	}else{
		Q->Rear->Next = TmpCell;
		Q->Rear = TmpCell;
	} 
	Q->Maxsize++;
	printf("入队成功，队列中的元素个数为%d\n",Q->Maxsize);
}

ElementType DeleteQ(Queue Q){
	if(IsEmpty(Q) == 0){//队列是否为空 
		printf("队列为空，出队失败\n");
		return -1;
	}else if(Q->Front->Next == NULL && Q->Rear->Next == NULL){//队列中是否只有一个结点 
		Position FirstCell = Q->Front;
		Q->Front == NULL;
		Q->Rear == NULL;
		ElementType X = FirstCell->Data;
		free(FirstCell);
		Q->Maxsize--;
		printf("出队后，队列元素的个数为%d\n",Q->Maxsize);
		return X;
	}else{
		Position FirstCell = Q->Front;
		Q->Front = FirstCell->Next;
		ElementType X = FirstCell->Data;
		free(FirstCell);
		Q->Maxsize--;
		printf("出队后，队列元素的个数为%d\n",Q->Maxsize);
		return X; 
	} 
	
}
