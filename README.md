# Academia - Course Registration Portal

## Author
- **Name:** Vicky Panchal
- **Roll No:** MT2023098

## International Institute of Information Technology, Bangalore
- **Course:** CS-513 System Software
- **Project:** Mini Project

## Project Description
The "Academia" project aims to design and develop a user-friendly and multifunctional course registration portal. This portal is intended to be used by students, faculty, and administrators to manage course information, student details, and faculty information. It incorporates features such as secure login systems, user roles, administrative access control, and concurrent access for multiple users.

## Project Functionalities
The Academia Portal should have the following functionalities:

### General Features
- All student and faculty details, as well as course information, are stored in files.
- Users need to pass through a login system to access their accounts.
- User accounts will be managed by the administrator.
- The application should possess password-protected administrative access to prevent unauthorized access.
- Different user roles are implemented: Faculty, Student, and Admin.

### Administrator Features
- After the administrator logs in, they should be presented with a menu to perform actions such as:
  - Add Student
  - Add Faculty
  - Activate/Deactivate Student
  - Update Student/Faculty Details
  - Exit

### Student Features
- After a student logs in, they should be presented with a menu to perform actions such as:
  - Enroll in new Courses
  - Unenroll from already enrolled Courses
  - View enrolled Courses
  - Change Password
  - Exit

### Faculty Features
- After a faculty member logs in, they should be presented with a menu to perform actions such as:
  - Add new Course
  - Remove offered Course
  - View enrollments in Courses
  - Change Password
  - Exit

### Data Locking
- Course details can be viewed with a read lock to protect data integrity.
- Enrolling or unenrolling in courses requires a write lock to protect critical data.

### Server-Client Interaction
- The project uses socket programming, where the server maintains the database and serves multiple clients concurrently.
- Clients can connect to the server to access their specific academic details.

### System Calls
- System calls are used instead of library functions wherever possible in the project, including process management, file management, file locking, semaphores, multithreading, and inter-process communication mechanisms.


## How to Run the Project

- Create Database
chmod +x database.sh
./database.sh

- Compile Server
cc server.c -o server

- Compile Client
cd client
cc client.c -o client

- Run Server
./server

- Run Client
./client

