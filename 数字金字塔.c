#include <stdio.h>

void pyramid( int n );

int main()
{    
    int n;

    scanf("%d", &n);
    pyramid(n);
    
    return 0;
}

/* 你的代码将被嵌在这里 */

void pyramid( int n ){
    int i,a=n-1,j,g=1;
    for(i=1;i<=n;i++){
        for(j=1;j<=a;j++){
            printf(" ");
        }for(j=1;j<=n-a;j++){
            printf("%d ",g);
        }a-=1;
        printf("\n");
        g++;
    }
}
