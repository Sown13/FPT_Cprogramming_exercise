#include <stdio.h>

void changeValue(int n)
{
	n = n + 5;
	printf("\nInside function N = %d", n);
}

void changeValueReference(int* p)
{
	*p = *p + 5;
	printf("\nInside function N = %d", *p);
}

int main()
{
	int number = 10;
	changeValueReference(&number);
	printf("\nNumber in main = %d", number);
	
	return 0;	
}
