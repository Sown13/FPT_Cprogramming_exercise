#include<stdio.h>
#include<stdlib.h>

void printArr(int *pa, int length){
	int i = 0;
	for ( i = 0; i < length; i++)
	{
		printf("%d ", *pa++);
	}
}

int main(){
	int quantity = 0;
	printf("Enter the quantity of numbers that you want to enter: ");
	scanf("%d", &quantity);
	
	double *ptr;

	ptr = (double*) malloc (quantity * sizeof(double));
	
	
//	since the pointer will be pointed to the outside of array after last of loop, so we need a pointer to save the first pointer and print from there;
//  we also can use ptr-- but it take too much of time
	double *pFirst = ptr;
	
	int i = 0;
	double sum = 0;
	if(ptr != NULL)
	{
		for(i = 0; i < quantity; i++){
		printf("Enter your number %d:  ", i+1);
		scanf("%lf", ptr++);
		fflush(stdin);
		}
		
	
		for (i = 0; i < quantity; i++){
			sum += *pFirst;
			printf("%lf \n", *pFirst++);
		}
	}
	
	printf("%lf ", sum);
	
	return 0;	
}


//int main(){
//	int quantity = 0;
//	printf("Enter the quantity of numbers that you want to enter: ");
//	scanf("%d", &quantity);
//	
//	int *ptr, *pFirst;
//
//	ptr = (int*) malloc (quantity * sizeof(int));
//	
//	
////	since the pointer will be pointed to the outside of array after last of loop, so we need a pointer to save the first pointer and print from there;
////  we also can use ptr-- but it take too much of time
//	pFirst = ptr;
//	
//	int i = 0;
//	if(ptr != NULL)
//	{
//		for(i = 0; i < quantity; i++){
//		printf("Enter your number %d:  ", i+1);
//		scanf("%d", ptr++);
//		fflush(stdin);
//		}
//		
//		int sum = 0;
//		for (i = 0; i < quantity; i++){
//			sum += *pFirst;
//			printf("%d \n", *pFirst++);
//		}
//		printf("%d ", sum);
//	}
//	
////	double a = 2.5;
////	printf("%lf", a );
//
////	free(ptr);
////	free(pFirst);
//
//	return 0;	
//}
