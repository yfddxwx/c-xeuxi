#include<stdio.h>
int main()
{
 printf("������һ������\n");
 int num;
 scanf("%d", &num);
 int guess = 125;
 while(num!=guess){
 if(num<125){
 	printf("ƫС\n");
 }if(num>125){
 	printf("pianda\n");
 } 
  scanf("%d", &num);

  }
 printf("�µ���\n");
    return 0;
}
