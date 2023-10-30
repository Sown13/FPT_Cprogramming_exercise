#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

// ex1 - find area and perimeter of a cicrle

void calAreaAndPerimeterOfCircle(float radius)
{
	float perimeter = radius * 2 * 3.14;
	float area = perimeter * perimeter / (4 * 3.14); 
	printf("Perimeter = %f \n", perimeter);
	printf("Area = %f \n", area);
}

// ex2 - print 100 95 90 ... 5 

void printSeries100To5(void)
{
	int i;
	for(i = 100; i >= 5; i-=5)
	{
		printf("%d \n", i);
	}
}

// ex3 - cal sum of odd and even between 2 number

void calSumOddAndEvenBetween2Number(int number1, int number2)
{
	int evenSum = 0;
	int oddSum = 0;
	if(number1 > number2)
	{
	 number1 = number1 + number2;
	 number2 = number1 - number2;
	 number1 = number1 - number2;
	}
	
	for(number1; number1 <= number2; number1++)
	{
		if( number1 % 2 == 0)
		{ 
			evenSum += number1;
		} else
		{
			oddSum += number1;
		} 
	}
	printf("Even sum = %d \n", evenSum);
	printf("Odd sum = %d \n", oddSum);
}

// ex4 - fibonacci

void printFibonacci(int quantity)
{
	int element1 = 0 , element2 = 1;
	int i;
	if( quantity < 1 )
	{
		printf("Wrong quantity, please enter an integer > 0 \n");
		return;
	}
	else
	{
		for( i = 0; i < quantity; i++) 
		{
			printf("%d \n", element2);
			element2 += element1;
			element1 = element2 - element1;
		}
	}
}

// ex5 - nested loop

void printfParttern()
{
	int i, j;
	for( i = 0 ; i < 6; i++)
	{
		for(j = 6 - i; j > 0; j--)
		{
			printf("*");
		}
		printf("\n");
	}
}

//ex 6,7 print 1 / 23 / 456/ 78910...

void printTriangle(int loopTimes, int maxPrint)
{
	int i, j, startPoint;
	startPoint = 1;
	for (i = 0; i < loopTimes; i++)
	{
		for ( j = 0; j < i+1; j++)
		{
			if (startPoint > maxPrint)
			break;
			if (startPoint % 10 == 0)
			continue;
			printf("%d ", startPoint++);
		}
		printf("\n");
	}	
}

// ex8  check prime number

int checkPrimeNumber(int number)
{
	int isPrime = 1;
	int i ;
	if (number == 0 || number == 1)
	{
//		printf("%d is not a Prime ", number);
		isPrime = 0;
		return isPrime;
	}
	for (i = 2; i < sqrt(number); i++ )
	{
		if (number % i == 0)
		{
//			printf("%d is not a Prime number!", number);
			isPrime = 0;
			break;
		}
	}
	if(isPrime == 1)
	{
//		printf("%d is a Prime \n", number);
	}
	return isPrime;
} 

// ex9 - print prime number until max value given

void printPrimeNumber(int max)
{
	int i;
	for( i = 0; i < max ; i++)
	{
		if (checkPrimeNumber(i))
		{
			printf("%d \n", i);
		}
	}
}

//ex10 - print max of array

void printMax(int numberList[], int length)
{
	int i, j;
	int max = numberList[0];
	int position = 0;
	for (i = 1; i < length; i++)
	{
		if(max < numberList[i]) {
		max = numberList[i];
		position = i + 1;			
		}

	}
	printf("max = %d at position %d \n", max, position);
} 

// ex11 - print second max of an array

void removeElement(int array[], int size, int number) {
	int index = 0;
	int i, j;
	for (i = 0; i < size; i++)
	{
		if(number == array[i])
		index = i;
	}
    if (index < 0 || index >= size) {
        printf("Invalid index\n");
        return;
    }

    for (j = index; j < size - 1; j++) {
        array[j] = array[j + 1];
    }
}

