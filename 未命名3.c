#include<stdio.h>
int main(){
	int i=0;
	int b=0;
	int a;
	while(b<=1000){
		b=b+i*i;
		i++;
		i--;
		
	}
	printf("%d", i);
    return 0;
}
