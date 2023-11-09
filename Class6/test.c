#include<stdio.h>
#include<string.h>

int main()
{
 	char str[100];
 	int count[26] = 0;
	int i = 0;
	int n = 97;
	int m = 122;

	
	printf("Enter your string: ");
	gets(str);

	for( i = 0; i < strlen(str); i++)
	{
		count[tolower(str[i])- 97]++;
	}
		
	for( i = 0; i < 26; i++)
	{
		if(count[i] != 0)
		{
		printf("%c : %d \n", 97+i, count[i]);
		}
		;
	}
	return 0;
}
