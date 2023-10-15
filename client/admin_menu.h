/*
Author: 	Vicky Panchal
Roll No.: 	MT2023098
Date: 		04/10/2023
*/

#include "../macros.h"
// #include "../database/database.h"

void addStudent(int sock);
void addFaculty(int sock);

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
	printf("Enter Your Choice: ");
	scanf("%d", &choice);
	write(sock, &choice, sizeof(choice));

	switch(choice) {
		case 1: addStudent(sock);
		break;

		case 3: addFaculty(sock);
		break;
		case 9: exit(0);
	}
}
char *Account[3] = {"./database/accounts/admin", "./database/accounts/student", "./database/accounts/faculty"};
void addStudent(int sock) {
	struct Student student;

	printf("Enter Student Name: \n");
	scanf("%s", student.name);
	printf("Enter You Age: \n");
	scanf("%d", &student.age);
	printf("Enter You Address: \n");
	scanf("%s", student.address);
	printf("Enter Password: \n");
	scanf("%s", student.password);
	printf("Enter You Email Address: \n");
	scanf("%s", student.email);
	
	write(sock, &student, sizeof(struct Student));
}

void addFaculty(int sock) {
	struct Faculty faculty;
	int count = 0;
	struct flock lock;
	printf("***************  Enter Faculty Details  ***************\n");
	printf("Name: ");
	scanf("%s", faculty.name);
	printf("Age: ");
	scanf("%d", &faculty.age);
	printf("Address: ");
	scanf("%s", faculty.address);
	printf("Password: ");
	scanf("%s", faculty.password);
	printf("Email Address: ");
	scanf("%s", faculty.email);
	
	write(sock, &faculty, sizeof(struct Faculty));
}