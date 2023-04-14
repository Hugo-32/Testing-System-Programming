#include <iostream>
#include <locale>
#include "Students.h"
#include "Teacher.h"

using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Rus");
	int choice;
	do
	{
		cout << " Система тестирования по курсу программирование" << endl;
		cout << " =============================================" << endl;
		cout << " Выберите режим работы: " << endl;
		cout << " 1. Режим преподавателя" << endl;
		cout << " 2. Режим студента" << endl;
		cout << " 0. Выход из программы" << endl;
		cout << endl;
		cout << " Выберите режим: ";
		cin >> choice;
		cin.get();
		system("cls");
		switch (choice)
		{
		case 1:
			Teachers();
			system("cls");
			break;
		case 2:
			Students();
			system("cls");
			break;
		case 0:
			cout << " Выход из программы." << endl;
			break;
		default:
			system("cls");
			cout << " Ошибка: неверный пункт меню. Попробуйте ещё раз!" << endl << endl;
			break;
		}
	} while (choice != 0);
	
	return 0;
}