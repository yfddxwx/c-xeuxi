#include<stdio.h>
int main()
{
 printf("请输入一个整数\n");
 int num;
 scanf("%d", &num);
 int guess = 125;
 while(num!=guess){
 if(num<125){
 	printf("偏小\n");
 }if(num>125){
 	printf("pianda\n");
 } 
  scanf("%d", &num);

  }
 printf("猜到了\n");
    return 0;
}
