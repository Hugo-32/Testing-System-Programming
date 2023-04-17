#include <iostream>
#include <fstream>
#include <cstring>
#include <locale>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

const int MAX_STUDENTS = 100; // Максимальное количество студентов
const int MAX_GRADES = 8; // Максимальное количество оценок по темам

struct Student {
	string login;
	string password;
	string firstName;
	string lastName;
	int grades[MAX_GRADES];
	int testGrade;
	float average;
};

int readStudents(Student* students);
double calculateAverage(Student students);
void printStudent(Student& student);
void writeEstimation(Student* students, int count);