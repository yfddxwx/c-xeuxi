#include <stdio.h>
int main(){
	printf("请输入一个整数");
	int num;
	scanf("%d, &num");
	int count=0;
	while(num>=count){
		printf("%d\n", count);
		count++;
	} 
    return 0;
}
