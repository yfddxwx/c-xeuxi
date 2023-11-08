#include <stdio.h>
int main (){
 int A;
 int B;
 int C;
 int m,n,sum;
 scanf("%d",&A);
 for( m=0; m<A; m++){
  sum=0;
  scanf("%d",&B);
  for(n=0;n<B;n++){
   scanf("%d",&C);
   sum = sum+C;
  }
  if(sum%3==0 && sum%5==0 &&sum%7==0){
   printf("YES\n");
  }else{
   printf("NO\n");
  }
 } 
 return 0;
}
