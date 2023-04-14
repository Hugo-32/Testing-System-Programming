#pragma once
#include <iostream>
#include <stdlib.h>
#include <locale>
#include <conio.h>
#include "authStudents.h"
#include "CaesarCipher.h"

void Students();
void Menu(Student students[100], int Pr);
int Proverka(Student students[100], int NumberOfStudents);

void trainingMode(const vector<Question>& questions);
void testingMode(const vector<Question>& questions);
void finalTest(const vector<Question>& questions);