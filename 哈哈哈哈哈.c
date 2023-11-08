#include <stdio.h>

int main()
{
    int a;
    scanf("%d",&a);
	if(a>=100&&a<=999){
        if(pow(a/100,3)+pow(a/10%10,3)+pow(a%100%10,3)==a){
                printf("yes");
            }
        else{
            printf("no");
        }
    }
    else{
        printf("Invalid Value.");
    }
	return 0;
}
