#include <iostream>
#include <fstream>
#include <cstring>
#include <locale>
#include "authStudents.h"

using namespace std;

const int MAX_STUDENTS = 100; // ������������ ���������� ���������
const int MAX_GRADES = 8; // ������������ ���������� ������ �� �����


// ������� ��� ���������� ������ �� ����� � �������� ������� ���������
int readStudents(Student* students) {
    ifstream inputFile("students.txt");
    int count = 0;
    while (!inputFile.eof() && count < MAX_STUDENTS) {
        inputFile >> students[count].login >> students[count].password;
        inputFile >> students[count].firstName >> students[count].lastName;
        for (int i = 0; i < MAX_GRADES; i++) {
            inputFile >> students[count].grades[i];
        }
        inputFile >> students[count].testGrade;
        count++;
    }
    return count;
}

// ������� ��� ������� �������� �����
void calculateAverage(Student& student) {
    int total = 0;
    int count = 0;
    for (int i = 0; i < MAX_GRADES; i++) {
        if (student.grades[i] >= 0) {
            total += student.grades[i];
            count++;
        }
    }
    if (count > 0) {
        student.average = (float)total / count;
    }
    else {
        student.average = 0;
    }
}

// ������� ��� ������ ������ � ��������
void printStudent(Student& student) {
    cout << "Login: " << student.login << endl;
    cout << "Password: " << student.password << endl;
    cout << "Name: " << student.firstName << endl;
    cout << "Surname: " << student.lastName << endl;
    cout << "Grades:";
    for (int i = 0; i < MAX_GRADES; i++) {
        if (student.grades[i] >= 0) {
            cout << " " << student.grades[i];
        }
    }
    cout << endl;
    cout << "Test grade: " << student.testGrade << endl;
    cout << "Average grade: " << student.average << endl;
    cout << endl;
}