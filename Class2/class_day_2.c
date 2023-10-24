#include<stdio.h>

int main()
{
	
	int mark;
	printf("Enter your mark: ");
	scanf("%d", &mark);
	
	if(mark < 0 || mark > 10) {
		printf("Invalid value, mark must be a value from 0 - 10");
		return 1;
	}
	else if (mark < 4) {
		printf("Failed");
	}
	else if (mark < 6) {
		printf("Pass");
	}
	else if (mark < 8) {
		printf("Good");
	}
	else {
		printf("Exellent");
	}
	return 0;
}
