#include <stdio.h>
#include <malloc.h>
#define Maxsize 100
typedef int ElementType;
typedef struct Lnode * List;
struct Lnode{  ElementType Data[Maxsize];  
               int Last; 
};
List MakeEmpty(); 
void Find(List llist,ElementType X);
int Insert(List llist, ElementType X, int i);
void delete(List llist, int i);

int main(){  
    int i,n;  
    ElementType data,data2,data3;
    List llist = MakeEmpty();
    printf("������Ԫ�صĸ�����");  
    scanf_s("%d",&n);  //��n��Ԫ�����η��뵽˳�����   
    if(n <= Maxsize){     
        for(i = 0;i < n;i++){         
            printf("�������%d��Ԫ�ص�ֵ��",i+1);
            scanf_s("%d",&data);
            llist->Data[i] = data;          
            llist->Last++;           
            printf("��%d��Ԫ�ش���ɹ�\n",i+1);
        }     
    } else{      
        printf("�������ݲ��Ϸ���������С�ڵ���100����\n");
    }      //��n��Ԫ�ش�ӡ���    
    printf("�����˳����е�����ֵ\n");
    for(i = 0;i < n;i++){         
        printf("��%d��Ԫ�ص�ֵΪ��%d\n",i+1,llist->Data[i]);
    }
    printf("\n");
    //����  
    printf("������Ҫ���ҵ�ֵ��");  
    scanf_s("%d",&data2);   
    Find(llist,data2);   
    printf("\n");
    //����
    printf("����������ֵ:");
    scanf_s("%d", &data3);
    printf("��ȷ������λ��:");
    scanf_s("%d", &i);
    int a=Insert(llist, data3, i);
    if (a == 1) {
        for (i = 0; i < n; i++) {
            printf("��%d��Ԫ�ص�ֵΪ��%d\n", i + 1, llist->Data[i]);
        }
    }
    
    //ɾ��
    printf("\n");
    printf("������Ҫɾ����ָ��λ��");
    scanf_s("%d", &i);
    delete(llist, i);
    for (i = 0; i < n; i++) {
        printf("��%d��Ԫ�ص�ֵΪ��%d\n", i + 1, llist->Data[i]);
    }
} 
List MakeEmpty(){  
    printf("��ʼ����˳���\n");  
    List list = (List)malloc(sizeof(struct Lnode));  
    list->Last = -1;  
    printf("����˳������\n");  
    return list;
}
void Find(List llist,ElementType X){     
    int i = 0;  
    while(llist->Data[i] != X && i <= llist->Last){  
        i++;
    }  
    if(i > llist->Last){    
        printf("����ʧ��\n");   
    }else{     
        printf("%d�״γ��ֵ�λ��Ϊ%d\n",X ,i+1);   
    } 
}
int Insert(List llist, ElementType X, int i) {
    int j;
    if (llist->Last == Maxsize - 1) {
        printf("����");
        return -1;
    }
    if (i<1 || i>llist->Last + 2) {
            printf("λ�򲻺Ϸ�");
            return -1;
     }
    for (j = llist->Last; j >= i - 1; j--) {
        llist->Data[j + 1] = llist->Data[j];
    }
    llist->Data[i - 1] = X;
    llist->Last++;
    return 1;
}
void delete(List llist, int i) {
    int j;
    if (i<1 || i>llist->Last + 1) {
        printf("λ��%d������Ԫ��", i);
        return -1;
    }
    for (j = i; j <= llist->Last; j++) {
        llist->Data[j - 1] = llist->Data[j];
        llist->Last--;
        return 1;
    }
}
