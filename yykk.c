#include <stdio.h>
int main()
{
    int r,d,l=2, e=0, i, f, j, a, b, g=0;
    scanf("%d",&r);
	i=0;
    
    while(i<r)
	{
        scanf("%d",&a);
        f=a;
        e=0;
        while(f)
		{
            e+=f%10;
            f/=10;
        }
        g=0;
		b=e;
        j=2;

        while(j<=9)
		{
            f=a*j;
            e=0;
            while(f)
			{
              e+=f%10;
              f/=10;
            }
            if(e==b)
			{ 
				g++;
			}j++;
        }
        if(g==8) 
		{
			printf("%d\n",b);
		}
        else     
		{	
			printf("NO\n");
		}i++;
    }
    return 0;
}
