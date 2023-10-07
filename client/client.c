/*
Author: 	Vicky Panchal
Roll No.: 	MT2023098
Date: 		04/10/2023
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#include "welcome.h"
#include "home_menu.h"

#define PORT 8889
#define PASSWORD_LENGTH 25

int mainMenu(int sock);

int main(int argc, char * argv[]){
	char *ip = "127.0.0.1";//if ip of server is not given in command line argument then it will
							//be assigned the loopback address
	if(argc==2){
		ip = argv[1];
	}
	int cli_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(cli_fd == -1){
		printf("socket creation failed\n");
		exit(0);
	}
	struct sockaddr_in ca;
	ca.sin_family=AF_INET;
	ca.sin_port= htons(PORT);
	ca.sin_addr.s_addr = inet_addr(ip);
	/* Convert Internet host address from numbers-and-dots notation in CP
   into binary data in network byte order.  */
	if(connect(cli_fd, (struct sockaddr *)&ca, sizeof(ca))==-1){
		/*
		 int connect(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
		 The connect() system call connects the socket referred to by the
       	 file descriptor sockfd to the address specified by addr.  The
         addrlen argument specifies the size of addr.  The format of the
         address in addr is determined by the address space of the socket
         sockfd;
		*/
		printf("connection failed\n");
		exit(0);
	}
	printf("connection established\n");
	
	welcome_screen();
	while(mainMenu(cli_fd)!=3);
	close(cli_fd);

	return 0;
}

int mainMenu(int sock){
	int opt;
	system("clear");
	printf("--------Welcome to Academia :: Course Registration--------\n");
	printf("Login Type \n");
	printf("Enter you choice {1. Admin, 2. Student, 3. Faculty} : \n");
	scanf("%d", &opt);
	write(sock, &opt, sizeof(opt));

	int home_val = homeMenu(opt, sock);
	return home_val;
	//home menu completed
	//user_menu
	//admin_action | user_action
}
