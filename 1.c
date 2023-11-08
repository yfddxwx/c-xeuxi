
#include<stdio.h>
#define MaxSize 10  //�������ĳ���
typedef struct {
    int data[MaxSize];  //�þ�̬�ġ����顱�������Ԫ��
    int length;     //˳���ĵ�ǰ����
}SqList;

void InitList(SqList  &L){
    for(int i=0; i<MaxSize; i++)
        L.data[i] = 0;
    L.length = 0;
}

bool ListInsert(SqList ,&L, int i,int e){//��L��λ��i������Ԫ��e
	if(i<1 || i>L.length+1) //�ж�i�ķ�Χ�Ƿ���Ч
		return false;
	if(L.length >= MaxSize)//��ǰ�洢�ռ����������ܲ���
		return false;
    for(int j=L.length; j>=i ; j--) //����i��Ԫ�ؼ�֮���Ԫ�غ���
        L.data[j] = L.data[j-1];
    L.data[i-1]=e;  //��λ��i������e
    L.length++; //���ȼ�1
    return true;
}


int main(){
    SqList L; //����һ��˳���
    InitList(L); // ��ʼ��˳���
    ListInsert(L,1,1);
    ListInsert(L,2,2);
    ListInsert(L,3,4);
    ListInsert(L,4,5);
    ListInsert(L,5,6);
    ListInsert(L,3,3);
    
    for(int i=0;i<L->length;i++)
        printf("data[%d]=%d\n",i,L.data[i]);
    
    return 0;
}




