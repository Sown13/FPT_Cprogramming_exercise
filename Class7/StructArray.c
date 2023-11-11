#include<stdio.h>
#include<stdlib.h>

struct Person
{
	char name[30];
	int age;
	char email[30];
};

struct TestSize{
//	int a;
	char names[10];
	double salary;
	int age;
	int something; 
};

void swap(struct Person *personA, struct Person *personB)
{
	struct Person tempPerson = *personA;
	*personA = *personB;
	*personB = tempPerson;
}

void sortByName(struct Person *persons, int length){
	int i = 0, j = 0;
	struct Person *minPerson = persons;
	for( i = 0; i < length-1; i++ )
	{
		minPerson = &persons[i];
		for(j = i+1; j < length; j++)
		{
			if (minPerson->name[0] > persons[j].name[0])
			{
				minPerson = &persons[j];
				printf("minPerson: %s \n", minPerson->name);
			}
		}
		swap(&persons[i], minPerson);
	}
}

struct Person* inputInfo(int quantity){
	struct Person *ptr, *firstPtr;
	
	ptr = (struct Person*) malloc (quantity * sizeof(struct Person));
	firstPtr = ptr;
	
	int i = 0;
	for(; i < quantity; i++){
		
		printf("Enter person %i name: ", i+1);
		fflush(stdin);
		gets(ptr -> name);
		
		printf("Enter person %i age: ", i+1);
		scanf("%d,",&ptr -> age);
		
		printf("Enter person %i email: ", i+1);
		fflush(stdin);
		gets(ptr -> email);	
		
		ptr++;
	}


	return firstPtr;
}

void displayInfo(struct Person person) {
	printf("%s %d %s \n", person.name, person.age, person.email);
}


int main() {
	
	int quantity = 0;
	printf("Enter the quantity of person info: ");
	scanf("%d", &quantity);
	
	struct Person *ptr, *firstPtr;
	
	ptr = inputInfo(quantity);
		
	sortByName(ptr, quantity);
	
	int i = 0;	
	for( i = 0; i < quantity; i++){
		printf("Person %d: ", i+1);
		displayInfo(ptr[i]);
	}

//	struct Person b = {
//		{'b','b','b'},2,{'b','b','b'}
//	};
//	
//	struct Person a = {
//		{'a','a','a'},1,{'a','a','a'}
//	};	
	
//	swap(&b,&a);
//	printf("p1: %s %d %s \n", b.name,b.age,b.email);
//	printf("p12: %s %d %s \n", a.name,a.age,a.email);	
	
	
	printf("Size of TestSize: %d \n", sizeof(struct TestSize));
	
	return 0;
}
