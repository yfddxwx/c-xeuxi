#include <stdio.h>

void dectobin( int n );

int main()
{
    int n;
    
    scanf("%d", &n);
    dectobin(n);
    
    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
//ʮ����ת�����Ʒ�������2ȡ�࣬�������
 
void dectobin( int n ){
    int a[n];
    if(n==1)printf("1");
    else if(n==0)printf("0");
    else{
        dectobin( n/2 );
        a[n]=0;
        printf("%d", n%2);
    }
}
