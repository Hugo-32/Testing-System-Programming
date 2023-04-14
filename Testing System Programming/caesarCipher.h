//
// caesarCipher.h
// Меркулов Николай
//
#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char encryptChar(char c);
char decryptChar(char c);
void encrypt(const string& inputFilename, const string& outputFilename);
void decrypt(const string& inputFilename, const string& outputFilename);