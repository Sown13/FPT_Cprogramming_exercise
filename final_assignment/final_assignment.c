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
	printf("\n|4. Find Product by name      |");
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


void printfListProduct(struct Product listProduct[], int currentQuantity) {
	int i = 0;
	if(currentQuantity == 0) {
		printf("\nThere no product in list now!");
		return;
	} 
	for( i = 0; i < currentQuantity; i++) {
		printf("\nProduct number %d: ", i);
		printf("Id: %d || Name: %s || Type: %s || Price: %lf", listProduct[i].id, listProduct[i].name, listProduct[i].type, listProduct[i].price);
	}
}

void findProductByPrice(struct Product listProduct[], int currentQuantity) {
	if(currentQuantity == 0) {
		printf("\nThere no product in list now!");
		return;
	} 
	double minPrice = 0;
	double maxPrice = 0;
	printf("\nEnter the minimum price that you want to find: ");
	scanf("%lf", &minPrice);
	printf("\nEnter the maximum price that you want to find:  ");
	scanf("%lf", &maxPrice);
	int i = 0;
	int numberOfResult = 0;
	for ( i = 0; i < currentQuantity; i++) {
		if ( listProduct[i].price > minPrice && listProduct[i].price < maxPrice)
		{
			printf("\nId: %d || Name: %s || Type: %s || Price: %lf", listProduct[i].id, listProduct[i].name, listProduct[i].type, listProduct[i].price);
			numberOfResult++;
		}
	}
	if(numberOfResult == 0) {
	printf("\nThere no product that match your search");
	}
}

void findProductByName(struct Product listProduct[], int currentQuantity) {
	if(currentQuantity == 0) {
		printf("\nThere no product in list now!");
		return;
	} 
	char searchName[50];
//	struct Product listProductByName[currentQuantity];
	int numberOfResult = 0;
	printf("\nPlease enter the name that you want to find: ");
	fflush(stdin);
	gets(searchName);
	int i = 0;
	for( i = 0; i < currentQuantity; i++) {
		if (strcmp(searchName, listProduct[i].name) == 0){
			printf("\nId: %d || Name: %s || Type: %s || Price: %lf", listProduct[i].id, listProduct[i].name, listProduct[i].type, listProduct[i].price);
			numberOfResult++;
		}
	}
	if(numberOfResult == 0) {
		printf("\nThere no product name that match your search");
	}
}

void swap(struct Product *product1, struct Product *product2)
{
	struct Product tempProduct = *product1;
	*product1 = *product2;
	*product2 = tempProduct;
}

void sortByPrice(struct Product *productList, int currentQuantity)
{
	int i = 0, j = 0;
	struct Product *minProduct = productList;
	for( i = 0; i < currentQuantity-1; i++ )
	{
		minProduct = &productList[i];
		for(j = i+1; j < currentQuantity; j++)
		{
			if (minProduct->price > productList[j].price)
			{
				minProduct = &productList[j];
			}
		}
		swap(&productList[i], minProduct);
	}
}

void sortByName(struct Product *productList, int currentQuantity){
	int i = 0, j = 0;
	struct Product *minProduct = productList;
	for( i = 0; i < currentQuantity-1; i++ )
	{
		minProduct = &productList[i];
		for(j = i+1; j < currentQuantity; j++)
		{
			if (minProduct->name[0] > productList[j].name[0])
			{
				minProduct = &productList[j];
			}
		}
		swap(&productList[i], minProduct);
	}
}

