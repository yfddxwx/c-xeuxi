#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
}; 

typedef struct node* List;

void insert_tail(int value, struct node *p1) {
	//1.�����µĵ㣬�洢value 
	struct node *new_node = (struct node *) malloc(sizeof(struct node));
	new_node->data = value;
	new_node->next = NULL; // ���һ�������������������� 
	
	//2.�ҵ����һ����
	struct node *cur = p1;
	while (cur->next != NULL) {// ͣ�µ�ʱ�̣�cur->next == NULL�����һ������� 
		cur = cur->next;
	} 
	//��72�����λ��,curָ�����һ���ڵ㣬��仰���𣿶� 
	 
	//3.�µĵ�������ĵ���� 
	cur->next = new_node;
}

void print(struct node *p1) {
	struct node *cur = p1;
	while (cur != NULL) {
		printf("%d -> ", cur->data);
		cur = cur->next; // ��ǰ��������ˣ�������һ���� 
	}
	printf("X\n");
}

//��������ƴ�ӳ��µ��������Ƶ���ʽ

//��������ƴ�ӳ�һ�����������ǽ��� 
List merge(List p1, List p2) {
	if (p1 == NULL) {
		return p2;
	}
	if (p2 == NULL) {
		return p1;
	}
	// p1��p2����Ϊ��
	
	// p3���洢���ݣ�ֻ��Ϊ�˱�� 
	List p3 = (List) malloc(sizeof(struct node));
	p3->next = NULL;
	
	List cur = p3;
	int count = 1;
	while (p1 != NULL && p2 != NULL) {
		if (count % 2 == 1) {
			cur->next = p1;
			p1 = p1->next;	
		} else {
			cur->next = p2;
			p2 = p2->next;
		}
		cur = cur->next;
		count++;
	}
	
	//����67�У�������һ������Ϊ��
	cur->next = p1 == NULL ? p2 : p1;
	return p3->next; 
} 


int main() {
	struct node *p1 = (struct node *) malloc(sizeof(struct node));
	p1->data = 100;
	p1->next = NULL; 
	
	struct node *p2 = (struct node *) malloc(sizeof(struct node));
	p2->data = 10;
	p2->next = NULL;
	
	insert_tail(400, p1);
	insert_tail(300, p1);
	insert_tail(500, p1);
	
	insert_tail(40, p2);
	insert_tail(30, p2);
	insert_tail(50, p2);
	insert_tail(60, p2);
	
	print(p1);
	print(p2);
	
	//����merge����
	p1 = merge(p1, p2); 
	print(p1);
	
	
	
	return 0;
}

