#include "CaesarCipher.h"

const int shift = 3;

char encryptChar(char c) {
    if (isalpha(c)) {
        char base = isupper(c) ? 'A' : 'a';
        return (c - base + shift) % 26 + base;
    }
    return c;
}

char decryptChar(char c) {
    if (isalpha(c)) {
        char base = isupper(c) ? 'A' : 'a';
        return (c - base - shift + 26) % 26 + base;
    }
    return c;
}

void encrypt(const string& inputFilename, const string& outputFilename) {
    ifstream outputFile(outputFilename);
    ofstream inputFile(inputFilename);

    if (!inputFile || !outputFile) {
        cerr << "Error opening files." << endl;
        return;
    }

    char c;
    while (outputFile.get(c)) {
        inputFile << encryptChar(c);
    }

    inputFile.close();
    outputFile.close();

    remove(outputFilename.c_str());
}

void decrypt(const string& inputFilename, const string& outputFilename) {
    ifstream inputFile(inputFilename);
    ofstream outputFile;
    outputFile.open(outputFilename);

    char c;
    while (inputFile.get(c)) {
        outputFile << decryptChar(c);
    }

    inputFile.close();
    outputFile.close();
}