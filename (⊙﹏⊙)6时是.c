//
//#include <stdio.h>
//
//int  fun( int a[],int n );
//int main()
//{
//int a[10],i,n;
// scanf("%d",&n);
// for(i=0;i<n;i++)
// scanf("%d",&a[i]);
//printf("%d",fun(a,n));
//  return 0;
//
//}
//
///* 请在这里填写答案 */
#include<stdio.h>
int main()
{
    int a,i,j,q=0,w;
    scanf("%d",&a);
    int b[a];
    for(i=0;i<a;i++){
        scanf("%d",&w);
        b[i]=w;
    }
    for(i=0;i<a;i++){
        for(j=0;j<a;j++){
            if(b[i]==b[j]){
                q++;
            }
        }
    }
    if(q==1)printf("YES");
    if(q==0)printf("NO");
}
