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
void dectobin( int n ){
    
    if(n==1)printf("1");
    else if(n==0)printf("0");
    else{
        dectobin( n/2 );
        
        printf("%d", n%2);
    }
}
