#include<stdio.h>
int main()
{
    int m,n;
    int sum=0,sum2=0,x;
    int i,b=0,j;
    scanf("%d %d",&m,&n);
    for(i=m;i>1;i--)
    {
        for( j=2;j<i;j++)
        {
           x=i%j;//i��j��2��ʼȡ��
            sum=sum+x;//�����������sumһ����ֵ
           if(x==0)//֤�����������Ϳ����������forѭ��
           {  sum=0;
               break;}
                      //  sum=sum+x;//�����������sumһ����ֵ
        }
        if(sum!=0)//����������ͽ������if���
        {
            b++;//���Ѿ����˼�������
            sum2=sum2+i;//�������ĺ�
            if(b==n||i==2 )//�Ѿ���10���������˻�������������10������i�Ѿ�Ϊ2��
            {break;}
            printf("%d+",i);
        }
    }
    printf("%d=%d",i,sum2);
    return 0;
}
