#pragma once
#include <iostream>
#include <stdlib.h>
#include <locale>
#include <conio.h>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <numeric>
#include <unordered_set>

struct Question
{
    string text;
    vector<string> answers;
    string correct_answer;
    string theme;
    vector<string> wrong_questions;
};

vector<Question> readQuestionsFromFile(const string& filename);
string choose_theme();
vector<Question> filterQuestionsByTheme(const vector<Question>& questions, const string& theme);
vector<Question> selectRandomQuestions(const vector<Question>& questions, int count);
void Trening(const vector<Question>& questions);
void Test(const vector<Question>& questions);
void FinalTest(const vector<Question>& questions);
void Trening(const vector<Question>& questions);
void Test(const vector<Question>& questions);
void FinalTest(const vector<Question>& questions);

void Menu();
void Students();
int Proverka();