//#include<stdio.h>
//#include<string.h>
//int main()
//{
//	char str1[20]={"hello"},str2[10]={"world"};
//	printf("%s\n",strcpy(str1,str2));
//	printf("%s\n",str1);
//	printf("%s\n",str2);
//	return 0;
//} 
/*
#include<stdio.h>
#include<string.h>
struct cat{
	char name[80];
	float age;
	int gender;
	
};
int main()
{
//	char str1[20]={"hello"},str2[10]={"world"};
//	printf("%s\n",strcpy(str1,str2));
//	printf("%s\n",str1);
//	printf("%s\n",str2);
	struct cat cat;
	cat.age = 9;
	cat.gender = 0;
	strcpy(cat.name,"miaowo");
	
	return 0;
} */
/*
#include<stdio.h>
#include<string.h>
struct students{
	char name[80];
	int xuehao;
	float cji[3];
	
};
int main()
{
//	char str1[20]={"hello"},str2[10]={"world"};
//	printf("%s\n",strcpy(str1,str2));
//	printf("%s\n",str1);
//	printf("%s\n",str2);
	struct students cat=
	{
		"yifd",
		100,
		{
			100,50,60
		}
	};
	int cour = 3,i;
	float sum = 0;
	for(i=0;i<3;i++){
		sum = sum + cat.cji[i];
	}
	float f = sum/3;
	
	
	
	return 0;
} */ 
#include<stdio.h>
int main()
{
    int n,i,j,e=0;
    scanf("%d",&n);
	int a[n][n];
    for(e=0;e<n;e++){
        e++;
    }
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


