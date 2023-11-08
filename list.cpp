#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *next;
};
 

// ��ӡlist�е�data 
// 100 -> 200 -> 150 -> X
void print(struct node *p1) {
	struct node *cur = p1;
	while (cur != NULL) {
		printf("%d -> ", cur->data);
		cur = cur->next; // ��ǰ��������ˣ�������һ���� 
	}
	printf("X\n");
}

// ����list�ĳ���, ������ܳ���Ϊ0 
// 100 200 150,����Ϊ3 
// �����������p1��NULL 
int length(struct node *p1) {
	int count = 0;
	struct node *cur = p1;
	while (cur != NULL) {
		count++;
		cur = cur->next;
	}
    return count;
}

//���½ڵ���뵽list��ͷ���������µ�ͷ�� 
// value ���뵽 ǰ�棬�������100 200 150 x 
struct node * insert_head(int value, struct node *p1) {
	struct node *p = (struct node *) malloc(sizeof(struct node));
	p->data = value;
	p->next = p1;
	return p; 
}

//������p1�������ͷ��������p1 = insert_head(500, p1),
//print(p1), ���������Դ�ӡ�¼����500�ڵ��� 

//�ж�list���Ƿ���ĳ��ֵ value 
//  100 200 150 x  ������������û��value 130 
// ����У�����1�����򷵻�0 
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

// ��list��β������ֵ 
// 100 200 150 value x, ������p1Ϊ�� 
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

// ɾ��list��β�����������һ���ڵ�free�� + �����ڶ����ڵ�next����ΪNULL
void remove_tail(struct node *p1) {
	if (p1 == NULL) {
		// ����Ϊ��
		return; 
	} 
	// p1��Ϊ�� 
	if (p1->next == NULL) {
		// ��������ֻ��һ���ڵ� 
		free(p1);
		return; 
	} 
	// p1��Ϊ�գ���p1����һ���ڵ�Ҳ��Ϊ�գ�����������������2����
	struct node* pre = p1;
	struct node* cur = pre->next;
	while (cur->next != NULL) {
		cur = cur->next;
		pre = pre->next;
	} 
	//97�У�cur�ǵ�����һ���ڵ㣬��pre�ǵ����ڶ����ڵ� 
	pre->next = NULL;
	free(cur);
}

// �������i��λ���ϲ���һ��ֵΪvalue�Ľڵ㣬���������ͷ�� 
struct node* insert(int i, int value, struct node* p1) {
	// 1.�����Ϸ�����:iС��0��i���������� 
	int len = length(p1); 
	if (i < 0 || i > len) {
		//���ô����޷����� 
		return p1;
	}
	
	// 2.����λ��iΪ0
	if (i == 0) {
		return insert_head(value, p1); //������ͷ�� 
	}
	
	// 3.����λ��i����������
	if (i == len) {
		insert_tail(value, p1);
		return p1;
	} 
	
	// 4.��������λ�� 
	// 1- ���һ���ڵ� 
	struct node* pre = p1; //��0�Žڵ� 
	struct node* cur = pre->next; //��1�Žڵ�
	int cur_cnt = 1; 
	while (cur_cnt != i) {
		//��δ����i��λ��
		pre = pre->next; // i-1�Žڵ� 
		cur = cur->next; // i�Žڵ� 
		cur_cnt++;
	}
	// cur_cnt == iʱ��ֹ��cur����i�Žڵ㣬pre����i-1�ڵ� 
	struct node *p2 = (struct node *) malloc(sizeof(struct node));
	p2->data = value;
	
	pre->next = p2;
	p2->next = cur;
	return p1; 
} 

int main(void) {
	struct node n1;
	n1.data = 100;
	n1.next = NULL;
	
	//�ڴ��д���һ���ṹ�������ȡ����ַ������ָ����
	// ʹ��malloc����Ҫͷ�ļ�<stdlib.h> 
	// malloc��������Ҫ�����ڴ��С�� malloc��������ռ���׵�ַ 
	struct node *p1 = (struct node *) malloc(sizeof(struct node));
	p1->data = 100;
	p1->next = NULL; 
	
	// ����p2��p2��Ӧ�Ľڵ��ֵΪ200��
	// ��p1ָ��Ľڵ� ����һ���ڵ�Ϊ p2ָ��Ľڵ� 
	struct node *p2 = (struct node *) malloc(sizeof(struct node));
	p2->data = 200;
	p1->next = p2; // p2��Ӧ�ڵ�node2�ĵ�ַ == p2 
	
	// p3, 150, ��Ӧ�ڵ���p2��Ӧ�Ľڵ����
	struct node *p3 = (struct node *) malloc(sizeof(struct node));
	p3->data = 150;
	p2->next = p3; 
	p3->next = NULL;
	
	// malloc���������ڴ棬�����ʹ�õĻ���Ҫ�ͷŵ���ɾ���� 
	// ʹ�ú���free(��Ӧ��ָ��)
	
	insert_tail(400, p1);
	insert_tail(300, p1);
	insert_tail(500, p1);
	
	remove_tail(p1);
	
	printf("����֮ǰ\n"); 
	print(p1);
	printf("2��λ�ò���600\n"); 
	p1 = insert(2, 600, p1);
	print(p1);
	printf("0��λ�ò���700\n"); 
	p1 = insert(0, 700, p1);
	print(p1);
	printf("7��λ�ò���1000\n"); 
	p1 = insert(7, 1000, p1);
	print(p1);
	printf("-1��λ�ò���900\n"); 
	p1 = insert(-1, 900, p1);
	print(p1);
	printf("9��λ�ò���900\n"); 
	p1 = insert(-1, 900, p1);
	print(p1);
	
	
	return 0;
}
