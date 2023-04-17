#define _CRT_SECURE_NO_WARNINGS
#include "Students.h"

using namespace std;

void Students()
{
	Student students[MAX_STUDENTS];
	int NumberOfStudents = readStudents(students);
	int Pr = -1;
	int Break = 1;
	do
	{
		system("cls"); 
		cout << " Режим студента " << endl;
		cout << " ==============" << endl;
		Pr = Proverka(students, NumberOfStudents);
		if (Pr == -1) 
		{ 
			cout << " Неверный логин или пароль" << endl; 
			cout << " Для возвращения в главное меню введите \" 0 \": ";
			cin >> Break;
			cin.get();
			if (Break == 0) { break; }
		}
		else 
		{ 
			cout << " Здравствуйте, "; 
			cout << students[Pr].firstName << " " << students[Pr].lastName << endl;
			cout << " Для перехода к списку операций нажмите любую клавишу: " << endl << " ";
			cout << "=> ";
			_getch();
			system("cls");
			Menu(students, Pr, NumberOfStudents);
		}
	} while (Pr == -1);
}

int Proverka(Student students[MAX_STUDENTS], int NumberOfStudents)
{
	char Login[255], Password[255];
	int NumberSt = -1;
	cout << " Введите логин: ";
	gets_s(Login, 255);
	for (int i = 0; i < NumberOfStudents; i++)
	{
		if (students[i].login == Login)
		{
			NumberSt = i;
			break;
		}
	}

	cout << " Введите пароль: ";
	gets_s(Password, 255);
	if (students[NumberSt].password == Password)
	{
		return NumberSt;
	}
	else { return -1; }
}

void Menu(Student students[MAX_STUDENTS], int Pr, int NumberOfStudents)
{
	int choice;
	vector<Question> questions = readQuestionsFromFile("decrypted.txt");
	do
	{
		cout << " " << students[Pr].firstName << " " << students[Pr].lastName << endl;
		cout << " ==========================" << endl;
		cout << " Список операций: " << endl;
		cout << " 1. Тренинг по теме" << endl;
		cout << " 2. Тестирование по теме" << endl;
		cout << " 3. Итоговый тест" << endl;
		cout << " 0. Выйти из учетной записи" << endl;
		cout << endl;
		cout << " Выберите операцию: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls"); 
			trainingMode(questions);
			break;
		case 2:
			system("cls"); 
			testingMode(questions, students, NumberOfStudents, Pr);
			break;
		case 3:
			system("cls"); 
			finalTest(questions, students, NumberOfStudents, Pr);
			break;
		case 0:
			cout << " Выйти из учетной записи" << endl;
			break;
		default:
			system("cls");
			cout << " Ошибка: неверный пункт меню. Попробуйте ещё раз!" << endl << endl;
			break;
		}
	} while (choice != 0);
}

void trainingMode(const vector<Question>& questions)
{
	string theme = chooseTheme();
	vector<Question> theme_questions = filterQuestionsByTheme(questions, theme);
	vector<Question> random_questions = selectRandomQuestions(theme_questions, 10);
	char finish;

	system("cls");
	cout << theme << endl << endl;
	
	int l = 1;

	for (const auto& question : random_questions) {
		cout << l << ". " << question.text << endl;
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
				cout << "Верно!" << endl << endl;
				flag_right_answer = true;
			}
			else {
				cout << "Неверно. Попробуйте ещё раз: ";
			}
		} while (!flag_right_answer);
		l++;
	}

	theme.erase(theme.find("."), 1);

	cout << "Тренинг по теме '" << theme << "' завершён." << endl;

	cout << "Для продолжения нажмите любую клавишу: ";
	_getch();
	system("cls");
}

