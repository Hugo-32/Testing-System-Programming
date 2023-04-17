#pragma once
#include <iostream>
#include <stdlib.h>
#include <locale>
#include <conio.h>
#include "authStudents.h"
#include "CaesarCipher.h"

void Students();
void Menu(Student students[MAX_STUDENTS], int Pr, int NumberOfStudents);
int Proverka(Student students[100], int NumberOfStudents);

void trainingMode(const vector<Question>& questions);
void testingMode(const vector<Question>& questions, Student students[MAX_STUDENTS], int NumberOfStudents, int Pr);
void finalTest(const vector<Question>& questions, Student students[MAX_STUDENTS], int NumberOfStudents, int Pr);