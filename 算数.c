# include<stdio.h>
int main()
{
	int n,k,a=0,zh=0;
    scanf("%d %d",&n,&k);
    int i=n;
    while(i>1){
        int j=i-1;
        while(i%j!=0&&j>=2){
            j--;
        }if(j==1){
            a++;
            zh=zh+i;
			if(a==k||i==2){
            break;
        }
            printf("%d+",i);}
        i--;
    }printf("%d=%d",i,zh);
}

