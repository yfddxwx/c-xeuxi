#include <stdio.h>

double fact( int n );
double factsum( int n );

int main()
{
    int n;

    scanf("%d",&n);
    printf("fact(%d) = %.0f\n", n, fact(n));
    printf("sum = %.0f\n", factsum(n));
        
    return 0;
}

/* 你的代码将被嵌在这里 */

double fact( int n ){
    int i,a=1;
    for(i=1;i<=n;i++){
        a*=i;
    }return a;
}

double factsum( int n ){
    int i,b=1;
    if(n==0)b=0;
    else for(i=2;i<=n;i++){
        b+=fact(i);
    }return b;
}
