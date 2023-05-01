#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include <locale>

using namespace std;

const int MAX_TEACHERS = 10; // Максимальное количество учителей

// Структура для хранения информации об учителе
struct Teacher {
    string login;
    string password;
    string firstName;
    string lastName;
};

int readTeachers(Teacher* teachers);
void printTeacher(const Teacher& teacher);