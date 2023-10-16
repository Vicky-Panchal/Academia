/*
Author: 	Vicky Panchal
Roll No.: 	MT2023098
Date: 		04/10/2023
*/

#include "../macros.h"

void viewAllCourses(int sock);
void enrollCourse(int sock);

int studentMenu(char *login_id,int  sock){//used in client.c
	printf("------- Welcome to Student Menu --------\n");
	printf("1. View All Courses\n");
	printf("2. Enroll (pick) New Course\n");
	printf("3. Drop Course \n");
	printf("4. View Enrolled Course Details \n");
	printf("5. Change Password\n");
	printf("6. Logout & Exit\n");

	int choice;
	printf("Enter Your Choice: ");
	scanf(" %d", &choice);
	printf("We had taken the choice\n");
	write(sock, &choice, sizeof(choice));
	printf("\nafter choice %d", choice); 
	switch(choice) {
		case 1: viewAllCourses(sock);
		break;

		case 2: enrollCourse(sock);
		break;

		case 6: return -1;

		default: return -1;
	}
}

void viewAllCourses(int sock) {
	
	int n;
	struct Courses course[n];
	read(sock, &n, sizeof(n));
	read(sock, &course, sizeof(course));
	if(n >= 1) {
		for(int i = 0; i < n; i++) {
			write(STDOUT_FILENO, "******Course Details*****\n", strlen("******Course Details*****\n"));
    		printf("\nId: %s", course[i].course_id);
			printf("\nName: %s", course[i].name);
			printf("\nDepartment: %s", course[i].department);
			printf("\nCredits: %d", course[i].credits);
			printf("\nNo. Of Available Seats: %d", course[i].no_of_available_seats);
			printf("\nNo. Of Seats: %d\n \n", course[i].no_of_seats);
			write(STDOUT_FILENO, "\n \n", strlen("\n"));
		}	
	}
	else {
		write(STDOUT_FILENO, "No Course Found!", 17);
	}
}

void enrollCourse(int sock) {
	char courseId[5];
	int isCourseFull;
	printf("\nEnter course Id: ");
	scanf(" %s", courseId);
	write(sock, &courseId, sizeof(courseId));

	read(sock, &isCourseFull, sizeof(isCourseFull));

	if(isCourseFull) {
		printf("\nCourse is Full");
	}

	printf("\nSuccessfully enrolled");
}