#include<stdio.h>

int main()
{
	char character;
	
	printf("Enter your character: ");
	character = getchar();
	printf("Your character: %c \n", character);
	char checkingChar = tolower(character);
	if( checkingChar < 97 || checkingChar > (97+25))
	{
		printf("You must enter a character from a-z \n ");
		return 1;
	}
	else if(checkingChar == 'a' || checkingChar == 'e' || checkingChar == 'u' || checkingChar == 'i' || checkingChar == 'o' )
	{
		printf("Your character is a Vowel \n");
	}
	else printf("Your character is a Consonant");
		
	return 0;	
}
