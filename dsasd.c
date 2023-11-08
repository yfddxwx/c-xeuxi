#include<stdio.h>
int malgb(int a[],int*p){
	int i;
    for(i=0;i<sizeof(a)/sizeof(a[0]);i++){
    	int a;
		printf("%d",*p++);
	}
}
int main(){
    int a[5]={0,1,2,3,4,};
    int *p=a[0];
    int i;
    for(i=0;i<sizeof(a)/sizeof(a[0]);i++){
    	
		printf("%d",*p);
	}
}
    
