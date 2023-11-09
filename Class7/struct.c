#include<stdio.h>


struct Person
{
	char name[30];
	int age;
	char email[30];
};


void inputInfo(struct Person* person) {
	
	printf("Enter name: ");
	fflush(stdin);
	gets(person -> name);
	
	printf("Enter age: ");
	scanf("%d", &person -> age);
	
	printf("Enter email: ");
	fflush(stdin);
	gets(person -> email);
	
}

void displayInfo(struct Person person) {
	printf("Person info: \n");
	printf("%s %d %s \n", person.name, person.age, person.email);
}



int main() {
	
	struct Person person;
	
	inputInfo(&person);
	displayInfo(person);

}
