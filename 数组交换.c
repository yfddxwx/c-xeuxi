#include <stdio.h>
int main()
{
	int a1 = 3;
 	int a2 = 4;
 	int a3 = 1;
 	int a4 = 2;
 	int array[5] = {3,4,1,2,9};
 	int length = 5;
 	int i;
// 	for (i=0;i<length/2;i++){
//  		int tmp=array[length-1-i];
//  		array[length-1-i]=array[i];
//  		array[i]=tmp;
// 	}
// 	for(i=0;i<length;i++){
//  		printf("%d\n",array[i]);
//	}




	int a=array[0];
	for (i=0;i<length;i++){
  		array[i]=array[i+1];
 	}array[length-1]=a;
 	for(i=0;i<length;i++){
  		printf("%d\n",array[i]);
	}
}





