#include <stdio.h>
#include <stdlib.h> 

#define SIZE 5

void printQueue(int *arr, int front, int rear){
	
	if(front == rear){
		printf("\n����Ϊ��!\n\n");
	}else{
		printf("������Ԫ������:\n");
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
		printf("\n��������!\n\n");
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
		printf("\n����Ϊ��!\n\n");
		return front;
	}
	front++;
	front = front % SIZE;
	printQueue(arr,front,rear);
	
	return front;
}

// �������ÿ�
int destroyQueue(int front, int rear){
	rear = front;
	return rear;
}

void printMenu(){
	
	printf("\n1.���\n");
	printf("2.����\n");
	printf("3.��ӡ����\n");
	printf("4.�ÿն���\n");
	printf("0.�˳�\n");
	printf("��ѡ��");
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
				printf("\n������Ҫ���������:");
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


