#include <stdio.h>

int f( int n );

int main()
{
    int n;
    
    scanf("%d", &n);
    printf("%d\n", f(n));
    
    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */

int f( int n ){
    if(n==0)return 0;
    if(n==1)return 1;
    if(n>=2){
        n=(f(n-2)+f(n-1));
        
    }return n;
}
