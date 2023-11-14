#include <stdio.h>
struct Product
{
	int id;
	char name[50];
	char type[20];
	double price;
};


int main() {
	struct Product product;
	
	printf("\n     Enter product name: ");
	fflush(stdin);
	gets(product.name); 
	
	printf("\n     Enter product type: ");
	fflush(stdin);
	gets(product.type); 
		
	printf("\n     Enter product price: ");
	scanf("%lf", &product.price);
		
		
//		Write to file
	
	FILE *pfile = fopen("product.txt", "a");
	if (pfile != NULL) {
		printf("Create file successfully");
		
		fprintf(pfile, "%s",product.name);
		fclose(pfile);
	}	
	
	
	struct Product productList[50];
	pfile = fopen("product.txt", "a");
		if (pfile != NULL) {
		printf("Create file successfully");
//		for (i = 0; i< )
		fscanf(pfile, "%s",product.name);
		fclose(pfile);
	}	
	
	return 0;
}
