#include<stdio.h>

void swapPointer(int *pa, int *pb)
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}

int main()
{
	int n = 10;
	int m = 10;
	int *p = &n;
//	*p = value of n ;  p = address of n; 

	printf("%d %d %x \n",p, *p, p);
	printf(" %x \n %x", &n,&m);
	
	
// pointer++ => pointer move to the next address
	
	int number[10] = {1,2,5,123,6,7,4,2,11,10};
	int i;
	for (; i < 10; i++)
	{
		printf("Address of number[%d] is: %x \n", i, &number[i]);
	}
	
	int a = 2;
	int b = 1;
	swapPointer(&a, &b);
	printf("%d %d", a, b);
	
	
	
	return 0;
}
