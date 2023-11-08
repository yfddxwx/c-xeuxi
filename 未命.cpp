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
//		printf("1.录入数据\n2.尾部插入数据\n3.显示数据\n4.删除数据\n5.退出系统");
//		 
//	}
//} 
int menu()
{      
        system("cls");
		printf("1.录入数据\n2.尾部插入数据\n3.显示数据\n4.删除数据\n5.退出系统");
		return 1;
}
int main()          
{
	
	while(1) 
	{
		menu(); 
//		printf("\t请选择您要运行的选项按(0-9):");
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
				AppendNodeAtRear(List head,ElementType f)//尾插法 任务一 
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
                printf("\n\t\t\t\t\t谢谢使用\n");
                exit(0);
                break; 
        	default:
//        		system("cls");
				printf("别瞎玩");
//				sleep(5);
				menu();        
		}
	}
}

void abs(){
	List head = NULL;
	int n,i;
	ElementType data;
	printf("开始采用头插法创建链表\n");
	printf("请输入插入结点的个数：");
	scanf("%d",&n); 
	for(i = 1;i < n+1;i++){
		 printf("请输入结点的值：");
		 scanf("%d",&data);
	     //head = AppendNodeAtFront(head,data);
		 head = AppendNodeAtRear(head,data);	
	}
	printf("头插法创建链表完成\n"); 
}
List AppendNodeAtFront(List head,ElementType X){//头插法，将一个结点插入到链表中 
	//1.创建一个结点，动态分配空间 
    List newNode = (List)malloc(sizeof(struct Lnode));
	newNode->Data = X;	
	if(head == NULL){//(1)表空 
	    head = newNode;
	    newNode->Next = NULL;
	    return head;
	}else{//(2)表非空 
	    newNode->Next = head;
	    head = newNode;
	    return head;
	}
}

void Disply(List head){//任务2 

	//判断表是否为空 
	 if(head == NULL){//表空 
		printf("链表为空表，打印失败\n");
	 }else{//表非空 
	    List p = head;
	    int i;
		for(i = 1;p != NULL;i++){
			printf("开始打印第%d个结点值为：%d\n",i,p->Data);
			p = p->Next;
		}
	 }	
}

List AppendNodeAtRear(List head,ElementType X){//尾插法 任务一 
	 List newNode = (List)malloc(sizeof(struct Lnode));
	 newNode->Data = X;
	 newNode->Next = NULL;
	 
	 //判断表是否为空
	 if(head == NULL){//1.表空 
	 	 head = newNode;
		 return head;  
	 }else{//2.表非空 
	 	 List p = head;
	 	 while(p->Next){
	 	 	p = p->Next;
		  }
		  p->Next = newNode;
		  return head;
	 } 	
}

