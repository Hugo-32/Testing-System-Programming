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
		cout << " ����� �������� " << endl;
		cout << " ==============" << endl;
		Pr = Proverka(students, NumberOfStudents);
		if (Pr == -1) 
		{ 
			cout << " �������� ����� ��� ������" << endl; 
			cout << " ��� ����������� � ������� ���� ������� \" 0 \": ";
			cin >> Break;
			cin.get();
			if (Break == 0) { break; }
		}
		else 
		{ 
			cout << " ������������, "; 
			cout << students[Pr].firstName << " " << students[Pr].lastName << endl;
			cout << " ��� �������� � ������ �������� ������� ����� �������: " << endl << " ";
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
	cout << " ������� �����: ";
	gets_s(Login, 255);
	for (int i = 0; i < NumberOfStudents; i++)
	{
		if (students[i].login == Login)
		{
			NumberSt = i;
			break;
		}
	}

	cout << " ������� ������: ";
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
		cout << " ������ ��������: " << endl;
		cout << " 1. ������� �� ����" << endl;
		cout << " 2. ������������ �� ����" << endl;
		cout << " 3. �������� ����" << endl;
		cout << " 0. ����� �� ������� ������" << endl;
		cout << endl;
		cout << " �������� ��������: ";
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
			cout << " ����� �� ������� ������" << endl;
			break;
		default:
			system("cls");
			cout << " ������: �������� ����� ����. ���������� ��� ���!" << endl << endl;
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
		cout << "������� ��� ����� (a, b, c ��� d): ";

		do {
			cin >> user_answer;
			string user_answer_str = user_answer + ")";

			if (user_answer_str == question.correct_answer.substr(0, 2)) {
				cout << "�����!" << endl << endl;
				flag_right_answer = true;
			}
			else {
				cout << "�������. ���������� ��� ���: ";
			}
		} while (!flag_right_answer);
		l++;
	}

	theme.erase(theme.find("."), 1);

	cout << "������� �� ���� '" << theme << "' ��������." << endl;

	cout << "��� ����������� ������� ����� �������: ";
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

		cout << "������� ��� ����� (a, b, c ��� d): ";
		string user_answer;
		do {
			cin >> user_answer;
			if ((user_answer != "a") && (user_answer != "b") && (user_answer != "c") && (user_answer != "d")) { cout << "������������ ����. ���������� ��� ���: "; }
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
	cout << "���������� ������: " << wrong_answers << "." << endl;
	cout << "������ �� ����: " << test_result << "." << endl;
	cout << "=============================================" << endl;
	cout << "\t�������, � ������� �������� ������:" << endl;
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
	cout << "��� ����������� ������� ����� �������: ";
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
	cout << "�������� ���� " << endl;
	cout << "================" << endl;

	int l = 1;

	for (const auto& question : random_questions) {
		cout << l << ". " << question.text << endl;
		for (const auto& answer : question.answers) {
			cout << answer << endl;
		}

		cout << "������� ��� ����� (a, b, c ��� d): ";
		string user_answer;
		do {
			cin >> user_answer;
			if ((user_answer != "a") && (user_answer != "b") && (user_answer != "c") && (user_answer != "d")) { cout << "������������ ����. ���������� ��� ���: "; }
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
	cout << "\t���������� ������: " << wrong_answers << "." << endl;
	cout << "\t������ �� ����: " << test_result << "." << endl;
	cout << "=============================================" << endl;
	cout << "��� ����������� ������� ����� �������: ";
	_getch();
	system("cls");
	students[Pr].testGrade = test_result;
	writeEstimation(students, NumberOfStudents);
}