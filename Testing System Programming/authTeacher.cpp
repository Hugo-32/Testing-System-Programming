#include "authTeacher.h"

// Функция для считывания данных из файла и создания массива учителей
int readTeachers(Teacher* teachers) {
    ifstream inputFile("Teachers.txt");
    int count = 0;
    while (!inputFile.eof() && count < MAX_TEACHERS) {
        inputFile >> teachers[count].login >> teachers[count].password >> teachers[count].firstName >> teachers[count].lastName;
        count++;
    }
    return count;
}

// Функция для вывода данных об учителе
void printTeacher(const Teacher& teacher) {
    cout << "Login: " << teacher.login << endl;
    cout << "Password: " << teacher.password << endl;
}