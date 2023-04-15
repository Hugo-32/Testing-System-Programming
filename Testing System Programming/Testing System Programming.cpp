#include <iostream>
#include <locale>
#include "Students.h"
#include "Teacher.h"

using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Rus");
	int choice, l = 0;
	do
	{
		cout << " Система тестирования по курсу \"Программирование\" " << endl;
		cout << " =============================================" << endl;
		cout << " Выберите режим доступа: " << endl;
		cout << " 1. Режим преподавателя" << endl;
		cout << " 2. Режим студента" << endl;
		cout << " 0. Выход из программы" << endl;
		cout << endl;
		if (l==1) 
		{
			cout << " Ошибка: неверный пункт меню. Попробуйте ещё раз!" << endl;
			l = 0;
		}
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
			cout << " Выход из программы " << endl;
			break;
		default:
			l = 1;
			break;
		}
	} while (choice != 0);
	
	return 0;
}