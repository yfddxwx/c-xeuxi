#include <stdio.h>

#define MAXN 10

double f( int n, double a[], double x );

int main()
{
    int n, i;
    double a[MAXN], x;
    
    scanf("%d %lf", &n, &x);
    for ( i=0; i<=n; i++ )
        scanf("%lf", &a[i]);
    printf("%.1f\n", f(n, a, x));
    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
double f( int n, double a[], double x ){
    int i;
    double b=1;
    for(i=0;i<n;i++){
        b=b*x;
        a[0]+=a[i]*b;
    }
}
