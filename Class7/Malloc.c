#include <stdio.h>

void printArray(int *p, int length)
{
	int i = 0;
	for(i = 0; i < length; i++)
	{
		printf(" %d ", *p++);
	}
}

int main()
{
	int *p, *pFirst;
	int N = 0;
	int i = 0;
	
	printf("Enter number of elements: ");
	scanf("%d", &N);
	
	p = (int *) malloc(N * sizeof(int));
	pFirst = p; // same address
	
	for(i = 0; i < N; i++)
	{
		printf("Element : ");
		scanf("%d", p++);
	}
	
	printArray(pFirst, N);
	
	return 0;
}
