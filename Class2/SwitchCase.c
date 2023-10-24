#include <stdio.h>

int main()
{
	char character;
	printf("Enter your character: ");
	character = getchar();
	printf("Your character: %c \n", character);
	
	if( character < 97 || character > (97+25))
	{
		printf("You must enter a character from a-z \n ");
		return 1;
	}
	
	switch(character)
	{
		case 'a':
		case 'e':
		case 'u':
		case 'i':
		case 'o': 
			printf("Your character is a Vowel");
			break;
		default:
			printf("your character is a Consonant");
			break;
	}
		
	return 0;
}
