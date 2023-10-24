#include <stdio.h>
#include <math.h>

int main()
{
	int a,b,c;
	float x1, x2;
	float delta;
	
	printf("Enter a: ");
	scanf("%d", &a);
	
	printf("Enter a: ");
	scanf("%d", &b);
	
	printf("Enter a: ");
	scanf("%d", &c);
	
	printf("Your number you entered: %d, %d, %d \n", a, b, c);
	
	delta = b*b - 4*a*c;
	
	if(delta > 0){
		x1 = (-b + sqrt(delta)) / 2*a;
		x2= (-b - sqrt(delta)) / 2*a;
		printf("x1 = %d, x2 = %d", x1,x2);
	}
	else if (delta == 0){
		x1 = x2 = -b/2*a;
		printf("x1 = x2 = %d", x1);
	}
	else printf("Null");
	
	return 0;
}
