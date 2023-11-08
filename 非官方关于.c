#include <stdio.h>
int main()
{
    double x;
    double y;
    scanf("%lf", &x);
    if(x>=0){
        y = sqrt(x);
    }else{
        y = (x+1)*(x+1)+2*x+1/x;
    }
    printf("f(%.2f) = %.2f", x, y);
    return 0;
}
