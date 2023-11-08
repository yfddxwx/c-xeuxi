# include<stdio.h>
# include<stdlib.h>
 #define ERROR -2
typedef char ElemType;
 
typedef struct LNode {
	ElemType data;
	LNode* next;
}LNode, *LinkList;
 
LinkList InitLNode() {
	LinkList L;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	return L;
}
 
void createLinkList(LinkList L, int num) {
	int elem = 0;
	LinkList head = L;
	printf("������Ԫ������");
	for (int i = 0; i < num; i++) {
		L->next = (LNode*)malloc(sizeof(LNode));
		scanf("%d", &elem);
		L->next->data = elem;
		L = L->next;
	}
	L->next = NULL;
	L = head;
}
//��ȡ������
int listLength(LinkList L) {
	LinkList first = L;
	int length = 0;
	while (L->next != NULL) {
		length++;
		L = L->next;
	}
	L = first;
	return length;
}
//��λĳ��Ԫ��
void LocationElem(LinkList L, ElemType elem) {
	int i = 0;
	bool flag = false;
	LinkList first = L;
	while (L->next != NULL){
		i++;
		if (L->next->data == elem) {
			flag = true;
			printf("%dλ�ڵ�%dλ",elem,i);
		}
		L = L->next;
	}
	L = first;
	if (!flag) {
		printf("��Ǹ��û�и�Ԫ��");
	}
}
//ͨ��λ�û�ȡԪ��
void GetElem(LinkList L, int Location) {
	LNode* first = L;
	int i = 0;
	int length = 0;
	while (L->next != NULL) {
		length++;
		L = L->next;
	}
	L = first;
	if (length < Location|| Location<1) {
		printf("�±겻�Ϸ�\n");
		L = first;
		return;
	}
	else {
		while (i < Location) {
			L = L->next;
			i++;
		}
		printf("��%dλ�õ�Ԫ����%d\n",Location, L->data);
		L = first;
	}
}
//����Ԫ��
void InsertList(LinkList L, ElemType elem, int location) {
	LNode* wait = NULL;//������LNode
	LNode* wait_next = NULL;
	LNode* first = L;
	int i = 0;
	int length = 0;
	while (L->next != NULL) {
		length++;
		L = L->next;
	}//��ȡ������
	L = first;
	if (location > length + 1 || location < 1) {
		printf("�±겻�Ϸ�\n");
		L = first;
		return;
	}
	while (i <= (location - 2)) {
		L = L->next;
		i++;
	}//��Lת������λ�õ�ǰ��
	wait_next = L->next;
	wait = (LNode*)malloc(sizeof(LNode));//����ռ���������LNode
	wait->data = elem;
	L->next = wait;//������LNode��ǰһ��LNode��nextָ�����LNode��ַ
	wait->next = wait_next;
	printf("����ɹ�\n");
	L = first;
}
 
void deleteElem(LinkList L, int location) {
	LNode* first = L;
	int i = 0;
	int length = 0;
	while (L->next != NULL) {
		length++;
		L = L->next;
	}//��ȡ������
	L = first;
	if (location > length || location < 1) {
		printf("�±겻�Ϸ�\n");
		L = first;
		return;
	}
	while (i < location -1 ) {
		L = L->next;
		i++;
	}
	L->next = L->next->next;
	printf("ɾ���ɹ�");
	L = first;
}
//��ӡ������
void print(LinkList L) {
	LNode* first = L;
	while (first->next != NULL) {
		printf("%d ", first->next->data);
		first = first->next;
	}
}
//���ڴ�����ַ��������ɺ��޷��ָ�ԭ��
void sort(LinkList L) {
	ElemType temp;
	LNode* first = L;
	LNode* flag = L;
	int i = 0;
	int length = 0;
	while (L->next != NULL) {
		length++;
		L = L->next;
	}//��ȡ������
	L = first;
	for (int i = 0; i < length-1; i++) {
		//flag = L;
		for (int j = 0; j < length - i - 1; j++) {
			if (L->next->data > L->next->next->data) {
				temp = L->next->data;
				L->next->data = L->next->next->data;
				L->next->next->data = temp;
			}
			L = L->next;
		}
		//L = flag->next;
		L=first;
	}
	L = first;
	print(L);
}
//����
void Invert(LinkList L) {
	LNode* first = L;
	LNode* last = L;
	ElemType temp;
	int i = 0;
	int length = 0;
	int length_temp;//������ȡ��һ��Ľڵ�
	while (L->next != NULL) {
		length++;
		L = L->next;
	}//��ȡ������
	length_temp = length;
	last = L;//��������Ľڵ�ڵ㸳��last����
	L = first;
	for (i = 0; i < length / 2; i++) {
		temp = L->next->data;
		L->next->data = last->data;
		last->data = temp;//�������
 
		L = L->next;
		last = first;//��������һ��last�ڵ�
		length_temp--;
		for (int j = 0;j < length_temp; j++) {
			last = last->next;
		}//�ҵ�����Ľڵ�
	}
	L = first;
	printf("���óɹ�\n");
	print(L);
}
 
 
 
int main() {
	LinkList L = NULL;
	int elem;
	int operate = -1;//������
	int length = 0;//����õ�
	int num = 0;//��Ԫ�ظ���
	int location = 0;//Ԫ���±�
	printf("������Ҫ���еĲ���\n");
	printf("1---����������\n");
	printf("2---��������\n");
	printf("3---��ָ��Ԫ�ص�λ��\n");
	printf("4---�����±��ȡԪ��\n");
	printf("5---����Ԫ��\n");
	printf("6---ɾ��Ԫ��\n");
	printf("7---����\n");
	printf("8---���õ�����\n");
	printf("11---��ӡ������\n");
	while (operate != 0) {
		scanf("%d", &operate);
		switch (operate){
			case 1:
				printf("������Ԫ�ظ���\n");
				scanf("%d", &num);
				L = InitLNode();
				createLinkList(L, num);
				printf("�������Ž�����һ������\n");break;
			case 2:
				length = listLength(L);
				printf("������ĳ�����%d\n", length);
				printf("�������Ž�����һ������\n");break;
			case 3:
				printf("���������붨λ��Ԫ��\n");
				scanf("%d", &elem);
				LocationElem(L, elem);
				printf("�������Ž�����һ������\n");break;
			case 4:
				printf("������Ԫ���±�:\n");
				scanf("%d", &location);
				GetElem(L, location);
				printf("�������Ž�����һ������\n");break;
			case 5:
				printf("����������Ԫ�غͲ���λ��:\n");
				scanf("%d %d",&elem, &location);
				InsertList(L, elem, location);
				printf("�������Ž�����һ������\n");break;
			case 6:
				printf("����������ɾ����Ԫ�ص�λ��\n");
				scanf("%d", &location);
				deleteElem(L, location);
				printf("�������Ž�����һ������\n");break;
			case 7:
				sort(L);
				printf("�������Ž�����һ������\n");break;
			case 8:
				Invert(L);
				printf("�������Ž�����һ������\n");break;
			case 11:
				print(L);
				printf("�������Ž�����һ������\n");break;
		}
	}
 
}
