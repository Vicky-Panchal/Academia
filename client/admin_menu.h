/*
Author: 	Vicky Panchal
Roll No.: 	MT2023098
Date: 		04/10/2023
*/

#define PORT 8880
#define PASSWORD_LENGTH 25

int adminMenu(int opt,int  sock){//used in client.c
	printf("------- Welcome to Admin Menu --------\n");
	printf("1. Add Student\n");
	printf("2. View Student Details \n");
	printf("3. Add Faculty\n");
	printf("4. View Faculty Details\n");
	printf("5. Activate Student\n");
	printf("6. Block Student\n");
	printf("7. Modify Student Details\n");
	printf("8. Modify Faculty Details\n");
	printf("9. Logout and Exit\n");

	int choice;
	printf("Enter You Choice: ");
	scanf("%d", &choice);
}