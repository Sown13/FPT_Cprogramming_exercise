#include <stdio.h>
#include <stdlib.h>


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
	int i, j, N, temp;
	int *p, *pFirst;
	
	printf("Enter number of elements: ");
	scanf("%d", &N);

	p = (int*) malloc( N * sizeof(int));
	pFirst = p;
	
	for(i = 0; i < N; i++)
	{
		printf("Element : ");
		scanf("%d", p++);
	}


	int sum = 0;
	printf("%d size: ---- \n", sizeof(pFirst));
	for(i = 0; i < N; i++)
	{
		sum += *pFirst;
		printf(" %d ", *pFirst++);	
	}
	printf("sum = %d ", sum);
	
	
	return 0;
}
