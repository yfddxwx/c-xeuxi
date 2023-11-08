# include<stdio.h>
int main()
{
	int n,i,j,k,a=2;
	scanf("%d",&n);
	k=n-1;
	i=1; 
	while(i<=n){
	    j=1;
		while(j<=k){
			printf(" ");
			j++;
		}
		j=1;
		while(j<=n-k){
			printf("* ");
			j++;
		}
		if(k==0){
			a=-a;
		}
		k-=a;
		printf("\n");
		i++;
	}
}