void testingMode(const vector<Question>& questions, Student students[MAX_STUDENTS], int NumberOfStudents, int Pr) 
{
	string theme = chooseTheme();
	vector<Question> theme_questions = filterQuestionsByTheme(questions, theme);
	vector<Question> random_questions = selectRandomQuestions(theme_questions, 10);
	vector<string> wrong_questions;
	int wrong_answers = 0, test_result;
	char finish;

	system("cls");
	cout << theme << endl << endl;

	int l = 1;

	for (const auto& question : random_questions) {
		cout << l << ". " << question.text << endl;
		for (const auto& answer : question.answers) {
			cout << answer << endl;
		}
		l++;

		cout << "Введите ваш ответ (a, b, c или d): ";
		string user_answer;
		do {
			cin >> user_answer;
			if ((user_answer != "a") && (user_answer != "b") && (user_answer != "c") && (user_answer != "d")) { cout << "Некорректный ввод. Попробуйте еще раз: "; }
		} while ((user_answer != "a") && (user_answer != "b") && (user_answer != "c") && (user_answer != "d"));
		cout << endl;

		string user_answer_str = user_answer + ")";

		if (user_answer_str != question.correct_answer.substr(0, 2)) 
		{
			string answer = "Answer: (" + question.correct_answer.substr(0, 2);
			wrong_questions.push_back(question.text);
			wrong_questions.push_back(answer);
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
	double  k = 1;
	for (const auto& wrong_questions : wrong_questions) 
	{
		if (int(k * 10) % 10 == 0)
		{
			cout << k << ". " << wrong_questions << endl;
		}
		else
		{
			cout <<  wrong_questions << endl;
		}
		k+=0.5;
	}
	cout << "=============================================" << endl;
	cout << "Для продолжения нажмите любую клавишу: ";
	_getch();
	system("cls");

	int choice = 0;
	if (theme == "CYCLES.")
	{
		choice = 1;
	}
	else
	{
		if (theme == "ARRAYS (ONE- AND TWO-DIMENSIONAL).")
		{
			choice = 2;
		}
		else
		{
			if (theme == "STRINGS.")
			{
				choice = 3;
			}
			else
			{
				if (theme == "RECURSION.")
				{
					choice = 4;
				}
				else
				{
					if (theme == "STRUCTURES.")
					{
						choice = 5;
					}
					else
					{
						if (theme == "FILES.")
						{
							choice = 6;
						}
						else
						{
							if (theme == "ADDRESSESS AND SIGNS.")
							{
								choice = 7;
							}
							else
							{
								if (theme == "DYNAMIC MEMORY.")
								{
									choice = 8;
								}
							}
						}
					}
				}
			}
		}
	}
	students[Pr].grades[choice-1] = test_result;
	writeEstimation(students, NumberOfStudents);
}

void finalTest(const vector<Question>& questions, Student students[MAX_STUDENTS], int NumberOfStudents, int Pr)
{
	vector<Question> random_questions = selectRandomQuestions(questions, 40);
	vector<string> wrong_questions;
	int wrong_answers = 0, test_result;
	char finish;

	system("cls");
	cout << "Итоговый тест " << endl;
	cout << "================" << endl;

	int l = 1;

	for (const auto& question : random_questions) {
		cout << l << ". " << question.text << endl;
		for (const auto& answer : question.answers) {
			cout << answer << endl;
		}

		cout << "Введите ваш ответ (a, b, c или d): ";
		string user_answer;
		do {
			cin >> user_answer;
			if ((user_answer != "a") && (user_answer != "b") && (user_answer != "c") && (user_answer != "d")) { cout << "Некорректный ввод. Попробуйте еще раз: "; }
		} while ((user_answer != "a") && (user_answer != "b") && (user_answer != "c") && (user_answer != "d"));
		cout << endl;

		string user_answer_str = user_answer + ")";

		if (user_answer_str != question.correct_answer.substr(0, 2)) {
			wrong_questions.push_back(question.text);
			wrong_answers++;
		}
		l++;
	}

	if (wrong_answers <= 7) test_result = 5;
	else if (wrong_answers > 7 && wrong_answers <= 13) test_result = 4;
	else if (wrong_answers > 13 && wrong_answers <= 20) test_result = 3;
	else test_result = 2;

	cout << "=============================================" << endl;
	cout << "\tКоличество ошибок: " << wrong_answers << "." << endl;
	cout << "\tОценка за тест: " << test_result << "." << endl;
	cout << "=============================================" << endl;
	cout << "Для продолжения нажмите любую клавишу: ";
	_getch();
	system("cls");
	students[Pr].testGrade = test_result;
	writeEstimation(students, NumberOfStudents);
}