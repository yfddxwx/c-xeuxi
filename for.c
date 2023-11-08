#include<stdio.h>
int main (){
	int i;
	int sum =0;
	for(i=1;i<500;i++){
		if(i%17==0){
			sum+=i;
		}
	}
	printf("%d", sum);
}
