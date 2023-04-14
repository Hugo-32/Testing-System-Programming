//
// caesarCipher.h
// Меркулов Николай
//
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <numeric>
#include <unordered_set>

using namespace std;

struct Question
{
    string text;
    vector<string> answers;
    string correct_answer;
    string theme;
    vector<string> wrong_questions;
};

char encryptChar(char c);
char decryptChar(char c);
void encrypt(const string& inputFilename, const string& outputFilename);
void decrypt(const string& inputFilename, const string& outputFilename);

vector<Question> readQuestionsFromFile(const string& filename);
string chooseTheme();
vector<Question> filterQuestionsByTheme(const vector<Question>& questions, const string& theme);
vector<Question> selectRandomQuestions(const vector<Question>& questions, int count);