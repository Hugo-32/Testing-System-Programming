#define _CRT_SECURE_NO_WARNINGS
#include "Students.h"

using namespace std;

void Students()
{
	Student students[100];
	cout << " Режим студента " << endl;
	cout << " ==============" << endl;
	int NumberOfStudents = readStudents(students);
	int Pr = -1;
	do
	{
		Pr = Proverka(students, NumberOfStudents);
		if (Pr == -1) { cout << " Студент не найден" << endl << endl; }
		else 
		{ 
			cout << " Студент найден: "; 
			cout << students[Pr].firstName << " " << students[Pr].lastName << endl;
			cout << " Для перехода в меню выбора режима работы программы нажмите любую клавишу: " << endl << " ";
			cout << "=> ";
			_getch();
			system("cls");
			Menu(students, Pr);
		}
	} while (Pr == -1);
}

int Proverka(Student students[100], int NumberOfStudents)
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

void Menu(Student students[100], int Pr)
{
	int choice;
	TestResult TestRes;
	do
	{
		cout << " " << students[Pr].firstName << " " << students[Pr].lastName << endl;
		cout << " ==========================" << endl;
		cout << " Список операций: " << endl;
		cout << " 1. Тренинг по теме" << endl;
		cout << " 2. Тестирование по теме" << endl;
		cout << " 3. Итоговый тест" << endl;
		cout << " 0. Вернуться назад" << endl;
		cout << endl;
		cout << " Выберите операцию: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			Trening(TestRes);



			system("cls");
			break;
		case 2:
			Test(TestRes);



			system("cls");
			break;
		case 3:
			FinalTest(TestRes);



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

void Trening(TestResult &TestRes)
{
	int n = 10, Otvet, StopList[10] = { 0 };
	cout << " Выберите тему тренинга:" << endl
		<< " 1. Циклы" << endl
		<< " 2. Массивы (одномерные и двумерные)" << endl
		<< " 3. Строки" << endl
		<< " 4. Рекурсия" << endl
		<< " 5. Структуры" << endl
		<< " 6. Файлы" << endl
		<< " 7. Адреса и указатели" << endl
		<< " 8. Динамическая память" << endl
		<< " => ";
	cin >> TestRes.Title;

	for (int i = 0; i <= n; i++)
	{
		
		//do
		//{
		//	cout << endl << " Введите ответ: ";
		//	cin >> Otvet;
		//	if (Otvet != Question[i].Result)
		//	{
		//		cout << " Ошибка. " << endl;
		//	}
		//} while (Otvet != Question[i].Result);
	}
}

void Test (TestResult &TestRes)
{
	int Title, n = 10, wrong = 0, wrongQuestions[10] = {0}, StopList[10] = { 0 };
	cout << " Выберите тему тренинга:" << endl
		<< " 1. Циклы" << endl
		<< " 2. Массивы (одномерные и двумерные)" << endl
		<< " 3. Строки" << endl
		<< " 4. Рекурсия" << endl
		<< " 5. Структуры" << endl
		<< " 6. Файлы" << endl
		<< " 7. Адреса и указатели" << endl
		<< " 8. Динамическая память" << endl
		<< " => ";
	cin >> TestRes.Title;

	for (int i = 0; i <= n; i++)
	{
		cout << endl << " Введите ответ: ";
		int Otvet;
		cin >> Otvet;
		//if (Otvet == Question[i].Result)
		//{
		//	cout << " Верно! " << endl << endl;
		//}
		//else
		//{
		//	cout << " Ошибка. " << endl << endl;
		//	wrong++;
		//	wrongQuestions[i] = 1;
		//}
	}
	cout << " Оценка: ";
	if (n - wrong >= 9) { cout << " 5 " << endl; TestRes.Res = 5; }
	else if (n - wrong >= 7) { cout << " 4 " << endl; TestRes.Res = 4;}
	else if (n - wrong >= 5) { cout << " 3 " << endl; TestRes.Res = 3;}
	else { cout << " 2 " << endl; TestRes.Res = 2;}
	cout << " Для продолжения нажмите любую клавишу: ";
	_getch();
}

void FinalTest(TestResult &TestRes)
{
	int n = 40, wrong = 0, right, wrongQuestions[10] = { 0 };
	for (int i = 0; i <= n; i++)
	{
		cout << endl << " Введите ответ: ";
		int Otvet;
		cin >> Otvet;
		//if (Otvet == Question[i].Result)
		//{
		//	cout << " Верно! " << endl << endl;
		//	right++;
		//}
		//else
		//{
		//	cout << " Ошибка. " << endl << endl;
		//	wrong++;
		//	wrongQuestions[i] = 1;
		//}
	}
	cout << " Оценка: ";
	if (n - wrong >= 9) { cout << " 5 " << endl; TestRes.Res = 5; }
	else if (n - wrong >= 7) { cout << " 4 " << endl; TestRes.Res = 4; }
	else if (n - wrong >= 5) { cout << " 3 " << endl; TestRes.Res = 3; }
	else { cout << " 2 " << endl; TestRes.Res = 2; }
	cout << " Для продолжения нажмите любую клавишу: ";
	_getch();
}