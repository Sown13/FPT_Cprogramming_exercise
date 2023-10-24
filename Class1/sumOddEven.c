#include <stdio.h>

int main()
{
 int quantity;	
	
 printf("Enter your quantity of number: ");
 scanf("%d", &quantity);
 
  int numberList[quantity];
  int evenSum = 0, oddSum = 0;
  int i;
 
 for(i = 0; i< quantity; i++)
 {
 	printf("Enter your number %d: ", i+1);
 	scanf("%d", &numberList[i]);
 	if (numberList[i]%2 == 0){
 		evenSum += numberList[i];
	 } else oddSum += numberList[i];
 }
 
 printf("Your number: \n") ;
 for(i = 0; i< quantity; i++){
 	printf("Element%d: %d \n", i+1, numberList[i]);
 }
 
 printf("your odd sum: %d \n", oddSum);
 printf("your even sum: %d", evenSum);
 return 0;
} 
