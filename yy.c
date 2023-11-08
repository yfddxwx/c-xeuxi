#include <stdio.h>

int main (){
    char n;
    int c=0;
    scanf("%c",&n);
          for(;n!='\n';){
			  c++;
			  scanf("%d",&c);
              if(n >= '0' && n <= '9'){b++;}
              switch(n){
                  case ' ':a++;break;
                  default:d++;
                      d=d-b;
              }}
    printf("blank = %d, digit = %d, other = %d",a,b,d);
              
}
