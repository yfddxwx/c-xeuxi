//(��ͷ���)���ӣ���ʼ�� 
#include <stdio.h>
#include <malloc.h>

typedef int ElementType;

typedef struct Node * Position;//�ṹָ�� (���н��)
struct Node{//�����еĽ�� 
	ElementType Data;//������ 
	Position Next;//ָ���� 
}; 
typedef struct QNode * Queue; //�ṹָ�� 
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
	
	 printf("��N��Ԫ��������ӣ����������Ԫ�صĸ�����");
	 scanf("%d",&n);
	 for(j = 1;j < n+1; j++ ){
	 	printf("���������Ԫ�ص�ֵ��");
	     scanf("%d",&data);
	 	 AddQ(Q,data); 
	 }
	 
	 for(j = 1;j < n+1; j++ ){
	 	ElementType del = DeleteQ( Q); 
	 	if(del != -1) 
	 	printf("����Ԫ��ֵΪ��%d\n",del);
	 }
	 
	return 0;
} 

Queue CreateQueue(){

	printf("��ʼ��ʼ������\n"); 
	Queue Q = (Queue)malloc(sizeof(struct QNode));
	Q->Front = Q->Rear = NULL;
	Q->Maxsize = 0; 
	printf("��ʼ���������\n");

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
	printf("���ǰ�������е�Ԫ�ظ���Ϊ%d\n",Q->Maxsize);
	if(IsEmpty(Q) == 0){
		Q->Front = Q->Rear = TmpCell;	
	}else{
		Q->Rear->Next = TmpCell;
		Q->Rear = TmpCell;
	} 
	Q->Maxsize++;
	printf("��ӳɹ��������е�Ԫ�ظ���Ϊ%d\n",Q->Maxsize);
}

ElementType DeleteQ(Queue Q){
	if(IsEmpty(Q) == 0){//�����Ƿ�Ϊ�� 
		printf("����Ϊ�գ�����ʧ��\n");
		return -1;
	}else if(Q->Front->Next == NULL && Q->Rear->Next == NULL){//�������Ƿ�ֻ��һ����� 
		Position FirstCell = Q->Front;
		Q->Front == NULL;
		Q->Rear == NULL;
		ElementType X = FirstCell->Data;
		free(FirstCell);
		Q->Maxsize--;
		printf("���Ӻ󣬶���Ԫ�صĸ���Ϊ%d\n",Q->Maxsize);
		return X;
	}else{
		Position FirstCell = Q->Front;
		Q->Front = FirstCell->Next;
		ElementType X = FirstCell->Data;
		free(FirstCell);
		Q->Maxsize--;
		printf("���Ӻ󣬶���Ԫ�صĸ���Ϊ%d\n",Q->Maxsize);
		return X; 
	} 
	
}
