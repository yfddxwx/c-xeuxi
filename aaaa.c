#include <stdio.h>

int main()
{
	
	double x;
    double y;
	scanf("%lf", &x);
	if ( x != 0 ) {
    	y = 1/x; 
	}
	else {y=0;
	}
printf("f(%.1f) = %.1f", x, y);

	

	return 0;
}

