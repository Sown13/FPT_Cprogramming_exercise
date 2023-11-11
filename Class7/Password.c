#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare conditions.
char upperCases[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
    'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
    'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

char lowerCases[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
    'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
    's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

char specials[] = {'`', '!', '\"', '?', '$', '?', '%', '^', '&',
    '*', '(', ')', '_', '-', '+', '=', '{', '[',
    '}', ']', ':', ';', '@', '\'', '~', '#', '|',
    '\\', '<', '>', '.', '?'};

char numbers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

//find any Upper char , at least 1
int checkUppercase(char* pass)
{
	int i = 0;
	for(i = 0; i < 26; i++)
	{
		char* test = strchr(pass, upperCases[i]);
		if(test != NULL) 
		{
			return 1; // find out a upper case
		}
	}

	return 0;	
}


int checkLowerCase(char* pass)
{
	int i = 0;
	for(i = 0; i < 26; i++)
	{
		char* test = strchr(pass, lowerCases[i]);
		if(test != NULL) 
		{
			return 1; // find out a upper case
		}
	}

	return 0;	
}

int main() {
	// Student code here.
	char* password = malloc(30);
	int checkUpper = 0;
	int checkLower = 0;
	
	printf("Enter a password: ");
	gets(password);
	
	printf("Password : %s with length %d", password, strlen(password));
	
	checkUpper = checkUppercase(password);
	checkLower = checkLowerCase(password);
	
	if((checkUpper + checkLower) == 2) 
	{
		printf("\nStrong password with upper case");
	}
	else 
	{
		printf("\nWeak password with upper case");
	}
	
	
	
	return 0;
}

