// main.cpp

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "date.h"
#include "address.h"
#include "student.h"

void loadStudents(std::vector students);
void printStudents(std::vector students);
void showStudentNames(std::vector students);
void findStudent(std::vector students);
void delStudents(std::vector students);
std::string menu();

int main(){
	std::vector<Student> students;
	loadStudents(students);
	bool keepGoing = true;

	while (keepGoing){
		menu();

		if (menu() == 0){
			delStudents(students);
			keepGoing = false;
		} //End quit condition
		
		else if (menu() == 1){
			showStudentNames(students);
		} //End studentNames condition

		else if (menu() == 2){
			printStudents(students);
		} //End print students condition

		else if (menu() == 3){
			findStudent(students);
		} //End find student condition

	} //end while loop

} //end main

std::string menu(){
	std::string userInput;

	std::cout << "0) Quit" << std::endl;
	std::cout << "1) Print all student names" << std::endl;
	std::cout << "2) Print all student data" << std::endl;
	std::cout << "3) Find a student" << std::endl;

	std::cout << "Please choose 0-3: ";
	std::cin >> userInput;

	return userInput;
} //end menu()

void loadStudents(std::vector students){
	std::ifstream inFile;
	std::string studentString;

	inFile.open("students.csv");
	while (getline(inFile, studentString)){
		converter.clear();
		converter.str(studentString);

		student = new Student();
		student -> init(studentString);
		students.push_back(student); 
	} //end while loop
} //end loadStudents

void delStudents(std::vector students){
	for (auto& item: students){
		students.pop_back();
		student -> ~Student();
	} //end for loop
} //end delStudents

void showStudentNames(std::vector students){
	for (auto& item: students){
		std::cout << student -> getLastFirst();
	} //end for loop
} //end showStudentNames

		
