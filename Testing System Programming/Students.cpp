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
	cout << " ������� �����: ";
	gets_s(Login, 255);
	cout << " ������� ������: ";
	gets_s(Password, 255);
}

void Menu()
{
	int choice;
	do
	{
		cout << " ��� � ������� ��������" << endl;
		cout << " =============================================" << endl;
		cout << " ������ ��������: " << endl;
		cout << " 1. ������� �� ����" << endl;
		cout << " 2. ������������ �� ����" << endl;
		cout << " 3. �������� ����" << endl;
		cout << " 0. ����� �� ���������" << endl;
		cout << endl;
		cout << " �������� ��������: ";
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
			cout << "����� �� ���������." << endl;
			break;
		default:
			system("cls");
			cout << " ������: �������� ����� ����. ���������� ��� ���!" << endl << endl;
			break;
		}
	} while (choice != 0);
}

void Trening()
{
	int Title, n = 10, Otvet, StopList[10] = { 0 };
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
	cin >> Title;

	for (int i = 0; i <= n; i++)
	{

		do
		{
			cout << endl << " ������� �����: ";
			cin >> Otvet;
			if (Otvet != Question[i].Result)
			{
				cout << " ������. " << endl;
			}
		} while (Otvet != Question[i].Result);
	}
}

void Test()
{
	int Title, n = 10, wrong, right, wrongQuestions[10] = { 0 }, StopList[10] = { 0 };
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
	cin >> Title;

	for (int i = 0; i <= n; i++)
	{
		cout << endl << " ������� �����: ";
		int Otvet;
		cin >> Otvet;
		if (Otvet == Question[i].Result)
		{
			cout << " �����! " << endl << endl;
			right++;
		}
		else
		{
			cout << " ������. " << endl << endl;
			wrong++;
			wrongQuestions[i] = 1;
		}
	}
	cout << " ������: ";
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
		cout << endl << " ������� �����: ";
		int Otvet;
		cin >> Otvet;
		if (Otvet == Question[i].Result)
		{
			cout << " �����! " << endl << endl;
			right++;
		}
		else
		{
			cout << " ������. " << endl << endl;
			wrong++;
			wrongQuestions[i] = 1;
		}
	}
	cout << " ������: ";
	int TestResult;
	if (n - wrong >= 9) { cout << " 5 " << endl; TestResult = 5; }
	else if (n - wrong >= 7) { cout << " 4 " << endl; TestResult = 4; }
	else if (n - wrong >= 5) { cout << " 3 " << endl; TestResult = 3; }
	else { cout << " 2 " << endl; TestResult = 2; }


}