#include<stdio.h>
#include<stdlib.h>
int main(){
	int i;
	void *q;
	q=&i;
	int cnt = 0;
//	while((q=malloc(100*1024*1024))){
//		cnt++;
//		
//	}
	free(NULL);
	printf("%d00",cnt);
}
