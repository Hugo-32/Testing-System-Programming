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

vector<Question> readQuestionsFromFile(const string& filename) {
	decrypt("File with the test base.txt", "decrypted.txt");
	vector<Question> questions;
	ifstream file(filename);
	string line;
	string current_theme;

	if (file.is_open()) {
		while (getline(file, line)) {
			if (line.find("THEME") != string::npos) {
				current_theme = line.substr(line.find(" - ") + 3);
			}
			else if (line.find(".") != string::npos) {
				Question question;
				question.theme = current_theme;
				question.text = line.substr(line.find(" ") + 1);

				while (getline(file, line) && !line.empty() && line.find("a)") == string::npos) {
					question.text += "\n" + line;
				}

				if (line.find("a)") != string::npos) {
					question.answers.push_back(line);
				}
				for (int i = 1; i < 4; i++) {
					getline(file, line);
					question.answers.push_back(line);
				}

				getline(file, line);
				question.correct_answer = line.substr(line.find(": ") + 2);
				questions.push_back(question);
			}
		}
		file.close();
	}

	encrypt("File with the test base.txt", "decrypted.txt");
	return questions;
}

string chooseTheme() {
	string theme;
	char choice;

	cout << "Выберите тему:" << endl;
	cout << "1. CYCLES" << endl;
	cout << "2. ARRAYS (ONE- AND TWO-DIMENSIONAL)" << endl;
	cout << "3. STRINGS" << endl;
	cout << "4. RECURSION" << endl;
	cout << "5. STRUCTURES" << endl;
	cout << "6. FILES" << endl;
	cout << "7. ADDRESSES AND SIGNS" << endl;
	cout << "8. DYNAMIC MEMORY" << endl;
	cin >> choice;

	switch (choice) {
	case '1':
		theme = "CYCLES.";
		break;
	case '2':
		theme = "ARRAYS (ONE- AND TWO-DIMENSIONAL).";
		break;
	case '3':
		theme = "STRINGS.";
		break;
	case '4':
		theme = "RECURSION.";
		break;
	case '5':
		theme = "STRUCTURES.";
		break;
	case '6':
		theme = "FILES.";
		break;
	case '7':
		theme = "ADDRESSESS AND SIGNS.";
		break;
	case '8':
		theme = "DYNAMIC MEMORY.";
		break;
	default:
		cout << "Неверный выбор. Введите число от 1 до 8." << endl;
		return chooseTheme();
	}

	return theme;
}

vector<Question> filterQuestionsByTheme(const vector<Question>& questions, const string& theme) {
	vector<Question> filtered_questions;

	for (const Question& question : questions) {
		if (question.theme == theme) {
			filtered_questions.push_back(question);
		}
	}

	return filtered_questions;
}

vector<Question> selectRandomQuestions(const vector<Question>& questions, int count) {
	vector<Question> selectedQuestions;
	vector<int> indices(questions.size());
	iota(indices.begin(), indices.end(), 0);

	mt19937 g(static_cast<unsigned>(time(nullptr)));
	shuffle(indices.begin(), indices.end(), g);

	for (int i = 0; i < count && i < questions.size(); i++) {
		selectedQuestions.push_back(questions[indices[i]]);
	}

	return selectedQuestions;
}