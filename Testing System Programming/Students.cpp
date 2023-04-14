#define _CRT_SECURE_NO_WARNINGS
#include "Students.h"
#include "CaesarCipher.h"

using namespace std;

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

void Trening(const vector<Question>& questions)
{
	string theme = chooseTheme();
	vector<Question> theme_questions = filterQuestionsByTheme(questions, theme);
	vector<Question> random_questions = selectRandomQuestions(theme_questions, 10);
	char finish;

	for (const auto& question : random_questions) {
		cout << question.text << endl;
		for (const auto& answer : question.answers) {
			cout << answer << endl;
		}

		bool flag_right_answer = false;
		string user_answer;
		cout << "Введите ваш ответ (a, b, c или d): ";

		do {
			cin >> user_answer;
			string user_answer_str = user_answer + ")";

			if (user_answer_str == question.correct_answer.substr(0, 2)) {
				cout << "Верно!" << endl;
				flag_right_answer = true;
			}
			else {
				cout << "Неверно. Попробуйте ещё раз: ";
			}
		} while (!flag_right_answer);
	}

	theme.erase(theme.find("."), 1);

	cout << "Тренинг по теме '" << theme << "' завершён." << endl;

	do {
		cout << "Чтобы завершить тест, введите '0'." << endl;
		cin >> finish;
	} while (finish != '0');
}

void Test(const vector<Question>& questions)
{
	string theme = chooseTheme();
	vector<Question> theme_questions = filterQuestionsByTheme(questions, theme);
	vector<Question> random_questions = selectRandomQuestions(theme_questions, 10);
	vector<string> wrong_questions;
	int wrong_answers = 0, test_result;
	char finish;

	for (const auto& question : random_questions) {
		cout << question.text << endl;
		for (const auto& answer : question.answers) {
			cout << answer << endl;
		}

		cout << "Введите ваш ответ (a, b, c или d): ";
		string user_answer;
		do {
			cin >> user_answer;
		} while ((user_answer != "a") && (user_answer != "b") && (user_answer != "c") && (user_answer != "d"));

		string user_answer_str = user_answer + ")";

		if (user_answer_str != question.correct_answer.substr(0, 2)) {
			wrong_questions.push_back(question.text);
			wrong_answers++;
		}
	}

	if (wrong_answers <= 2) test_result = 5;
	else if (wrong_answers == 3) test_result = 4;
	else if (wrong_answers > 3 && wrong_answers <= 5) test_result = 3;
	else test_result = 2;

	cout << "=============================================" << endl;
	cout << "Количество ошибок: " << wrong_answers << "." << endl;
	cout << "Оценка за тест: " << test_result << "." << endl;
	cout << "=============================================" << endl;
	cout << "\tВопросы, в которых допущены ошибки:" << endl;
	for (const auto& wrong_questions : wrong_questions) {
		cout << wrong_questions << endl;
	}
	cout << "=============================================" << endl;
	cout << "Чтобы завершить тест, введите '0'." << endl;

	do {
		cin >> finish;
	} while (finish != '0');
}

void FinalTest(const vector<Question>& questions)
{
	vector<Question> random_questions = selectRandomQuestions(questions, 40);
	vector<string> wrong_questions;
	int wrong_answers = 0, test_result;
	char finish;

	for (const auto& question : random_questions) {
		cout << question.text << endl;
		for (const auto& answer : question.answers) {
			cout << answer << endl;
		}

		cout << "Введите ваш ответ (a, b, c или d): ";
		string user_answer;
		do {
			cin >> user_answer;
		} while ((user_answer != "a") && (user_answer != "b") && (user_answer != "c") && (user_answer != "d"));

		string user_answer_str = user_answer + ")";

		if (user_answer_str != question.correct_answer.substr(0, 2)) {
			wrong_questions.push_back(question.text);
			wrong_answers++;
		}
	}

	if (wrong_answers <= 7) test_result = 5;
	else if (wrong_answers > 7 && wrong_answers <= 13) test_result = 4;
	else if (wrong_answers > 13 && wrong_answers <= 20) test_result = 3;
	else test_result = 2;

	cout << "=============================================" << endl;
	cout << "\tКоличество ошибок: " << wrong_answers << "." << endl;
	cout << "\tОценка за тест: " << test_result << "." << endl;
	cout << "=============================================" << endl;
	cout << "Вопросы, в которых допущены ошибки:" << endl;
	for (const auto& wrong_questions : wrong_questions) {
		cout << wrong_questions << endl;
	}
	cout << "=============================================" << endl;
	cout << "Чтобы завершить тест, введите '0'." << endl;

	do {
		cin >> finish;
	} while (finish != '0');
}

void Menu()
{
	int choice;
	vector<Question> questions = readQuestionsFromFile("decrypted.txt");
	do
	{
		cout << " Имя и фамилия студента" << endl;
		cout << " =============================================" << endl;
		cout << " Список операций: " << endl;
		cout << " 1. Тренинг по теме" << endl;
		cout << " 2. Тестирование по теме" << endl;
		cout << " 3. Итоговый тест" << endl;
		cout << " 0. Выход из программы" << endl;
		cout << endl;
		cout << " Выберите операцию: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			Trening;
			system("cls");
			break;
		case 2:
			Test();
			system("cls");
			break;
		case 3:
			FinalTest();
			system("cls");
			break;
		case 0:
			cout << "Выход из программы." << endl;
			break;
		default:
			system("cls");
			cout << " Ошибка: неверный пункт меню. Попробуйте ещё раз!" << endl << endl;
			break;
		}
	} while (choice != 0);
}

void Students()
{
	int Pr = Proverka();

}

int Proverka()
{
	char Login[255], Password[255];
	cout << " Введите логин: ";
	gets_s(Login, 255);
	cout << " Введите пароль: ";
	gets_s(Password, 255);
}