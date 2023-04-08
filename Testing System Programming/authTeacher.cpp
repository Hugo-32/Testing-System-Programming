#include <iostream>
#include <fstream>
#include <cstring>
#include <locale>
#include "authTeacher.h"

using namespace std;

const int MAX_TEACHERS = 10; // Максимальное количество учителей

// Структура для хранения информации об учителе
struct Teacher {
    string login;
    string password;
};

// Функция для считывания данных из файла и создания массива учителей
int readTeachers(Teacher* teachers) {
    ifstream inputFile("Teachers.txt");
    int count = 0;
    while (!inputFile.eof() && count < MAX_TEACHERS) {
        inputFile >> teachers[count].login >> teachers[count].password;
        count++;
    }
    return count;
}

// Функция для вывода данных об учителе
void printTeacher(const Teacher& teacher) {
    cout << "Login: " << teacher.login << endl;
    cout << "Password: " << teacher.password << endl;
}