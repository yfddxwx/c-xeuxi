#include <stdio.h> 
int main(void)
{
	int s=6;
switch(++s)
{ case 6:
  case 7:s+=2;
  case 8:
  case 9:s+=2;
}printf("%d", s);
}

