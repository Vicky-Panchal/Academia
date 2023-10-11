/*
Author: 	Vicky Panchal
Roll No.: 	MT2023098
Date: 		04/10/2023
*/

#include "../macros.h"
// #include "../database/database.h"

void viewOfferingCourses(char* login_id,int sock);
void addNewCourse(char* login_id,int sock);

int facultyMenu(char* login_id,int  sock){//used in client.c
	printf("------- Welcome to Faculty Menu --------\n");
	printf("1. View Offering Courses \n");
	printf("2. Add New Courses \n");
	printf("3. Remove Courses from Catalog\n");
	printf("4. Update Course Details \n");
	printf("5. Change Password \n");
	printf("6. Logout & Exit\n");
	
	int choice;
	char prompt[] = "Enter Your Choice: ";
	char buffer[10];

    write(STDOUT_FILENO, prompt, sizeof(prompt));

    ssize_t bytesRead = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
    if (bytesRead == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    buffer[bytesRead] = '\0';

    if (sscanf(buffer, "%d", &choice) != 1) {
        fprintf(stderr, "Invalid input. Please enter an integer.\n");
        exit(EXIT_FAILURE);
    }
	write(sock, &choice, sizeof(choice));

	switch(choice) {
		case 1: viewOfferingCourses(login_id, sock);
		break;

		case 2: addNewCourse(login_id, sock);
		break;

		case 6: exit(0);
	}
}

void viewOfferingCourses(char* login_id,int sock) {
	int count;
	struct Courses course[count];

	
}

void addNewCourse(char* login_id,int sock) {
	struct Courses course;

	write(STDOUT_FILENO, "Enter Course Name: ", 20);
    read(STDIN_FILENO, course.name, sizeof(course.name));

    write(STDOUT_FILENO, "Enter Department: ", 19);
    read(STDIN_FILENO, course.department, sizeof(course.department));

    write(STDOUT_FILENO, "Enter Number of Seats: ", 24);
    read(STDIN_FILENO, &course.no_of_seats, sizeof(course.no_of_seats));

    write(STDOUT_FILENO, "Enter Credits: ", 14);
    read(STDIN_FILENO, &course.credits, sizeof(course.credits));

    write(STDOUT_FILENO, "Enter Available Seats: ", 23);
    read(STDIN_FILENO, &course.no_of_available_seats, sizeof(course.no_of_available_seats));

    write(STDOUT_FILENO, "Enter Active Status (0 or 1): ", 30);
    read(STDIN_FILENO, &course.isActive, sizeof(course.isActive));

	write(sock, &course, sizeof(course));
}