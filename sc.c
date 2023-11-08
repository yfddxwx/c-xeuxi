#include<stdio.h>
int main(){
	char a = 'A';
	short int b = 600;
	int c = -5;
	printf("%p\n", &a);
	printf("%p\n", &b);
	printf("%p\n", &c);
	int *p1;
	short int *p2;
	int *p3;
	p1 = &a;
	p2 = &b;
	p3 = &c;
	printf("%p\n%p\n",&a,p1);
	printf("%c\n", *p1);
	*p1 = 'b';
	printf("%c\n", *p1);
	printf("%c\n",a);
//	return 0;
//	
	p1 = &c;
	*p1 = 1;
	printf("%d",c);
}