void printSecondMax(int numberList[], int length)
{
	int i, j, k;
	int nowMax = numberList[0];
	int lastMax = nowMax;
	for(i = 0; i < sizeof(numberList); i++)
	{
		for (j = 1; j < sizeof(numberList); j++)
		{
			if(nowMax < numberList[j])
			nowMax = numberList[j];
		}
		removeElement(numberList, length, nowMax);
		lastMax = nowMax;
		nowMax = numberList[0];
		for (k = 1; k < sizeof(numberList) - i; k++)
		{
			if(nowMax < numberList[j])
			nowMax = numberList[j];
		}
		if (lastMax != nowMax)
		{
			printf("%d is second max! \n", nowMax);
			return;
		}
	}
} 

//ex12 - sum of 2 2 dimension array 

// 2D array is saved in consicutive memory slot (for example: arr[2][3] is saved by 6 consicutive slot); 

void calSumOf2DimensionMatrix()
{
	int multiDArray1[3][3] = {{1,2,3},{1,2,3},{3,4,5}};
	int multiDArray2[3][3] = {{3,5,1},{3,4,3},{3,4,5}};
	int i, j;
	int sumArr[3][3];
	for( i = 0; i < 3; i++)
	{
		printf("{");
		for( j = 0; j < 3; j++)
		{
			sumArr[i][j] = multiDArray1[i][j] + multiDArray2[i][j];
			printf("%d ", sumArr[i][j]);
		}
		printf("} \n");
	}
}

// ex13 multi 2d array

void calMulti2DimensionMatrix()
{
	int multiDiArray1[3][4] = {{1,2,3,4},{1,2,3,2},{3,4,5,2}};
	int multiDiArray2[4][2] = {{3,5},{3,4},{3,4},{2,3}};
	int i, j, k;
	int multiArr[3][3];
	int tempValue = 0;
	
	for( i = 0; i < 2; i++)
	{
		
		for( j = 0; j < 3; j++)
		{
			multiArr[i][j] = 0;
			for( k = 0; k < 4; k++)
			{
				multiArr[i][j] += multiDiArray1[i][k] * multiDiArray2[k][j];
			}
			printf("%d ", multiArr[i][j]);
		}
		printf("\n");
	}
}


// ex14  sort array

void selectedSort()
{
	int arr[11] = {1,5,3,4,2,6,8,7,10,9,10};
	int i, j;
	int tempIndex = 0;
	int min = 0;
	
	for( i = 0; i < 11; i++)
	{
		min = arr[i];
		tempIndex = i;
		
		for (j = i + 1; j < 11; j++ )
		{
			if( arr[j] < min)
				{
					min = arr[j];
					tempIndex = j;
				} 
		}
		arr[tempIndex] = arr[i];
		arr[i] = min;
		
		printf("%d ", arr[i]);
	}
	printf("\n");
}


void bubbleSort()
{
	int arr[11] = {2,5,3,4,1,6,8,7,10,11,10};
	int i, j;

	for( i = 0; i < 11 ; i++ )
	{
		for ( j = 10; j > i; j--)
		{
			if(arr[j] < arr[j-1])
			{
				arr[j] = arr[j] + arr[j-1];
				arr[j-1] = arr[j] - arr[j-1];
				arr[j] = arr[j] - arr[j-1];
			}
		}
	}
	
	for( i = 0; i < 11; i++)
	{
		printf(" %d ", arr[i]);
	}
	printf("\n");
}

// ex15 find longest name

