#include<stdio.h>
int main(){
	char *a[4] = {"�ɴ�Ѽ", "bokebi", "pikaqu", "mioawazz"};
	int i=0,b;
	for(i;i<4;i++)printf("%s\n",a[i]);
//	scanf("%d",&b);
	for(;;){
		scanf("%d",&b);
		if(b<=3&&b>=0){
			printf("%s\n",a[b]);
			break;
		}else printf("ɵ��\n"); 
	} 
	printf("ɵ�ƻ���ʲôҪ����\n");
	char c[80];
	scanf("%s",c);
	int f=9;
//	for(;;){
	
	for(i=0;i<4;i++){
		if(strcmp(c,a[i])==0){
		printf("�õ�����%s\n",a[i]);
		f=1;
		} 
		
	}if(f=9)printf("ɵ���ܲ��ܺú��䣿\n");
//	scanf("%s",c);}
}
