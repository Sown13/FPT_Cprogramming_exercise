#include<stdio.h>
#include <stdlib.h>

int *testPtr() {
//	int static arr[3] = {1,2,3};
	int arr[3] = {1,2,3};
	
	int *firstPtr;
	int *ptr = arr;
	firstPtr = ptr;
	int i =0;
	for ( i = 0 ; i < 3; i++) {
		printf("arr: %d ptr: %d ", arr[i], *ptr);
		printf("arr address: [%x ] || ptr adress: [%x ]\n", &arr[i], ptr);
		ptr++;
	}
	
	return arr;
}

void printPtr(int *ptr, int quantity) {
	int i = 0;
	printf("printPtr: \n");
	for ( i = 0 ; i < quantity; i++) {
		printf("%d ", *ptr);
		printf("%d", *ptr);
		printf("[%x ]\n", ptr++);
	}
}

int main() {
	int *ptr = testPtr();
	printPtr(ptr,3);
	printf("\n%x", ptr++);
	printf("\n%x", ptr++);
	printf("\n%x", ptr);
	return 0;
}
