#include <stdio.h>

#include <stdio.h>

int main(){
    int a, b, c, d, e;
    int f;
    scanf("%d %d",&a,&b);
    c=a+b;
    d=a-b;
    e=a*b;
    f=a/b;
    
    printf("%d + %d = %d\n",a,b,c);
    printf("%d - %d = %d\n",a,b,d);
    printf("%d * %d = %d\n",a,b,e);
    if(f%1==0){
        printf("%d / %d = %.0f",a,b,c);
    }else{
        printf("%d / %d = %.2f",a,b,c);
    }
}
