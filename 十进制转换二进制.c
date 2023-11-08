#include <stdio.h>

void dectobin( int n );

int main()
{
    int n;
    
    scanf("%d", &n);
    dectobin(n);
    
    return 0;
}

/* 你的代码将被嵌在这里 */
//十进制转二进制方法：对2取余，逆序输出
 
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
