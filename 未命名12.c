#include <stdio.h>
#include <malloc.h>

typedef int ElementType;
typedef struct Lnode * List;

struct Lnode{
	ElementType Data;
	List Next;
};

List AppendNodeAtFront(List ,ElementType ); 
void Disply(List head);
List AppendNodeAtRear(List head,ElementType X); 
int deleteLinkList(LinkList *L, int pos, ElemType *e);


int main(){
	int a,b,c;
	while(1){
		printf("1.¼������\n2.β����������\n3.��ʾ����\n4.ɾ������\n5.�˳�ϵͳ");
		 
	}
} 
int menu()
{      
        system("cls");
		printf("1.¼������\n2.β����������\n3.��ʾ����\n4.ɾ������\n5.�˳�ϵͳ");
		return 1;
}
void main()          
{
	List head = NULL;
	int n,i;
	ElementType data;
	while(1) 
	{
		menu(); 
//		printf("\t��ѡ����Ҫ���е�ѡ�(0-9):");
	    scanf("%d",&a);
	    int b=0;
        switch(a) 
        {
        	case 1: 
        		system("cls");
				List AppendNodeAtFront(List ,ElementType ); 
        	    break;
            case 2:
				system("cls");
				void Disply(List head);
				break; 
            case 3:system("cls");
				List AppendNodeAtRear(List head,ElementType X); 
                break;
            	
            case 4:
            	system("cls");
	            int deleteLinkList(LinkList *L, int pos, ElemType *e);
	            break; 	  
            case 5:
            	system("cls");
                printf("\n\t\t\t\t\tллʹ��\n");
                exit(0);
                break; 
        	default:
//        		system("cls");
				printf("��Ϲ��");
				sleep(5);
				menu();        
		}
	}
}
