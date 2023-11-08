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
	printf("==============压入数据==============\n");
	 for(i = 1;i <= 15;i++){
	 	 printf("请输入要入栈元素的值\n");
	     scanf("%d",&data);
	 	 Push(S,data);
     }
	printf("==============取出数据==============\n");
	  for(i = 1;i <= 15;i++){
	 	 pop(S);
	 	 printf("\n"); 
     } 
     
	return 0;
} 

Stack CreatStack(){
	 printf("==========开始初始化顺序栈==========\n");
	 Stack S = (Stack)malloc(sizeof(struct SNode));
	 S->Top = -1;
	 printf(" S->Top的值为：%d\n",S->Top);
	 printf("==========初始化顺序栈结束==========\n");
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
		printf("堆栈已满，入栈失败\n");
 	 }else{
		S->Top++;
		S->data[S->Top] = X;
		 printf("入栈成功\n");  
	}
}

void pop(Stack S){
	if(IsEmpty(S) == 0){
		printf("堆栈已空，出栈失败");
 	 }else{
		 abc X =S->data[S->Top]; 
		 printf("栈顶元素的值为：%d",X);
		 S->Top--;
		   
	}

}
