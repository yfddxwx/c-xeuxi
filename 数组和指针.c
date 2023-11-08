#include<stdio.h>
int main(){
	char *a[4] = {"可达鸭", "bokebi", "pikaqu", "mioawazz"};
	int i=0,b;
	for(i;i<4;i++)printf("%s\n",a[i]);
//	scanf("%d",&b);
	for(;;){
		scanf("%d",&b);
		if(b<=3&&b>=0){
			printf("%s\n",a[b]);
			break;
		}else printf("傻逼\n"); 
	} 
	printf("傻逼还有什么要求吗\n");
	char c[80];
	scanf("%s",c);
	int f=9;
//	for(;;){
	
	for(i=0;i<4;i++){
		if(strcmp(c,a[i])==0){
		printf("好的这是%s\n",a[i]);
		f=1;
		} 
		
	}if(f=9)printf("傻逼能不能好好输？\n");
//	scanf("%s",c);}
}
