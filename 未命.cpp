#include <stdio.h>
#include <malloc.h>
# include<string.h>
# include<stdlib.h>

typedef int ElementType;
typedef struct Lnode * List;

struct Lnode{
	ElementType Data;
	List Next;
};

List AppendNodeAtFront(List ,ElementType ); 
void Disply(List head);
List AppendNodeAtRear(List head,ElementType X);
void abs(); 


//int main(){
//	int a,b,c;
//	while(1){
//		printf("1.¼������\n2.β����������\n3.��ʾ����\n4.ɾ������\n5.�˳�ϵͳ");
//		 
//	}
//} 
int menu()
{      
        system("cls");
		printf("1.¼������\n2.β����������\n3.��ʾ����\n4.ɾ������\n5.�˳�ϵͳ");
		return 1;
}
int main()          
{
	
	while(1) 
	{
		menu(); 
//		printf("\t��ѡ����Ҫ���е�ѡ�(0-9):");
		int a;
	    scanf("%d",&a);
	    int b=0;
        switch(a) 
        {
        	case 1: 
        		system("cls");
				abs() ;
        	    break;
            case 2:
				system("cls");
				int p,f;
				scanf("%d",p);
				scanf("%d",f)
				AppendNodeAtRear(List head,ElementType f)//β�巨 ����һ 
				break; 
            case 3:
//			system("cls");
				void Disply(List head);
                break;
            	
            case 4:
            	system("cls");
//	            int deleteLinkList(LinkList *L, int pos, ElemType *e);
	            break; 	  
            case 5:
            	system("cls");
                printf("\n\t\t\t\t\tллʹ��\n");
                exit(0);
                break; 
        	default:
//        		system("cls");
				printf("��Ϲ��");
//				sleep(5);
				menu();        
		}
	}
}

void abs(){
	List head = NULL;
	int n,i;
	ElementType data;
	printf("��ʼ����ͷ�巨��������\n");
	printf("�����������ĸ�����");
	scanf("%d",&n); 
	for(i = 1;i < n+1;i++){
		 printf("���������ֵ��");
		 scanf("%d",&data);
	     //head = AppendNodeAtFront(head,data);
		 head = AppendNodeAtRear(head,data);	
	}
	printf("ͷ�巨�����������\n"); 
}
List AppendNodeAtFront(List head,ElementType X){//ͷ�巨����һ�������뵽������ 
	//1.����һ����㣬��̬����ռ� 
    List newNode = (List)malloc(sizeof(struct Lnode));
	newNode->Data = X;	
	if(head == NULL){//(1)��� 
	    head = newNode;
	    newNode->Next = NULL;
	    return head;
	}else{//(2)��ǿ� 
	    newNode->Next = head;
	    head = newNode;
	    return head;
	}
}

void Disply(List head){//����2 

	//�жϱ��Ƿ�Ϊ�� 
	 if(head == NULL){//��� 
		printf("����Ϊ�ձ���ӡʧ��\n");
	 }else{//��ǿ� 
	    List p = head;
	    int i;
		for(i = 1;p != NULL;i++){
			printf("��ʼ��ӡ��%d�����ֵΪ��%d\n",i,p->Data);
			p = p->Next;
		}
	 }	
}

List AppendNodeAtRear(List head,ElementType X){//β�巨 ����һ 
	 List newNode = (List)malloc(sizeof(struct Lnode));
	 newNode->Data = X;
	 newNode->Next = NULL;
	 
	 //�жϱ��Ƿ�Ϊ��
	 if(head == NULL){//1.��� 
	 	 head = newNode;
		 return head;  
	 }else{//2.��ǿ� 
	 	 List p = head;
	 	 while(p->Next){
	 	 	p = p->Next;
		  }
		  p->Next = newNode;
		  return head;
	 } 	
}

/*���Ա�ĵ�����
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
		scanf_s("%d", &elem);
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
		scanf_s("%d", &operate);
		switch (operate){
			case 1:
				printf("������Ԫ�ظ���\n");
				scanf_s("%d", &num);
				L = InitLNode();
				createLinkList(L, num);
				printf("�������Ž�����һ������\n");break;
			case 2:
				length = listLength(L);
				printf("������ĳ�����%d\n", length);
				printf("�������Ž�����һ������\n");break;
			case 3:
				printf("���������붨λ��Ԫ��\n");
				scanf_s("%d", &elem);
				LocationElem(L, elem);
				printf("�������Ž�����һ������\n");break;
			case 4:
				printf("������Ԫ���±�:\n");
				scanf_s("%d", &location);
				GetElem(L, location);
				printf("�������Ž�����һ������\n");break;
			case 5:
				printf("����������Ԫ�غͲ���λ��:\n");
				scanf_s("%d %d",&elem, &location);
				InsertList(L, elem, location);
				printf("�������Ž�����һ������\n");break;
			case 6:
				printf("����������ɾ����Ԫ�ص�λ��\n");
				scanf_s("%d", &location);
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
 
}*/
