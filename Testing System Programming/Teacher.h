#pragma once
#include <iostream>
#include <stdlib.h>
#include <locale>
#include <conio.h>
#include <string>
#include "authTeacher.h"
#include "CaesarCipher.h"
#include "authStudents.h"

void Teachers();
int Proverka(Teacher Teachers[MAX_TEACHERS], int NumberOfTeachers);
void Menu(Teacher Teachers[MAX_TEACHERS], int Pr, int NumberOfTeachers);
void Editing_Questions(Teacher Teachers[MAX_TEACHERS], int Pr, int NumberOfTeachers);
void Editing_Students(Teacher Teachers[MAX_TEACHERS], int Pr, int NumberOfTeachers);
void Del_Questions();
void Add_Questions();
void Edit_Questions();
void Del_Add_Students(Teacher Teachers[MAX_TEACHERS], int Pr, int NumberOfTeachers, Student* students, int& NumberOfStudents);
void Del_Students(Student* students, int& count);
void Add_Students(Student* students, int& count);

void Edit_Estimation_Of_Students(Student* students, int& count);

void Print_List_Of_Students(Teacher Teachers[MAX_TEACHERS], int Pr, int NumberOfTeachers, Student* students, int& NumberOfStudents);
void Print_List(int& sort, int filter[], int size, int& range_sort, int& theme_sort, Student* students, int& NumberOfStudents);
void Print_List_All(int& sort, int filter[], int size, int& range_sort, int& theme_sort, Student* students, int& count);
void Print_List_Theme(int& sort, int filter[], int size, int& range_sort, int& theme_sort, Student* students, int& count);
void Print_List_Test(int& sort, int filter[], int size, int& range_sort, int& theme_sort, Student* students, int& count);
void Print_List_Average(int& sort, int filter[], int size, int& range_sort, int& theme_sort, Student* students, int& count);
void Filters(int filter[], int& size);
void Sort(int& sort, int& range_sort, int& theme_sort);