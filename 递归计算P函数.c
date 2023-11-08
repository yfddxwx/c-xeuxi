#include <stdio.h>

double P( int n, double x );

int main()
{
    int n;
    double x;
    
    scanf("%d %lf", &n, &x);
    printf("%.2f\n", P(n,x));
    
    return 0;
}

/* 你的代码将被嵌在这里 */

double P( int n, double x ){
    double result;
    if(n ==0) result = 1;
    else if(n == 1)
        result = x;
    else
        result = ((2*n-1)*P(n-1,x)-(n-1)*P(n-2,x))/n;
    return result;
 
 
 
}
