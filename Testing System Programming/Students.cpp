#define _CRT_SECURE_NO_WARNINGS
#include "Students.h"

using namespace std;

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

void Menu()
{
	int choice;
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

void Trening()
{
	int Title, n = 10, Otvet, StopList[10] = { 0 };
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
	cin >> Title;

	for (int i = 0; i <= n; i++)
	{

		do
		{
			cout << endl << " Введите ответ: ";
			cin >> Otvet;
			if (Otvet != Question[i].Result)
			{
				cout << " Ошибка. " << endl;
			}
		} while (Otvet != Question[i].Result);
	}
}

void Test()
{
	int Title, n = 10, wrong, right, wrongQuestions[10] = { 0 }, StopList[10] = { 0 };
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
	cin >> Title;

	for (int i = 0; i <= n; i++)
	{
		cout << endl << " Введите ответ: ";
		int Otvet;
		cin >> Otvet;
		if (Otvet == Question[i].Result)
		{
			cout << " Верно! " << endl << endl;
			right++;
		}
		else
		{
			cout << " Ошибка. " << endl << endl;
			wrong++;
			wrongQuestions[i] = 1;
		}
	}
	cout << " Оценка: ";
	int TestResult;
	if (n - wrong >= 9) { cout << " 5 " << endl; TestResult = 5; }
	else if (n - wrong >= 7) { cout << " 4 " << endl; TestResult = 4; }
	else if (n - wrong >= 5) { cout << " 3 " << endl; TestResult = 3; }
	else { cout << " 2 " << endl; TestResult = 2; }


}

void FinalTest()
{
	int n = 40, wrong, right, wrongQuestions[10] = { 0 };
	for (int i = 0; i <= n; i++)
	{
		cout << endl << " Введите ответ: ";
		int Otvet;
		cin >> Otvet;
		if (Otvet == Question[i].Result)
		{
			cout << " Верно! " << endl << endl;
			right++;
		}
		else
		{
			cout << " Ошибка. " << endl << endl;
			wrong++;
			wrongQuestions[i] = 1;
		}
	}
	cout << " Оценка: ";
	int TestResult;
	if (n - wrong >= 9) { cout << " 5 " << endl; TestResult = 5; }
	else if (n - wrong >= 7) { cout << " 4 " << endl; TestResult = 4; }
	else if (n - wrong >= 5) { cout << " 3 " << endl; TestResult = 3; }
	else { cout << " 2 " << endl; TestResult = 2; }


}