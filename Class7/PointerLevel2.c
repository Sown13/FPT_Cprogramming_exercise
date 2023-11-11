#include <stdio.h>

int main()
{
	char **pNames;
	int N = 0, len = 30;
	int i = 0;
	
	printf("Enter number of names: "); // 5 names
	scanf("%d", &N);
	
	pNames = (char**) malloc( N * sizeof(char*));
	
	for(i = 0; i < N; i++)
	{
		pNames[i] = malloc( 30 * sizeof(char)); 
	}
	
	printf("\nEnter name: ");
	for(i = 0; i < N; i++)
	{
		fflush(stdin);
		printf("Name: ");
		gets(pNames[i]);
	}
	
	return 0;	
}
