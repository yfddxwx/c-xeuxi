#include <stdio.h>
#include <math.h>

double funcos( double e, double x );

int main()
{    
    double e, x;

    scanf("%lf %lf", &e, &x);
    printf("cos(%.2f) = %.6f\n", x, funcos(e, x));
    
    return 0;
}

/* 你的代码将被嵌在这里 */
double funcos(double e, double x)
{   int i; 
	int temp = -1;
	double item = 1, p = 2, sun = 1,f1 = 1, f2=1; 
	for(;item > e;)
	{	
		i= 1;
		while( i <= p){
			f1 =f1* i;
			i++;
		}
		f2 = pow(x, p);
		item = f2 / f1;
		sun = sun + temp * item;
		p = p + 2;
		f1 = 1;
		temp = -temp;
	} 
	return sun;
}
