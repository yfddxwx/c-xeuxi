#include <stdio.h>
#include <string.h>
//�����зֱ�������������С��20���ַ��������ַ����в�Ҫ���ֻ��з����ո��Ʊ����
int main(void)
{
char s1[20],s2[20];

int i = 0;

gets(s1);
gets(s2);

while(s1[i] != '\0' && s2[i] != '\0')
{
i++;
if(s1[i] > s2[i])
{
printf(">"); 
break;
}
else if(s1[i] < s2[i])
{
printf("<");
break;
}
else if(i+1 == strlen(s1))
{
printf("=");
break;
}
}
}

