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
    printf("请输入元素的个数：");  
    scanf_s("%d",&n);  //将n个元素依次放入到顺序表中   
    if(n <= Maxsize){     
        for(i = 0;i < n;i++){         
            printf("请输入第%d个元素的值：",i+1);
            scanf_s("%d",&data);
            llist->Data[i] = data;          
            llist->Last++;           
            printf("第%d个元素存入成功\n",i+1);
        }     
    } else{      
        printf("输入数据不合法，请输入小于等于100的数\n");
    }      //将n个元素打印输出    
    printf("请输出顺序表中的所有值\n");
    for(i = 0;i < n;i++){         
        printf("第%d个元素的值为：%d\n",i+1,llist->Data[i]);
    }
    printf("\n");
    //查找  
    printf("请输入要查找的值：");  
    scanf_s("%d",&data2);   
    Find(llist,data2);   
    printf("\n");
    //插入
    printf("请输入插入的值:");
    scanf_s("%d", &data3);
    printf("请确定插入位序:");
    scanf_s("%d", &i);
    int a=Insert(llist, data3, i);
    if (a == 1) {
        for (i = 0; i < n; i++) {
            printf("第%d个元素的值为：%d\n", i + 1, llist->Data[i]);
        }
    }
    
    //删除
    printf("\n");
    printf("请输入要删除的指定位序：");
    scanf_s("%d", &i);
    delete(llist, i);
    for (i = 0; i < n; i++) {
        printf("第%d个元素的值为：%d\n", i + 1, llist->Data[i]);
    }
} 
List MakeEmpty(){  
    printf("开始创建顺序表\n");  
    List list = (List)malloc(sizeof(struct Lnode));  
    list->Last = -1;  
    printf("创建顺序表完成\n");  
    return list;
}
void Find(List llist,ElementType X){     
    int i = 0;  
    while(llist->Data[i] != X && i <= llist->Last){  
        i++;
    }  
    if(i > llist->Last){    
        printf("查找失败\n");   
    }else{     
        printf("%d首次出现的位序为%d\n",X ,i+1);   
    } 
}
int Insert(List llist, ElementType X, int i) {
    int j;
    if (llist->Last == Maxsize - 1) {
        printf("已满");
        return -1;
    }
    if (i<1 || i>llist->Last + 2) {
            printf("位序不合法");
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
        printf("位序%d不存在元素", i);
        return -1;
    }
    for (j = i; j <= llist->Last; j++) {
        llist->Data[j - 1] = llist->Data[j];
        llist->Last--;
        return 1;
    }
}
