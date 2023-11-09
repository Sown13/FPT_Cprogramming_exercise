#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "password_checker.h"

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


//int *testIntPtr(){
//	int i = 10;
//	return &i;
//}
//
//char *testCharPtr(){
//	char i = 'c';
//	return &i;
//}


int main() {
	// Student code here.
	
	while(1) {
//	int health = 0;
//	char *password = input_password_interface();
//	printf("\n + Pointer: %s \n", password);
//
//
//	health = check_password_health(password);
//	printf(" + Health main: %d \n", health);
//	
//	print_result_interface(health);
//	free(password);

//	int *testResult = testIntPtr();
//	printf("%d\n", *testResult);
//	
//	char *testResultChar = testCharPtr();
//	printf("%c\n", *testResultChar);
	
	print_result_interface(check_password_health(input_password_interface()));
	}

	
	return 0;
}

char *input_password_interface() {
	// Student code here.
	printf("======== Password Health Checker ========\n");
	printf("This program use to check your password health with 3 level: low, medium and strong.\n");
	printf("Enter password (password length must be no smaller than 10 and no lager than 20): ");
	
	char* password = malloc(50);
	
	gets(password);
	fflush(stdin);
	return password;
	
//	static char password[50];
//	gets(password);
//	fflush(stdin);
//	
//	char *ptr = password;
//	
////	char* ptr = malloc(strlen(password) + 1);
////    strcpy(ptr, password);
//	
//	int i = 0;
//	printf("Your password: ");
//	for(; i < sizeof(password); i++)
//	{
//		if(password[i] == '\0') {
//			break;
//		} 
//		printf("%c", password[i]);
//	}
//	printf("\n");	
	
//	printf("\n pointer function return: %s \n", password);

	
//	return ptr;
}

// Check password health.
// Return -1: password length is smaller than 10 characters.
// Return 0: password contains invalid characters.
// Return 1 or return 2: password health is low.
// Return 3: password health is medium.
// Return 4: password health is strong.


int check_password_health(char *password) {
   	// Student code here.
   	
   	char *tempPtr = password;
   	int i = 0;
   	int j = 0;
   	int isContainLower = 0;
   	int isContainUpper = 0;
   	int isContainSpecial = 0;
   	int isContainNumber = 0;
   	
//   	int passwordLength = 0;
//   	while(*tempPtr != '\0') {
//   		passwordLength++;
//   		tempPtr++;
//	}
	
	tempPtr = password;

   	
	if (strlen(password) < 10) {
		return -1;
	} else {
		for (i = 0; i < sizeof(upperCases); i++ ) {
			char* temp = strchr(password, upperCases[i]);
			if (temp != '\0'){
				isContainUpper = 1;
			}
			
			temp = strchr(password, lowerCases[i]);
			if (temp != '\0'){
			isContainLower = 1;
			}
			
			
			temp = strchr(password, specials[i]);
			if (temp != '\0'){
			isContainSpecial = 1;
			}
			
			temp = strchr(password, numbers[i]);
			if (temp != '\0'){
			isContainNumber = 1;
			}	
			
			
//			for(j = 0; j < sizeof(upperCases); j++) {
//				if (*tempPtr == upperCases[j]){
//					isContainUpper = 1;
//					break;
//				}
//			}
//			
//			for(j = 0; j < sizeof(lowerCases); j++) {
//				if (*tempPtr == lowerCases[j]) {
//					isContainLower = 1;
//					break;
//				}
//			}
//			
//			for(j = 0; j < sizeof(specials); j++) {
//				if (*tempPtr == specials[j]){
//					isContainSpecial = 1;
//					break;
//				}
//			}
//			
//			for(j = 0; j < sizeof(numbers); j++) {
//				if (*tempPtr == numbers[j]) {
//					isContainNumber = 1;
//					break;
//				}
//			}
//			tempPtr++;
		}
	}
	
	
	
	printf(" + Value each:  upper:%d  lower:%d   special:%d   number:%d \n" , isContainUpper, isContainLower , isContainSpecial , isContainNumber);
	printf(" + Total value: %d \n", (isContainUpper + isContainLower + isContainSpecial + isContainNumber ));
    return (isContainUpper + isContainLower + isContainSpecial + isContainNumber );
}

// Create interface to print result to monitor.

void print_result_interface(int health) {
    // Student code here.
    
    switch(health){
    	case 1:
    	case 2:
    		printf("\nPassword is LOW \n");
    		break;
    	case 3:
    		printf("\nPassword is MEDIUM \n");
    		break;
    	case 4:
    		printf("\nPassword is STRONG \n");
    		break;
    	case 0:
   			printf("\nInvalid character \n");
   			break;
   		default:
   			printf("\nYou need to enter a password that longer than 10\n");
   			break;
	}
	printf("----------------------------------------");
}




