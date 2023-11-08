#include<stdio.h>
#include<malloc.h>
#define maxdata 1000;

typedef struct HNode*Heap;
struct HNode{
	int *data;
	int cap;
//	data[cap]; 
	int size;
}; 



int main(){
	
	return 0;
} 

Heap creatmaxheap(int maxsize){
	Heap H = (Heap)malloc(sizeof(struct HNode));
	H->data=(int*)malloc(sizeof(int)*(maxsize+1)); 
	H->size=0;
	H->cap=maxsize;
	H->data[0]=maxdata;
	return H;
}