/*线性表的单链表
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
	printf("请输入元素内容");
	for (int i = 0; i < num; i++) {
		L->next = (LNode*)malloc(sizeof(LNode));
		scanf_s("%d", &elem);
		L->next->data = elem;
		L = L->next;
	}
	L->next = NULL;
	L = head;
}
//获取链表长度
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
//定位某个元素
void LocationElem(LinkList L, ElemType elem) {
	int i = 0;
	bool flag = false;
	LinkList first = L;
	while (L->next != NULL){
		i++;
		if (L->next->data == elem) {
			flag = true;
			printf("%d位于第%d位",elem,i);
		}
		L = L->next;
	}
	L = first;
	if (!flag) {
		printf("抱歉，没有该元素");
	}
}
//通过位置获取元素
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
		printf("下标不合法\n");
		L = first;
		return;
	}
	else {
		while (i < Location) {
			L = L->next;
			i++;
		}
		printf("第%d位置的元素是%d\n",Location, L->data);
		L = first;
	}
}
//插入元素
void InsertList(LinkList L, ElemType elem, int location) {
	LNode* wait = NULL;//待插入LNode
	LNode* wait_next = NULL;
	LNode* first = L;
	int i = 0;
	int length = 0;
	while (L->next != NULL) {
		length++;
		L = L->next;
	}//获取链表长度
	L = first;
	if (location > length + 1 || location < 1) {
		printf("下标不合法\n");
		L = first;
		return;
	}
	while (i <= (location - 2)) {
		L = L->next;
		i++;
	}//将L转到插入位置的前面
	wait_next = L->next;
	wait = (LNode*)malloc(sizeof(LNode));//分配空间给待插入的LNode
	wait->data = elem;
	L->next = wait;//将待插LNode的前一个LNode的next指向待插LNode地址
	wait->next = wait_next;
	printf("插入成功\n");
	L = first;
}
 
void deleteElem(LinkList L, int location) {
	LNode* first = L;
	int i = 0;
	int length = 0;
	while (L->next != NULL) {
		length++;
		L = L->next;
	}//获取链表长度
	L = first;
	if (location > length || location < 1) {
		printf("下标不合法\n");
		L = first;
		return;
	}
	while (i < location -1 ) {
		L = L->next;
		i++;
	}
	L->next = L->next->next;
	printf("删除成功");
	L = first;
}
//打印单链表
void print(LinkList L) {
	LNode* first = L;
	while (first->next != NULL) {
		printf("%d ", first->next->data);
		first = first->next;
	}
}
//由于传进地址，排序完成后无法恢复原样
void sort(LinkList L) {
	ElemType temp;
	LNode* first = L;
	LNode* flag = L;
	int i = 0;
	int length = 0;
	while (L->next != NULL) {
		length++;
		L = L->next;
	}//获取链表长度
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
//逆置
void Invert(LinkList L) {
	LNode* first = L;
	LNode* last = L;
	ElemType temp;
	int i = 0;
	int length = 0;
	int length_temp;//用来获取后一半的节点
	while (L->next != NULL) {
		length++;
		L = L->next;
	}//获取链表长度
	length_temp = length;
	last = L;//将最后倒数的节点节点赋给last变量
	L = first;
	for (i = 0; i < length / 2; i++) {
		temp = L->next->data;
		L->next->data = last->data;
		last->data = temp;//交换完毕
 
		L = L->next;
		last = first;//重新找下一个last节点
		length_temp--;
		for (int j = 0;j < length_temp; j++) {
			last = last->next;
		}//找到后面的节点
	}
	L = first;
	printf("逆置成功\n");
	print(L);
}
 
 
 
int main() {
	LinkList L = NULL;
	int elem;
	int operate = -1;//操作数
	int length = 0;//求表长用到
	int num = 0;//表元素个数
	int location = 0;//元素下标
	printf("请输入要进行的操作\n");
	printf("1---创建单链表\n");
	printf("2---单链表长度\n");
	printf("3---求指定元素的位置\n");
	printf("4---给定下标获取元素\n");
	printf("5---插入元素\n");
	printf("6---删除元素\n");
	printf("7---排序\n");
	printf("8---逆置单链表\n");
	printf("11---打印单链表\n");
	while (operate != 0) {
		scanf_s("%d", &operate);
		switch (operate){
			case 1:
				printf("请输入元素个数\n");
				scanf_s("%d", &num);
				L = InitLNode();
				createLinkList(L, num);
				printf("请输入编号进行下一步操作\n");break;
			case 2:
				length = listLength(L);
				printf("单链表的长度是%d\n", length);
				printf("请输入编号进行下一步操作\n");break;
			case 3:
				printf("请输入你想定位的元素\n");
				scanf_s("%d", &elem);
				LocationElem(L, elem);
				printf("请输入编号进行下一步操作\n");break;
			case 4:
				printf("请输入元素下标:\n");
				scanf_s("%d", &location);
				GetElem(L, location);
				printf("请输入编号进行下一步操作\n");break;
			case 5:
				printf("请输入插入的元素和插入位置:\n");
				scanf_s("%d %d",&elem, &location);
				InsertList(L, elem, location);
				printf("请输入编号进行下一步操作\n");break;
			case 6:
				printf("请输入你想删除的元素的位置\n");
				scanf_s("%d", &location);
				deleteElem(L, location);
				printf("请输入编号进行下一步操作\n");break;
			case 7:
				sort(L);
				printf("请输入编号进行下一步操作\n");break;
			case 8:
				Invert(L);
				printf("请输入编号进行下一步操作\n");break;
			case 11:
				print(L);
				printf("请输入编号进行下一步操作\n");break;
		}
	}
 
}*/
