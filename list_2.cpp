#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *next;
};
 

// 打印list中的data 
// 100 -> 200 -> 150 -> X
void print(struct node *p1) {
	struct node *cur = p1;
	while (cur != NULL) {
		printf("%d -> ", cur->data);
		cur = cur->next; // 当前点访问完了，继续下一个点 
	}
	printf("X\n");
}

// 计算list的长度, 链表可能长度为0 
// 100 200 150,长度为3 
// 如果传过来的p1是NULL 
int length(struct node *p1) {
	int count = 0;
	struct node *cur = p1;
	while (cur != NULL) {
		count++;
		cur = cur->next;
	}
    return count;
}

//将新节点插入到list的头部，返回新的头部 
// value 插入到 前面，后面跟着100 200 150 x 
struct node * insert_head(int value, struct node *p1) {
	struct node *p = (struct node *) malloc(sizeof(struct node));
	p->data = value;
	p->next = p1;
	return p; 
}

//主函数p1是链表的头部，调用p1 = insert_head(500, p1),
//print(p1), 主函数可以打印新加入的500节点吗？ 

//判断list中是否有某个值 value 
//  100 200 150 x  问链表里面有没有value 130 
// 如果有，返回1，否则返回0 
int contains(int value, struct node *p1) {
	struct node *cur = p1;
	while (cur != NULL) {
		if (cur->data == value) {
			return 1;
		}
		cur = cur->next;
	}
    return 0;
}

// 在list的尾部插入值 
// 100 200 150 value x, 不考虑p1为空 
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

// 删除list的尾部，等于最后一个节点free掉 + 倒数第二个节点next设置为NULL
void remove_tail(struct node *p1) {
	if (p1 == NULL) {
		// 链表为空
		return; 
	} 
	// p1不为空 
	if (p1->next == NULL) {
		// 代表链表只有一个节点 
		free(p1);
		return; 
	} 
	// p1不为空，且p1的下一个节点也不为空，代表链表中至少有2个点
	struct node* pre = p1;
	struct node* cur = pre->next;
	while (cur->next != NULL) {
		cur = cur->next;
		pre = pre->next;
	} 
	//97行，cur是倒数第一个节点，而pre是倒数第二个节点 
	pre->next = NULL;
	free(cur);
}

// 在链表的i号位置上插入一个值为value的节点，返回链表的头部 
struct node* insert(int i, int value, struct node* p1) {
	// 1.处理不合法输入:i小于0或i大于链表长度 
	int len = length(p1); 
	if (i < 0 || i > len) {
		//不用处理，无法插入 
		return p1;
	}
	
	// 2.插入位置i为0
	if (i == 0) {
		return insert_head(value, p1); //返回新头部 
	}
	
	// 3.插入位置i等于链表长度
	if (i == len) {
		insert_tail(value, p1);
		return p1;
	} 
	
	// 4.其他插入位置 
	// 1- 最后一个节点 
	struct node* pre = p1; //第0号节点 
	struct node* cur = pre->next; //第1号节点
	int cur_cnt = 1; 
	while (cur_cnt != i) {
		//还未到达i号位置
		pre = pre->next; // i-1号节点 
		cur = cur->next; // i号节点 
		cur_cnt++;
	}
	// cur_cnt == i时终止，cur就是i号节点，pre就是i-1节点 
	struct node *p2 = (struct node *) malloc(sizeof(struct node));
	p2->data = value;
	
	pre->next = p2;
	p2->next = cur;
	return p1; 
} 

//双链表操作
struct node* link(struct node *p1, struct node *p2) {
	//0.异常处理
	// a) p1 == NULL, p2 != NULL 错误 
	// b) p1 != NULL, p2 == NULL 正确 
	// c) p1 == NULL, p2 == NULL 错误 
	// d) p1 != NULL, p2 != NULL 最理想情况 
	
	if (p1 == NULL) {
		return p2;
	}
	if (p2 == NULL) {
		return p1;
	}
	
	//1.先找到p1的最后一个节点
	struct node *cur = p1;
	// NULL是没有任何东西，没有data, 也没有next 
	while (cur->next != NULL) {
		cur = cur->next;
	}
	//cur最后一个节点 
	
