#include<stdio.h>
#include <stdlib.h>

int main (){
	
	char **names;
	char *name;
	
	int nameLength, quantityName;
	
	scanf("%d", quantityName);
	
	names = (char**) malloc(quantityName * sizeof(char*));
	
	int i = 0;
	for( i = 0; i < quantityName; i++) {
		names[i] = (char*) malloc (30 * sizeof(char));
	}
	
	printf("\n");
	for(i = 0; i <quantityName; i++) { 
		fflush(stdin);
		gets(names[i]);
	}
	
	return 0;
	
}
