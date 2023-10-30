#include<stdio.h>

int withdraw(int account)
{
	int amount;
	printf("Enter your amount that you want to withdraw: ");
	scanf("%d", &amount);
	account -= amount;
	return account;
}

int transfer(int account)
{
	int amount;
	printf("Enter your amount that you want to transfer: ");
	scanf("%d", &amount);
	account -= amount;
	return account;
}

int deposit(int account)
{
	int amount;
	printf("Enter your amount that you want to transfer: ");
	scanf("%d", &amount);
	account += amount;
	return account;
}

int main()
{
	int isRunning = 1;
	int isLoggedIn = 0;
	
	int choice;
	int account = 10000;
	
	char user[] = "admin";
	char password[] = "123456";
	
	char inputUser[10];
	char inputPassword[10];
	
	
	while( isRunning != 0 )
	{
		printf("Menu \n");
		printf("1 - Login \n");
		printf("0 - Close \n");
		printf("Enter your choice: ");
//		scanf("%d%*c", &choice);
		scanf("%d", &choice);
		fflush(stdin);
		switch(choice)
		{
			case 1:
				printf("Enter your user name: ");
//				scanf(" %[^\n]%*c", inputUser);
				gets(inputUser);
				printf("Enter your user password: ");
				gets(inputPassword);
//				scanf(" %[^\n]%*c", inputPassword);
				
				if(strcmp(inputUser,user) == 0 && strcmp(inputPassword,password) == 0)
				{
					isRunning = 0;
					isLoggedIn = 1;
				}
				else printf("Wrong user or password! \n");
				break;
			case 0:
				printf("Closing!");
				isRunning = 0;
				break;
			default:
				printf("Invalid choice, enter 0 - 1");
				break;
		}
	}	

	
	while( isLoggedIn != 0)
	{
		printf("XXX------------------------- \n");
		printf("Menu: %d vnd \n", account);
		printf("1/ Withdraw money! \n");
		printf("2/ Transfer money! \n");
		printf("3/ Deposit money! \n");
		printf("4/ Change password! \n");
		printf("0/ Close \n");
		printf("-------------------------XXX \n");
		printf("Please enter your choice from 0 - 4: ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				printf(" \n");
				account = withdraw(account);
				printf("Withdrawing! Done \n");
				printf("Your account is now: %d vnd", account);
				printf(" \n");
				break;
			case 2: 
				printf(" \n");
				account = transfer(account);
				printf("Transfering! Done \n");
				printf("Your account is now: %d vnd", account);
				printf(" \n");
				break;
			case 3: 
				printf(" \n");
				account = deposit(account);
				printf("Depositing! Done \n");
				printf("Your account is now: %d vnd", account);
				printf(" \n");
				break;
			case 4: 
				printf(" \n");
				printf("Changing password! \n");
				printf(" \n");
				break;
			case 0: 
				isLoggedIn = 0;
				printf("Closed!");
				break;
			default:
				printf(" \n");
				printf("Invalid choice, please enter value from 0 - 4! \n");
				printf(" \n");
				break;
		}
	}
	return 0;	
}
