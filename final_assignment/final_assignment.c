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
	printf("   =============MENU=============   ");
	printf("\n|1. Add new Product               |");
	printf("\n|2. List all Product              |");	
	printf("\n|3. Find Product by price         |");
	printf("\n|4. Find by approximate name      |");
	printf("\n|5. Find Product by exactly name  |");	
	printf("\n|6. Sort by name                  |");	
	printf("\n|7. Sort by price                 |");	
	printf("\n|8. Update Product by ID          |");
	printf("\n|9. Delete a Product from list    |");		
	printf("\n|0. Exit                          |");
	printf("\n   =============END=============  ");
	printf("\n");
}

void saveProductToFile(struct Product product, int currentQuantity, int currentId) {
	FILE *pFile = fopen("product.txt", "a");
	FILE *pFileQuantity = fopen("quantity.txt", "w");
	FILE *pFileId = fopen("id.txt", "w");
	int i = 0;
	if (pFile != NULL && pFileQuantity != NULL && pFileId != NULL) {
//		printf("\nOpen file successfully");
		fwrite(&product, sizeof(product), 1,pFile);
		fprintf(pFileQuantity, "%d", currentQuantity);
		fprintf(pFileId, "%d", currentId);
		fclose(pFile);
		fclose(pFileQuantity);
		fclose(pFileId);
		printf("\nSave product successfully!");
	}
}

void updateProductListToFile(struct Product *listProduct, int currentQuantity) {
	FILE *pFile = fopen("product.txt", "w");
	FILE *pFileQuantity = fopen("quantity.txt", "w");
	int i = 0;
	if (pFile != NULL && pFileQuantity != NULL) {
//		printf("\nOpen file successfully");
		fprintf(pFileQuantity, "%d", currentQuantity);
//		for ( i = 0; i < currentQuantity; i++) {
//			fwrite(&listProduct[i], sizeof(listProduct[i]), 1, pFile);
//		}
		fwrite(listProduct, sizeof(listProduct[0]), currentQuantity, pFile);
		fclose(pFile);
		fclose(pFileQuantity);
	}
}

void loadFile(struct Product* listProduct, int *currentQuantity, int *currentId) {
	FILE *pFile = fopen("product.txt", "r");
	FILE *pFileQuantity = fopen("quantity.txt", "r");
	FILE *pFileId = fopen("id.txt", "r");
	int i = 0;
	if (pFile != NULL && pFileQuantity != NULL && pFileId != NULL) {
		fscanf(pFileQuantity,"%d", currentQuantity);
		fscanf(pFileId,"%d", currentId);
		fread(listProduct, sizeof(struct Product), *currentQuantity, pFile);
		fclose(pFile);
		fclose(pFileQuantity);
		fclose(pFileId);
//		printf("%d %d", *currentQuantity, *currentId);
		printf("\nLoad data successfully!");
	}
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
		saveProductToFile(*newProduct, *currentQuantity, *currentId);
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

void findProductByNameLike(struct Product listProduct[], int currentQuantity) {
	if(currentQuantity == 0) {
		printf("\nThere no product in list now!");
		return;
	} 
	char searchName[50];
	int numberOfResult = 0;
	int i = 0;
	int j = 0;
	printf("\nPlease enter the name that you want to find: ");
	fflush(stdin);
	gets(searchName);
	char searchNameLower[strlen(searchName) + 1];
	for (j =0; j < strlen(searchName); j++) {
		searchNameLower[j] = tolower(searchName[j]);
	}
	searchNameLower[j] = '\0';
	for( i = 0; i < currentQuantity; i++) {
//		printf(">[%s]<\n", searchNameLower);
		char checkingName[strlen(listProduct[i].name)+1];
//		printf("\n \n ");
		for (j =0; j < strlen(listProduct[i].name); j++) {
			checkingName[j] = tolower(listProduct[i].name[j]);
//			printf("%c",checkingName[j]);
		}
		checkingName[j] = '\0';
//		printf("\n[%s =", checkingName);
//		terminate trash after the string
//		printf("[%s ? %s]\n", checkingName, searchNameLower);
		if (strstr(checkingName, searchNameLower) != NULL){
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
			updateProductListToFile(listProduct, currentQuantity);
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
		updateProductListToFile(listProduct, *currentQuantity);
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
	loadFile(productList, &currentQuantity, &currentId);
	while(running){
		menu();
		printf("\nEnter your choice: ");
		fflush(stdin);
//		scanf("%d", &choice);
		if (scanf("%d", &choice) != 1) {
            printf("\nInvalid choice, please enter a number from 0 - 9");
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
				findProductByNameLike(productList, currentQuantity);
				break;
			case 5:	
				findProductByName(productList, currentQuantity);
				break;
			case 6:
				sortByName(productList, currentQuantity);
				printfListProduct(productList, currentQuantity);
				break;
			case 7:
				sortByPrice(productList, currentQuantity);
				printfListProduct(productList, currentQuantity);
				break;
			case 8:
				updateById(productList, currentQuantity);
				break;
			case 9:
				deleteById(productList, &currentQuantity);
				printf("\n current quantity: %d", currentQuantity);
				break;
			case 0:
				running = 0;
				break;
			default:
				printf("\nInvalid choice, please enter a number from 0 - 9");
				break;
		}
	}	
	return 0;
}
