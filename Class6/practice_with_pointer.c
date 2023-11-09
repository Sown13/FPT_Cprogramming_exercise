#include<stdio.h>

void printArr(int *pa, int length){
	int i = 0;
	for ( i = 0; i < length; i++)
	{
		printf("%d ", *pa++);
	}
}

int main(){
	
	int arr[13] = {1,2,3,4,2,3,4,5,6,7,6,7,1};
	
	printArr(arr, 13);
	
	return 0;
}
