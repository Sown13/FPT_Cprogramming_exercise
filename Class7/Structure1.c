#include <stdio.h>

struct Person
{
	char name[30];
	int age;
	char email[30];
};

//write function to 
//1. input data of structure
//2. display date of structure

void inputData(struct Person* p)
{
	printf("Enter name: ");
	fflush(stdin);
	gets(p->name);
	
	printf("Enter age: ");
	scanf("%d", &p->age);
	
	printf("Enter email: ");
	fflush(stdin);
	gets(p->email);
}

void displayData(struct Person p)
{
	//2. p same person ?
	printf("\n===== Person information ======");
	printf("%s %d %s", p.name, p.age, p.email);
}

int main()
{
	struct Person person;
	inputData( &person );
	
	//1. why not change this command?
	displayData(person);
	
	return 0;
}
