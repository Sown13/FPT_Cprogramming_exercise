#include <stdio.h>
#include <math.h>

//ex1 - calculate sum of number from user input----------

int calSumFromInput(int quantity){
	int sum = 0;
	
	int count = 0;
	while(count < quantity){
		int input;
		printf("Item %d: ", count+1);
		scanf("%d", &input);
		sum += input;
		count++;
	}
	
	return sum;
}

//ex2 - calculate sum of even and odd from user input----------

void calSumOddAndEvenFromInput(int quantity){
	int evenSum = 0;
	int oddSum = 0;
	
	int count = 0;
	while(count < quantity){
		int input;
		printf("Item %d: ", count+1);
		scanf("%d", &input);
		if(input%2 == 0){
			evenSum += input;
		}
		else oddSum += input;
		count++;
	}
	
	printf("Sum of even number = %d \n", evenSum);
	printf("Sum of odd number = %d \n", oddSum);
}

//ex3 calculate sum of even digits and odd digits of an integer

void calSumOddAndEvenDigit(int integer){
	int evenDigitSum = 0;
	int oddDigitSum = 0;
	
	while(integer != 0){
		int digit;
		digit = integer % 10;
		integer = integer/10;
		if(digit%2 == 0){
			evenDigitSum += digit;
		}
		else oddDigitSum += digit;
	}
	printf("Sum of even digit = %d \n", evenDigitSum);
	printf("Sum of odd digit = %d \n", oddDigitSum);
}

//ex4 find result of  a quadratic equation ax^2 + bx + c = 0;

void calQuadraticEquation(int a, int b, int c){
	float result1, result2, delta;
	delta = b*b - 4*a*c;
	if(delta < 0){
		printf("Equation has no result! \n");
	} else if (delta == 0){
		result1 = result2 = -b/(2*a);
		printf("Equation has 1 result is: %f \n", result1);
	} else {
		result1 = (-b + sqrt(delta)) / (2*a);
		result2= (-b - sqrt(delta)) / (2*a);
		printf("Equation has 2 result as follow: \n");
		printf("result 1 = %f \n", result1);
		printf("result 2 = %f \n", result2);				
	}
}

//Main

int main(){
	int isRunning = 1;
	while(isRunning == 1){
	printf("xxxx------------------------------------------------\n");
	printf("Menu: \n");
	printf("1- ex1: calculate sum of number from user input \n");
	printf("2- ex2: calculate sum of even and odd from user input \n");
	printf("3- ex3: calculate sum of even digits and odd digits of an integer \n");
	printf("4- ex4: find result of a quadratic equation \n");
	printf("0- Close program \n");	
	printf("------------------------------------------------xxxx\n");
	
	int choice;
	printf("Enter your choice (a number from 0 to 4): ");
	scanf("%d", &choice);
	
	int quantity;
	int number;
	int sum;
	switch(choice){
		case 1:
				printf("Enter the quantity of numbers that you want to input: ");
				scanf("%d", &quantity);
				printf("Number of element: %d \n", quantity);
				
				sum = calSumFromInput(quantity);
				printf("Sum = %d \n", sum);
				break;
		case 2:
				printf("Enter the quantity of numbers that you want to input: ");
				scanf("%d", &quantity);
				printf("Number of element: %d \n", quantity);
				
				calSumOddAndEvenFromInput(quantity);
				break;
		case 3:
				printf("Enter your number: ");
				scanf("%d", &number);
				
				calSumOddAndEvenDigit(number);
				break;
		case 4:
				printf("Enter your 1st coefficient: ");
				int a;
				scanf("%d", &a);
				
				printf("Enter your 2nd coefficient: ");
				int b;
				scanf("%d", &b);
				
				printf("Enter your constant: ");
				int c;
				scanf("%d", &c);
				
				calQuadraticEquation(a,b,c);
				break;
		case 0:
				isRunning = 0;
				break;
		default:
				printf("Invalid choice \n");
				break;	
		}
	}
	printf("Program Closing...");
	
	return 0;
} 


