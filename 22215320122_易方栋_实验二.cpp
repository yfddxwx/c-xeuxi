#include <stdio.h>
#include <malloc.h>

#define Maxsize 10

typedef int abc;

typedef struct SNode * Stack;
struct SNode{
	 abc data[Maxsize];
	 int Top;
};


Stack CreatStack();
int IsFull(Stack S); 
int IsEmpty(Stack S);
void Push(Stack S,abc X);
void pop(Stack S); 

int main(){
	 int n,i;
	 abc data;
	 Stack S = CreatStack();
	printf("==============ѹ������==============\n");
	 for(i = 1;i <= 15;i++){
	 	 printf("������Ҫ��ջԪ�ص�ֵ\n");
	     scanf("%d",&data);
	 	 Push(S,data);
     }
	printf("==============ȡ������==============\n");
	  for(i = 1;i <= 15;i++){
	 	 pop(S);
	 	 printf("\n"); 
     } 
     
	return 0;
} 

Stack CreatStack(){
	 printf("==========��ʼ��ʼ��˳��ջ==========\n");
	 Stack S = (Stack)malloc(sizeof(struct SNode));
	 S->Top = -1;
	 printf(" S->Top��ֵΪ��%d\n",S->Top);
	 printf("==========��ʼ��˳��ջ����==========\n");
	 return S;
}

int IsFull(Stack S){
	if(S->Top == Maxsize-1){
		return 0;
	}else{
		return 1;
	} 	
} 

int IsEmpty(Stack S){
	if(S->Top == -1){
		return 0;
	}else{
		return 1;
	} 
}

void Push(Stack S,abc X){
	 if(IsFull(S) == 0){
		printf("��ջ��������ջʧ��\n");
 	 }else{
		S->Top++;
		S->data[S->Top] = X;
		 printf("��ջ�ɹ�\n");  
	}
}

void pop(Stack S){
	if(IsEmpty(S) == 0){
		printf("��ջ�ѿգ���ջʧ��");
 	 }else{
		 abc X =S->data[S->Top]; 
		 printf("ջ��Ԫ�ص�ֵΪ��%d",X);
		 S->Top--;
		   
	}

}
