#include "authStudents.h"
#include "CaesarCipher.h"

// Функция для считывания данных из файла и создания массива студентов
double calculateAverage(Student student) {
    int total = 0;
    int count = 0;
    for (int i = 0; i < MAX_GRADES; i++) {
        if (student.grades[i] >= 0) {
            total += student.grades[i];
            count++;
        }
    }
    if (count > 0) {
        return (float)total / count;
    }
    else {
        return 0;
    }
}

// Функция для считывания данных из файла и создания массива студентов
int readStudents(Student* students) 
{
    decrypt("students.txt", "decrypted2.txt");
    ifstream inputFile("decrypted2.txt");
    int count = 0;
    while (!inputFile.eof() && count < MAX_STUDENTS) {
        inputFile >> students[count].login >> students[count].password;
        inputFile >> students[count].firstName >> students[count].lastName;
        for (int i = 0; i < MAX_GRADES; i++) {
            inputFile >> students[count].grades[i];
        }
        inputFile >> students[count].testGrade;
        students[count].average = calculateAverage(students[count]);
        count++;
    }
    return count;
}

// Функция для вывода данных о студенте
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

void writeEstimation(Student* students, int count) 
{
	FILE* file;
	fopen_s(&file, "decrypted2.txt", "w");
	for (int i = 0; i < count; i++)
	{
		fprintf(file, "%s %s\n", students[i].login.c_str(),students[i].password.c_str());
        fprintf(file, "%s %s\n", students[i].firstName.c_str(), students[i].lastName.c_str());
        for (int j = 0; j < MAX_GRADES; j++)
        {
            fprintf(file, "%d ", students[i].grades[j]);
        }
        fprintf(file, "\n%d", students[i].testGrade);
        if (i < count-1) { fprintf(file, "\n\n"); }
	}
	fclose(file);
    encrypt("students.txt", "decrypted2.txt");
}