	//2.p1的最后一个的next设置成p2
	cur->next = p2; // p2为NULL 
	//3.要把新的头部返回 
	return p1;// 此时新头部一直是p1 
}

struct node* create(struct node *p1, struct node *p2) {
	//最理想情况：两个链表都不为空
	
	// 这是全新的节点，哨兵节点 
	struct node *head = (struct node *)malloc(sizeof(struct node));
	head->next = NULL;
	//没有设置data 
	
	struct node *cur = head; //此时链表的尾部 
	int count = 1;
	while (p1 != NULL && p2 != NULL) {
		// 取出p1或p2，复制拼接到p3上面
		struct node *tmp = (struct node *)malloc(sizeof(struct node));
		tmp->next = NULL; // 新节点必然为此时的最后一个节点 
		if (count % 2 == 1) {
			//要复制的点来自p1 
			tmp->data = p1->data; // 新的节点复制p1的data 
			p1 = p1->next;//更新p1
		} else {
			tmp->data = p2->data; // 新的节点复制p1的data 
			p2 = p2->next;//更新p1
		} 
		cur->next = tmp; // cur代表新链表最后一个点，cur的next设置为新节点 
		cur = cur->next; // 新链表进行更新位置
		count++;// 交替取值 
	} 
	//p1和p2节点全部复制完了吗? 长的链表还没有复制完！ 
	//要么p1为空，要么p2为空！
	
	// a) if判断是p1，p2是否为空
	// b) 看count
	// c) 把两个接上去，反正都为空 
	struct node *rest = p1 != NULL ? p1 : p2;
	while (rest != NULL) {
		struct node *tmp = (struct node *)malloc(sizeof(struct node));
		tmp->next = NULL; // 新节点必然为此时的最后一个节点
		tmp->data = rest->data;
		cur->next = tmp;// 新节点链接到新链表尾部 
		cur = cur->next;
		rest = rest->next; 
	}
	// rest == null就是两个链表全部复制完
	return head->next;
}
 

int main(void) {
	struct node n1;
	n1.data = 100;
	n1.next = NULL;
	
	//内存中创建一个结构体变量，取出地址，存在指针里
	// 使用malloc，需要头文件<stdlib.h> 
	// malloc括号里需要填入内存大小， malloc返回申请空间的首地址 
	struct node *p1 = (struct node *) malloc(sizeof(struct node));
	p1->data = 100;
	p1->next = NULL; 
	
	// 创建p2，p2对应的节点的值为200，
	// 且p1指向的节点 的下一个节点为 p2指向的节点 
	struct node *p2 = (struct node *) malloc(sizeof(struct node));
	p2->data = 200;
	p1->next = p2; // p2对应节点node2的地址 == p2 
	
	// p3, 150, 对应节点在p2对应的节点后面
	struct node *p3 = (struct node *) malloc(sizeof(struct node));
	p3->data = 150;
	p2->next = p3; 
	p3->next = NULL;
	
	// malloc主动申请内存，如果不使用的话，要释放掉（删除） 
	// 使用函数free(对应的指针)
	
	insert_tail(400, p1);
	insert_tail(300, p1);
	insert_tail(500, p1);
	
	remove_tail(p1);
	
	printf("插入之前\n"); 
	print(p1);
	printf("2号位置插入600\n"); 
	p1 = insert(2, 600, p1);
	print(p1);
	printf("0号位置插入700\n"); 
	p1 = insert(0, 700, p1);
	print(p1);
	printf("7号位置插入1000\n"); 
	p1 = insert(7, 1000, p1);
	print(p1);
	printf("-1号位置插入900\n"); 
	p1 = insert(-1, 900, p1);
	print(p1);
	printf("9号位置插入900\n"); 
	p1 = insert(-1, 900, p1);
	print(p1);
	
	printf("===========测试两个链表拼接===========\n");
	struct node *first = p1;
	struct node *second = (struct node *) malloc(sizeof(struct node));
	second->data = 10;
	second->next = NULL;
	insert_tail(40, second);
	insert_tail(30, second);
	insert_tail(50, second);
	
	struct node *third = create(first, second);
	printf("第一个链表：\n");
	print(first);
	printf("第二个链表：\n");
	print(second);
	printf("交替合并后的链表：\n"); 
	print(third);
	
	
	return 0;
}
