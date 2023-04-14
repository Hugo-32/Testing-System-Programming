#define _CRT_SECURE_NO_WARNINGS
#include "Students.h"

using namespace std;

void Students()
{
	Student students[100];
	cout << " ����� �������� " << endl;
	cout << " ==============" << endl;
	int NumberOfStudents = readStudents(students);
	int Pr = -1;
	do
	{
		Pr = Proverka(students, NumberOfStudents);
		if (Pr == -1) { cout << " ������� �� ������" << endl << endl; }
		else 
		{ 
			cout << " ������� ������: "; 
			cout << students[Pr].firstName << " " << students[Pr].lastName << endl;
			cout << " ��� �������� � ���� ������ ������ ������ ��������� ������� ����� �������: " << endl << " ";
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

void Menu(Student students[100], int Pr)
{
	int choice;
	TestResult TestRes;
	do
	{
		cout << " " << students[Pr].firstName << " " << students[Pr].lastName << endl;
		cout << " ==========================" << endl;
		cout << " ������ ��������: " << endl;
		cout << " 1. ������� �� ����" << endl;
		cout << " 2. ������������ �� ����" << endl;
		cout << " 3. �������� ����" << endl;
		cout << " 0. ��������� �����" << endl;
		cout << endl;
		cout << " �������� ��������: ";
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
			cout << "����� �� ���������." << endl;
			break;
		default:
			system("cls");
			cout << " ������: �������� ����� ����. ���������� ��� ���!" << endl << endl;
			break;
		}
	} while (choice != 0);
}

void Trening(TestResult &TestRes)
{
	int n = 10, Otvet, StopList[10] = { 0 };
	cout << " �������� ���� ��������:" << endl
		<< " 1. �����" << endl
		<< " 2. ������� (���������� � ���������)" << endl
		<< " 3. ������" << endl
		<< " 4. ��������" << endl
		<< " 5. ���������" << endl
		<< " 6. �����" << endl
		<< " 7. ������ � ���������" << endl
		<< " 8. ������������ ������" << endl
		<< " => ";
	cin >> TestRes.Title;

	for (int i = 0; i <= n; i++)
	{
		
		//do
		//{
		//	cout << endl << " ������� �����: ";
		//	cin >> Otvet;
		//	if (Otvet != Question[i].Result)
		//	{
		//		cout << " ������. " << endl;
		//	}
		//} while (Otvet != Question[i].Result);
	}
}

void Test (TestResult &TestRes)
{
	int Title, n = 10, wrong = 0, wrongQuestions[10] = {0}, StopList[10] = { 0 };
	cout << " �������� ���� ��������:" << endl
		<< " 1. �����" << endl
		<< " 2. ������� (���������� � ���������)" << endl
		<< " 3. ������" << endl
		<< " 4. ��������" << endl
		<< " 5. ���������" << endl
		<< " 6. �����" << endl
		<< " 7. ������ � ���������" << endl
		<< " 8. ������������ ������" << endl
		<< " => ";
	cin >> TestRes.Title;

	for (int i = 0; i <= n; i++)
	{
		cout << endl << " ������� �����: ";
		int Otvet;
		cin >> Otvet;
		//if (Otvet == Question[i].Result)
		//{
		//	cout << " �����! " << endl << endl;
		//}
		//else
		//{
		//	cout << " ������. " << endl << endl;
		//	wrong++;
		//	wrongQuestions[i] = 1;
		//}
	}
	cout << " ������: ";
	if (n - wrong >= 9) { cout << " 5 " << endl; TestRes.Res = 5; }
	else if (n - wrong >= 7) { cout << " 4 " << endl; TestRes.Res = 4;}
	else if (n - wrong >= 5) { cout << " 3 " << endl; TestRes.Res = 3;}
	else { cout << " 2 " << endl; TestRes.Res = 2;}
	cout << " ��� ����������� ������� ����� �������: ";
	_getch();
}

void FinalTest(TestResult &TestRes)
{
	int n = 40, wrong = 0, right, wrongQuestions[10] = { 0 };
	for (int i = 0; i <= n; i++)
	{
		cout << endl << " ������� �����: ";
		int Otvet;
		cin >> Otvet;
		//if (Otvet == Question[i].Result)
		//{
		//	cout << " �����! " << endl << endl;
		//	right++;
		//}
		//else
		//{
		//	cout << " ������. " << endl << endl;
		//	wrong++;
		//	wrongQuestions[i] = 1;
		//}
	}
	cout << " ������: ";
	if (n - wrong >= 9) { cout << " 5 " << endl; TestRes.Res = 5; }
	else if (n - wrong >= 7) { cout << " 4 " << endl; TestRes.Res = 4; }
	else if (n - wrong >= 5) { cout << " 3 " << endl; TestRes.Res = 3; }
	else { cout << " 2 " << endl; TestRes.Res = 2; }
	cout << " ��� ����������� ������� ����� �������: ";
	_getch();
}