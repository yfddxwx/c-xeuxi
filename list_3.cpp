#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
}; 

typedef struct node* List;

void insert_tail(int value, struct node *p1) {
	//1.创建新的点，存储value 
	struct node *new_node = (struct node *) malloc(sizeof(struct node));
	new_node->data = value;
	new_node->next = NULL; // 最后一个，所以我们设置完了 
	
	//2.找到最后一个点
	struct node *cur = p1;
	while (cur->next != NULL) {// 停下的时刻：cur->next == NULL，最后一点才满足 
		cur = cur->next;
	} 
	//在72行这个位置,cur指向最后一个节点，这句话对吗？对 
	 
	//3.新的点插入最后的点后面 
	cur->next = new_node;
}

void print(struct node *p1) {
	struct node *cur = p1;
	while (cur != NULL) {
		printf("%d -> ", cur->data);
		cur = cur->next; // 当前点访问完了，继续下一个点 
	}
	printf("X\n");
}

//两个链表拼接成新的链表，复制的形式

//两个链表拼接成一个链表，并且是交替 
List merge(List p1, List p2) {
	if (p1 == NULL) {
		return p2;
	}
	if (p2 == NULL) {
		return p1;
	}
	// p1和p2都不为空
	
	// p3不存储数据，只是为了编程 
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
	
	//到达67行，含义有一条链表为空
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
	
	//测试merge函数
	p1 = merge(p1, p2); 
	print(p1);
	
	
	
	return 0;
}

