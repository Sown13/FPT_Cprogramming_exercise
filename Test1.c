#include <stdio.h>

int main()
{
	printf("test");
	
	int a = 3, b = 5, c = 7;
	
	if( a > b )
	{
		if( a > c)
		{
			printf("Max = %d%", a);
			return a;
		}
		else printf("Max = %d%", c);
	}
	else if ( b > c )
	{
		printf("Max = %d%", b);
	}	
		else printf("Max = %d%", c);
		return 0;
}