void findLongestName()
{
	char nameList[5][30];
	char name[30];
	int lengthList[5];
	int i, j;
	int count = 0;
	int longestLength = 0;
	int longestIndex = 0;
	
	for ( i = 0; i < 5 ; i++)
	{
		printf("Enter the %d name: ", i+1);
		gets(name);
		strcpy(nameList[i], name);
		printf("%s \n", nameList[i]);
		fflush(stdin);
	}

	for ( j = 0; j < 5; j++)
	{
		lengthList[j] = strlen(nameList[j]);
	}
	for ( j = 0; j < 5; j++)
	{
		longestLength  = lengthList[j];
		longestIndex = j;
		if(lengthList[j] > longestLength)
		{
			longestLength = lengthList[j] ;
			longestIndex = j;
		}
	}
	printf("the longest name is %s \n", nameList[longestIndex]);
}

// ex16 sort names by alphabet

void sortByAlphaBet()
{
	char nameList[5][30];
	char name[30];
	int i, j ;
	char firstChar[5];
	int indexOrder[5];
	
	
	// get name from user input
	for ( i = 0; i < 5 ; i++)
	{
		printf("Enter the %d name: ", i+1);
		gets(name);
		strcpy(nameList[i], name);
		printf("%s \n", nameList[i]);
		fflush(stdin);
	}
	
	// make an array of char represent for first character in those name that was entered
	for( i = 0; i < 5; i++)
	{
		firstChar[i] = tolower(nameList[i][0]);
	}
	
	// sort the char array by selected sort and put it to an array by order
	for( i = 0; i < 5; i++)
	{
		char min = firstChar[i];
		int tempIndex = i;
		
		for (j = i + 1; j < 5; j++ )
		{
			if( firstChar[j] < min)
				{
					min = firstChar[j];
					tempIndex = j;
				} 
		}
		indexOrder[i] = tempIndex;
		firstChar[tempIndex] = firstChar[i];
		firstChar[i] = min;
	}
	
	for( i = 0; i < 5; i++)
	{
		printf("%d ", indexOrder[i]);
		printf("%s \n", nameList[indexOrder[i]]);
	}
	
}


int main()
{	
	int isRunning = 1;
	int choice;
	int test = 10;
	int sum = 0;
	int numberList[10] = {1,5,3,10,25,31,45,45,45,39};
	while( isRunning != 0)
	{
		printf("Enter number from 1 to 20 to check the exercise or 0 to exit: ");
		scanf("%d", &choice);
		fflush(stdin);
		switch(choice)
		{
			case 1: 
				printf("Ex1 ------------------------------------------\n");
				calAreaAndPerimeterOfCircle(10.5);
				break;
			case 2:
				printf("Ex2 -------------------------------------------\n");
				printSeries100To5();
				break;
			case 3:
				printf("Ex3 ---------------------------------------------\n");
				int number1, number2;
				printf("Enter your first number: ");
				scanf("%d", &number1);
				printf("Enter your second number: ");
				scanf("%d", &number2);
				calSumOddAndEvenBetween2Number(number1, number2);
				break;
			case 4:
				printf("Ex4 ---------------------------------------------\n");
				int quantity;
				printf("Enter your quantity of fibonacci that you to print: ");
				scanf("%d", &quantity);
				printFibonacci(quantity);
				break;
			case 5:
				printf("EX5 ----------------------------------------\n");
				printfParttern();
				break;
			case 6:
				sum = test++ + ++test;
				printf("sum = %d \n", sum);
				break;
			case 7:
				printTriangle(10,50);
				break;
			case 8:
				checkPrimeNumber(151);
				break;
			case 9:
				printPrimeNumber(1000);
				break;
			case 10:
				printMax(numberList,10);
				break;
			case 11:
				printSecondMax(numberList, 10);
				break;
			case 12:
				calSumOf2DimensionMatrix();
				break;
			case 13:
				calMulti2DimensionMatrix();
				break;
			case 14:
				selectedSort();
				bubbleSort();
				break;
			case 15:
				findLongestName();
				break;
			case 16:
				sortByAlphaBet();
				break;
			case 0:
				isRunning = 0;
				break;
			default:
				printf("Wrong input, please enter from 1 - 20 or 0 to exit! \n");
				break;
		}
	}
	return 0;
}
