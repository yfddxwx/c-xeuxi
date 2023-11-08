# include <stdio.h>
# include <string.h>
int main (){
    char arry[80];
    int i, count = 0,k, b = 0,f1=0,f2=0,f3=0,j;
    char c[81];
    gets(arry);
    k = strlen(arry);
    for(;arry[i] != '\0';) {
		
        
        if (arry[i] >= 'A' && arry[i] <= 'Z')
        {f3=1;
            f2 = 1;
            for (j = 0; j < count; j++)
                if (c[j] == arry[i])
                    f1 = 1;
            if (f1 == 0)
            {
                c[count] = arry[i];
                printf("%c", arry[i]);
                count++;
            }
            f1 = 0;
        }i++;
	}
    if(f3 ==0 ){
        printf("Not Found");
        return 0;
    }
}



#include<stdio.h>
int main(void) {
	int i = 0,j=0,s,f1=0,f2=0,count=0;
	long number = 0;
	char str[81];
    char a[81],c[81];
	gets(a);
	for(;a[i] != '\0';) {
		if(str[i] >= 'A' && str[i] <= 'Z'){
		    a[j]=str[i];
            j++;
        }
        
        if (a[i] >= 'A' && a[i] <= 'Z')
        {
            f2 = 1;
            for (int j = 0; j < count; j++)
                if (c[j] == a[i])
                    f1 = 1;
            if (f1 == 0)
            {
                c[count] = a[i];
                printf("%c", a[i]);
                count++;
            }
            f1 = 0;
        }i++;
	}
    if(f2!=1)printf("Not Found");
// 	i=0;
//         for(;i<j;i++)
//     printf("%c", a[i]);
	return 0;
}
