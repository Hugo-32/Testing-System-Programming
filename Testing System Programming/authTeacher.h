#include <iostream>
#include <fstream>
#include <cstring>
#include <locale>

using namespace std;

const int MAX_TEACHERS = 10; // ������������ ���������� ��������

// ��������� ��� �������� ���������� �� �������
struct Teacher {
    string login;
    string password;
};

int readTeachers(Teacher* teachers);
void printTeacher(const Teacher& teacher);