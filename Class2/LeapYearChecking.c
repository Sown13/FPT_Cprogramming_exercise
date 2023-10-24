#include<stdio.h>

int isLeapYear(int year)
{
	if( year % 400 == 0)
	{
		printf("%d is a leap year", year);
	}
	else if( year % 4 == 0 && year % 100 != 0)
	{
		printf("%d is a leap year", year);
	}
	else {
		printf("%d is Not a leap year", year);
		return 1;
	}
	
	return 0;
}

int main()
{
	int year, month;
	printf("Enter your year: ");
	scanf("%d", &year);
	printf("Enter your month: ");
	scanf("%d", &month);
	
	switch(month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			printf("month %d year %d have : 31 days", year, month);
			break;
		case 2: 
			if(isLeapYear(year) == 0)
			{
				printf("month %d year %d have : 29 days", year, month);
				break;	
			}
			else printf("month %d year %d have : 28 days", year, month);
			break;
		default:
			printf("month %d year %d have : 30 days", year, month);
			break;
	}
	
	return 0;
}