void updateById(struct Product *listProduct, int currentQuantity) {
	int productId, i, j, editIndex;
	struct Product editProduct;
	printf("\nPlease enter ID of the product that you want to edit:");
	scanf("%d", &productId);
	for(i = 0; i < currentQuantity; i++) {
		if ( productId == listProduct[i].id) {
			editProduct = listProduct[i];
			editIndex = i;
			printf("\nHere the product with id %d", productId);
			printf("\nId: %d || Name: %s || Type: %s || Price: %lf", listProduct[i].id, listProduct[i].name, listProduct[i].type, listProduct[i].price);
			printf("\nAre you sure you want to edit it? y/n\n");
			break;
		} else {
			editIndex = -1;
		}
	}
	if(editIndex == -1 ) {
		printf("Id not found!");
		return;
	}
	if(isConfirm()) {
		char tempName[50];
		char tempType[20];
		double tempPrice = editProduct.price;
		strcpy(tempName, editProduct.name);
		strcpy(tempType, editProduct.type);
		
		printf("\nPlease enter the new name (Enter to skip): ");
		fflush(stdin);
		gets(editProduct.name);
		if(strlen(editProduct.name) == 0) {
			strcpy(editProduct.name, tempName);
		}
		
		printf("\nPlease enter the new price: ");
		scanf(" %lf", &editProduct.price);
//		if(editProduct.price == EOF) {
//			editProduct.price = tempPrice;
//		}
		
		printf("\nPlease enter the new type (Enter to skip): ");
		fflush(stdin);
		gets(editProduct.type);
		if(strlen(editProduct.type) == 0) {
			strcpy(editProduct.type, tempType);
		}
		
		printf("\nHere the new product with id %d", productId);
		printf("\nId: %d || Name: %s || Type: %s || Price: %lf", editProduct.id, editProduct.name, editProduct.type, editProduct.price);	
		printf("\nAre you sure want to edit like that? y/n\n");
		if(isConfirm())	{
			listProduct[editIndex].price = editProduct.price;
			strcpy(listProduct[i].name, editProduct.name);
			strcpy(listProduct[i].type, editProduct.type);
			printf("Edit successfully!");
		} else {
			printf("\nCanceled!");
		}
	} else {
			printf("\nCanceled!");
		}
}


void deleteById(struct Product *listProduct, int *currentQuantity) {
	int productId, i, j, deleteIndex;
	struct Product deleteProduct;
	printf("\nPlease enter ID of the product that you want to delete:");
	scanf("%d", &productId);
	for(i = 0; i < *currentQuantity; i++) {
		if ( productId == listProduct[i].id) {
			deleteProduct = listProduct[i];
			deleteIndex = i;
			printf("\nHere the product with id %d", productId);
			printf("\nId: %d || Name: %s || Type: %s || Price: %lf", listProduct[i].id, listProduct[i].name, listProduct[i].type, listProduct[i].price);
			printf("\nAre you sure you want to delete it? y/n\n");
			break;
		} else {
			deleteIndex = -1;
		}
	}
	if(deleteIndex == -1 ) {
		printf("Id not found!");
		return;
	}
	if (isConfirm()) {
		struct Product *tempPtr = &listProduct[deleteIndex];
		for( i = deleteIndex; i < *currentQuantity-1; i++) {
			swap(&listProduct[i], &listProduct[i+1]);
			tempPtr++;
		}
		tempPtr -> id = 0;
		tempPtr -> price = 0.0;
		strcpy(tempPtr -> name, "");
		strcpy(tempPtr -> type, "");
		(*currentQuantity)--;
		printf("Delete successfully!");
	}  else {
			printf("\nCanceled!");
		}
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
		fflush(stdin);
//		scanf("%d", &choice);
		if (scanf("%d", &choice) != 1) {
            printf("\nInvalid choice, please enter a number from 0 - 8");
            continue;
        }
		
		switch(choice) {
			case 1:
				addNewProduct(&productList[currentQuantity], &currentQuantity, &currentId);
				break;
			case 2:
				printfListProduct(productList, currentQuantity);
				break;
			case 3:
				findProductByPrice(productList, currentQuantity);
				break;
			case 4:
				findProductByName(productList, currentQuantity);
				break;
			case 5:
				sortByName(productList, currentQuantity);
				printfListProduct(productList, currentQuantity);
				break;
			case 6:
				sortByPrice(productList, currentQuantity);
				printfListProduct(productList, currentQuantity);
				break;
			case 7:
				updateById(productList, currentQuantity);
				break;
			case 8:
				deleteById(productList, &currentQuantity);
				printf("\n current quantity: %d", currentQuantity);
				break;
			case 0:
				running = 0;
				break;
			default:
				printf("\nInvalid choice, please enter a number from 0 - 8");
				break;
		}
	}	
	return 0;
}
