#include<stdio.h>
int main()
{
 int arr[8]={1,2,3,6,7,8,9,0};
 int length=8;
 int i=0,d=0,e,f,g;
 int a=1;
 for(i=0;i<length;i++){
  if(arr[i]<arr[i+1]){
   a++;
  }else if(arr[i]>arr[i+1]){
   d=a;
   a=0;
   if(e>d){
    d=e;
   } else{
    
   }
   e=d;
  }
 }
  printf("%d",d);
 
}
