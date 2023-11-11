#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define QUANTITY 50

struct Product
{
	int id;
	char name[50];
	char type[20];
	double price;
};



void menu()
{
	printf("\n");
	printf("\n");
	printf("   ===========MENU===========   ");
	printf("\n|1. Add new Product           |");
	printf("\n|2. List all Product          |");	
	printf("\n|3. Find Product by price     |");
	printf("\n|4. Find person by name       |");
	printf("\n|5. Sort by name              |");	
	printf("\n|6. Sort by price             |");	
	printf("\n|7. Update Product by ID      |");	
	printf("\n|8. Delete a Product from list|");	
	printf("\n|0. Exit                      |");
	printf("\n   ===========END===========  ");
	printf("\n");
}

struct Product inputProduct() {
	struct Product product;
	
	printf("\n     Enter product name: ");
	fflush(stdin);
	gets(product.name); 
	
	printf("\n     Enter product type: ");
	fflush(stdin);
	gets(product.type); 
		
	printf("\n     Enter product price: ");
	scanf("%lf", &product.price);
	
	printf("\nYour new product info: ");
	printf("name: %s || type: %s || price: %lf", product.name, product.type, product.price);
	
	return product;
}

int isConfirm() {
	char choice;
	fflush(stdin);
	scanf("%c", &choice);
	switch(choice) {
		case 'y': 
			return 1;
		default:
			return 0;
	}
}

void addNewProduct(struct Product* newProduct, int *currentQuantity, int *currentId) {
	if (*currentQuantity >= 50) {
		printf("\nThe list is full, you need remove one or more products before you can add new");
		return;
	}
	struct Product product = inputProduct();
	printf("\nAre you sure to add it into the list? y/n \n");
	if(isConfirm()) {
		newProduct -> id = 1000 + *currentId;
		strcpy(newProduct -> name, product.name);
		strcpy(newProduct -> type, product.type);
		newProduct -> price = product.price;
		(*currentQuantity)++;
		(*currentId)++;
		printf("Added succesfully!");
	} else {
		printf("Canceled!");
	}
}

void printfListProduct(struct Product* listProduct) {
	
}

void findProductByPrice(double price) {
	
}

void findProductByName(char *name) {
	
}

int main() 
{
	struct Product productList[QUANTITY];
	int currentQuantity = 0;
	int currentId = 0;
	int running = 1;
	int choice = 0;
	while(running){
		menu();
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				addNewProduct(&productList[currentQuantity], &currentQuantity, &currentId);
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 0:
				running = 0;
				break;
			default:
				break;
		}
	}	
	return 0;
}
