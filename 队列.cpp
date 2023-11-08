#include <stdio.h>
#include <stdlib.h> 

#define SIZE 5

void printQueue(int *arr, int front, int rear){
	
	if(front == rear){
		printf("\n队列为空!\n\n");
	}else{
		printf("队列中元素如下:\n");
		int i;
		if(front < rear){
			for(i=front; i<rear; i++, i = i % SIZE){
				printf("%d\t",arr[i]);
			}
		}else{
			for(i=front; i<SIZE; i++){
				printf("%d\t",arr[i]);
			}
			for(i=0; i<rear; i++){
				printf("%d\t",arr[i]);
			}
		}
		printf("\n\n");
	}
}

int enQueue(int *arr, int front, int rear, int data){
	if((rear+1)%SIZE == front){
		printf("\n队列已满!\n\n");
		printQueue(arr,front,rear);
		return rear;
	}
	arr[rear%SIZE] = data;
	rear++;
	rear = rear%SIZE;
	printQueue(arr,front,rear);
	
	return rear;
}

int deQueue(int *arr, int front, int rear){
	if(front == rear){
		printf("\n队列为空!\n\n");
		return front;
	}
	front++;
	front = front % SIZE;
	printQueue(arr,front,rear);
	
	return front;
}

// 将队列置空
int destroyQueue(int front, int rear){
	rear = front;
	return rear;
}

void printMenu(){
	
	printf("\n1.入队\n");
	printf("2.出队\n");
	printf("3.打印队列\n");
	printf("4.置空队列\n");
	printf("0.退出\n");
	printf("请选择：");
}

int main(){
	int arr[SIZE];
	int front = 0,rear = 0;
	char choice;
	int data;
	
	do{
		printMenu();
		choice = getch();
		switch(choice){
			case '1':
				printf("\n请输入要插入的数据:");
				scanf("%d",&data);
				rear = enQueue(arr,front,rear,data);			
				break;
			case '2':
				front = deQueue(arr,front,rear);
				break;
			case '3':
				printQueue(arr,front,rear);
				break;
			case '4':
				rear = destroyQueue(front,rear);
				printQueue(arr,front,rear);
				break;
			
		}
	}while(choice != '0');
	
	return 0;
}


