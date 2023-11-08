#include<stdio.h>
int main()
{
    
    int n,i,j;
    scanf("%d",&n);
	int a[n][n];

    for(i=0;i<n;i++){
        j=0;
		while(j<n){
            scanf("%d",&a[i][j]);
			j++;
        }
    }
    int k=0,y=0,f=0,p=0;
    if(n==1)
    printf("0 0");
    else{
        i=0;
		while(i<n)
        {
            y=i;
            for(p=0;p<n;p++){
                if(a[i][k]<=a[i][p]){
                k=p;
                }
            }
        
            for(j=0;j<n;j++){
            if(a[y][k]>a[j][k]){
            y=j;
            break;
            }
        }
        if(i==y)
        {
            f=1;
            break;
        }i++;
        }
    if(f==1)
        printf("%d %d",i,k);
    else
         printf("NONE");
    }
    return 0;
    }


