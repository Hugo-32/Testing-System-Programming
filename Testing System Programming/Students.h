#pragma once
#include <iostream>
#include <stdlib.h>
#include <locale>
#include <conio.h>
#include "authStudents.h"

struct TestResult {
	int Res;
	int Title;
};

void Students();
void Menu(Student students[100], int Pr);
int Proverka(Student students[100], int NumberOfStudents);
void Trening(TestResult &TestRes); 
void Test(TestResult &TestRes);
void FinalTest(TestResult &TestRes);