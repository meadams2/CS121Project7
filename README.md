# CS121 Project 7 - Heap of Students Pt. 2

This project is a continuation of Project 6. We are given a client who has given us a task of creating a program with the following capabilities:

- The ability to print out a full record for each student
- The ability to print out a summary report containing the student's last name, first name on a single line.
- The ability to search for a student based on the last name. The search should return a full report of all students who's name is a match.

We are provided a stretch goal of being able to sort by the last name, first name, or credit hours. Credit hour sort should be descending with students with the most credit hours appearing first. The sort command doesn't print anything but allows subsequent commands. 

## Implementation

This project begins with three major classes that have already been implemented and tested within isolation:

- Address
- Date
- Student
  
We focus on the main.cpp module to perform the following tasks:

- Open the students.csv file
- Create a vector of Student pointers
- Load each student from a line in the csv file
- Present a menu to the user:
  - Quit
  - Print the names of all students
  - Print the details of all students
  - Search for a student
- User able to choose from at least those options
- When the user chooses to quit, the program cleans up the vector, closes the file, and exits

Necessary functions:

- loadStudents(students vector)
- printStudents(students vector)
- showStudentNames(students vector)
- findStudent(students vector)
- delStudents(students vector)
- menu()

Most of the functions work with the main data structure which is a vector of pointers to Students. We want to pass the vector by reference because we don't want copies of the Student classes causing memory leaks. Create students in main, and pass to other functions as needed.

## Algorithm

### Loading the Students

The function will:

- Open the students.csv file
- For each line of the file:
  - Create a Student instance on the heap
  - Initialize that instance with the string from the csv file
  - Append that instance to the vector at the end
- Close the file
It needs to work with a reference to the students vector, so it can change that vector in place.

### Printing the Students

The function takes a reference to the students vector. It goes through each student and prints out that students' full data. 

### Showing the Student Names

Function goes through the entire list of students, printing out the last and first name of each student. 

### Finding a Student

Function asks for a student's last name then checks the file to find a student with a matchign name. Note that the function should work with partial matches. The search may be case sensitive. 

<ins>**Note**</ins> : Look into the string.find()( method to see how to search for a substring in a string. If the string.find() method cannot find a match, it returns std::string::npos. 

### Presenting the Menu

Menu presents a limited list of choices. Ask user to enter number indicating choice. Value can stay as a string. Menu should indicate all the options the user has, and shoudl allow for some way to exit the program. The menu function returns the user's choice as a string, but doesn't verify that the user's choice is a valid input. 

### Deleting the Students

Student vector creates student instances on the heap. Manually reclaim heap data by looping through each element in the students vector and delete that element. 

### Main 

Main function acts like a traffic cop and moves control to various parts of the program. It should:

- Load up the vector from the file
- Loop until the user wants to quit
  - Offer the menu
  - Perform tasks based on user input
- Clear the students vector  
