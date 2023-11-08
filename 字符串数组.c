#include <stdio.h>

void max_row(int (*arr)[20], int m, int n);

int main(void)
{
    int m, n;
    int hang, lie, juZhen[20][20];

    scanf("%d%d", &m, &n);

    for (hang = 0; hang < m; hang++)
    {
        for (lie = 0; lie < n; lie++)
        {
            scanf("%d", &juZhen[hang][lie]);
        }
    }
    max_row(juZhen, m, n);  
    return 0;
}

/* 请在这里填写答案 */
void max_row(int (*arr)[20], int m, int n)
{
int i,j,t;
for(i=0;i<m;++i)
{
	t=(*arr)[0];
for(j=0;j<n;++j)
	if((*arr)[j]>t)
		t=(*arr)[j];
printf("The max in line %d is:%d\n",i+1,t);
++arr;
}
}

