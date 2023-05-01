#define _CRT_SECURE_NO_WARNINGS
#include "Teacher.h"

using namespace std;

void Teachers()
{
	Teacher Teachers[MAX_TEACHERS];
	int NumberOfTeachers = readTeachers(Teachers);
	int Pr = -1;
	int Break = 1;
	do
	{
		system("cls");
		cout << " ����� ������������� " << endl;
		cout << " ===========================" << endl;
		Pr = Proverka(Teachers, NumberOfTeachers);
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
			cout << Teachers[Pr].firstName << " " << Teachers[Pr].lastName << endl;
			cout << " ��� �������� � ������ �������� ������� ����� �������: " << endl << " ";
			cout << "=> ";
			_getch();
			system("cls");
			Menu(Teachers, Pr, NumberOfTeachers);
		}
	} while (Pr == -1);
}

int Proverka(Teacher Teachers[MAX_TEACHERS], int NumberOfTeachers)
{
	char Login[255], Password[255];
	int NumberSt = -1;
	cout << " ������� �����: ";
	gets_s(Login, 255);
	for (int i = 0; i < NumberOfTeachers; i++)
	{
		if (Teachers[i].login == Login)
		{
			NumberSt = i;
			break;
		}
	}

	cout << " ������� ������: ";
	gets_s(Password, 255);
	if (Teachers[NumberSt].password == Password)
	{
		return NumberSt;
	}
	else { return -1; }
}

void Menu(Teacher Teachers[MAX_TEACHERS], int Pr, int NumberOfTeachers)
{
	int choice;
	do
	{
		cout << " " << Teachers[Pr].firstName << " " << Teachers[Pr].lastName << endl;
		cout << " ==========================" << endl;
		cout << " ������ ��������: " << endl;
		cout << " 1. �������������� ��������" << endl;
		cout << " 2. ������ �� ������� ���������" << endl;
		cout << " 0. ����� �� ������� ������" << endl;
		cout << endl;
		cout << " �������� ��������: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			Editing_Questions(Teachers, Pr, NumberOfTeachers);
			break;
		case 2:
			system("cls");
			Editing_Students(Teachers, Pr, NumberOfTeachers);
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

void Editing_Questions(Teacher Teachers[MAX_TEACHERS], int Pr, int NumberOfTeachers)
{
	int choice;
	do
	{
		cout << " " << Teachers[Pr].firstName << " " << Teachers[Pr].lastName << endl;
		cout << " ==========================" << endl;
		cout << " ������ ��������: " << endl;
		cout << " 1. �������� ��������" << endl;
		cout << " 2. ���������� ��������" << endl;
		cout << " 3. ��������� ��������" << endl;
		cout << " 0. ��������� �����" << endl;
		cout << endl;
		cout << " �������� ��������: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			Del_Questions();
			break;
		case 2:
			system("cls");
			Add_Questions();
			break;
		case 3:
			system("cls");
			Edit_Questions();
			break;
		case 0:
			system("cls"); 
			cout << " ����������� �����" << endl;
			break;
		default:
			system("cls");
			cout << " ������: �������� ����� ����. ���������� ��� ���!" << endl << endl;
			break;
		}
	} while (choice != 0);
}

void Editing_Students(Teacher Teachers[MAX_TEACHERS], int Pr, int NumberOfTeachers)
{
	int choice;	
	Student students[MAX_STUDENTS];
	int NumberOfStudents = readStudents(students);
	do
	{
		cout << " " << Teachers[Pr].firstName << " " << Teachers[Pr].lastName << endl;
		cout << " ==========================" << endl;
		cout << " ������ ��������: " << endl;
		cout << " 1. �������� � ����������� ���������" << endl;
		cout << " 2. ��������� ��������� ���������" << endl;
		cout << " 3. ����� ������ ��������� � ��������" << endl;
		cout << " 0. ��������� �����" << endl;
		cout << endl;
		cout << " �������� ��������: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			Del_Add_Students(Teachers, Pr, NumberOfTeachers, students, NumberOfStudents);
			break;
		case 2:
			system("cls");
			Edit_Estimation_Of_Students(students, NumberOfStudents);
			break;
		case 3:
			system("cls");
			Print_List_Of_Students(Teachers, Pr, NumberOfTeachers, students, NumberOfStudents);
			break;
		case 0:
			cout << "  ����������� �����" << endl;
			cout << "��� ����������� ������� ����� �������: ";
			_getch();
			system("cls");
			break;
		default:
			system("cls");
			cout << " ������: �������� ����� ����. ���������� ��� ���!" << endl << endl;
			break;
		}
	} while (choice != 0);
	writeEstimation(students, NumberOfStudents);
}

void Del_Questions()
{

}

void Add_Questions()
{

}

void Edit_Questions()
{

}

void Del_Add_Students(Teacher Teachers[MAX_TEACHERS], int Pr, int NumberOfTeachers, Student* students, int& NumberOfStudents)
{
	int choice;
	do
	{
		cout << " " << Teachers[Pr].firstName << " " << Teachers[Pr].lastName << endl;
		cout << " ==========================" << endl;
		cout << " ������ ��������: " << endl;
		cout << " 1. �������� ���������" << endl;
		cout << " 2. ���������� ���������" << endl;
		cout << " 0. ��������� �����" << endl;
		cout << endl;
		cout << " �������� ��������: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			Del_Students(students, NumberOfStudents);
			system("cls");
			break;
		case 2:
			system("cls");
			Add_Students(students, NumberOfStudents);
			system("cls");
			break;
		case 0:
			cout << " ����������� �����" << endl;
			cout << "��� ����������� ������� ����� �������: ";
			_getch();
			system("cls");
			break;
		default:
			system("cls");
			cout << " ������: �������� ����� ����. ���������� ��� ���!" << endl << endl;
			break;
		}
	} while (choice != 0);
	writeEstimation(students, NumberOfStudents);
}

void Del_Students(Student* students, int &count)
{
	char choice = 'N';
	int Break = 1, Number_Del;
	do
	{
		cin.get();
		cout << " �� ������������� ������ ������� ������ ��������? (Y/N): ";
		cin >> choice;
		if (choice == 'N') 
		{ 
			cout << " ����������� �����" << endl;
			cout << "��� ����������� ������� ����� �������: ";
			_getch();
			system("cls");
		}
		else
		{
			string firstName, lastName;
			do
			{
				cin.get();
				cout << " ������� ��� ��������: ";
				cin >> firstName;
				cin.get();
				cout << " ������� ������� ��������: ";
				cin >> lastName;
				for (int i = 0; i < count; i++)
				{
					if ((students[i].firstName == firstName) and (students[i].lastName == lastName))
					{
						Number_Del = i;
						cout << " ������� ������. ������ � �������� �������" << endl;
						Break = 0;
						break;
					}
					else
					{
						cout << " ������� �� ������. ���������� �����" << endl;
						cout << " ��� ����������� � ������� ���� ������� \" 0 \": ";
						cin >> Break;
						cin.get();
						if ((Break != 0) and (Break != 1)) { Break == 1; }
					}
				}
			} while (Break == 1);
			count--;
			for (int i = Number_Del; i < count; i++)
			{
				students[i].firstName = students[i + 1].firstName;
				students[i].lastName = students[i + 1].lastName;
				students[i].login = students[i + 1].login;
				students[i].password = students[i + 1].password;
				for (int j = 0; j < MAX_GRADES; j++)
				{
					students[i].grades[j] = students[i + 1].grades[j];
				}
				students[i].testGrade = students[i + 1].testGrade;
			}

			cout << " ������ ������� ������ ��� ������ ��������? (Y/N): ";
			cin >> choice;
			if (choice == 'N')
			{
				cout << " ����������� �����" << endl;
			}
		}
		cout << "��� ����������� ������� ����� �������: ";
		_getch();
		system("cls");
	} while (choice != 'N');
}

void Add_Students(Student* students, int &count)
{
	char choice = 'N';
	int Break = 1, Number_Del;
	do
	{
		cin.get();
		cout << " �� ������������� ������ �������� ������ ������ ��������? (Y/N): ";
		cin >> choice;
		if (choice == 'N')
		{
			cout << " ����������� �����" << endl;
			cout << "��� ����������� ������� ����� �������: ";
			_getch();
			system("cls");
		}
		else
		{
			string firstName, lastName, login, password, theme;
			int grades[MAX_GRADES], testGrade;
			int Number_Of_Theme = 1;
			cin.get();
			cout << " ������� ��� ��������: ";
			cin >> firstName;
			cin.get();
			cout << " ������� ������� ��������: ";
			cin >> lastName;
			cout << " ������� ����� ��������: ";
			cin >> login;
			cout << " ������� ������ ��������: ";
			cin >> password;
			for (int j = 0; j < MAX_GRADES; j++)
			{
				if (Number_Of_Theme == 1)
				{
					theme = "CYCLES.";
				}
				else
				{
					if (Number_Of_Theme == 2)
					{
						theme = "ARRAYS (ONE- AND TWO-DIMENSIONAL).";
					}
					else
					{
						if (Number_Of_Theme == 3)
						{
							theme = "STRINGS.";
						}
						else
						{
							if (Number_Of_Theme == 4)
							{
								theme = "RECURSION.";
							}
							else
							{
								if (Number_Of_Theme == 5)
								{
									theme = "STRUCTURES.";
								}
								else
								{
									if (Number_Of_Theme == 6)
									{
										theme = "FILES.";
									}
									else
									{
										if (Number_Of_Theme == 7)
										{
											theme = "ADDRESSESS AND SIGNS.";
										}
										else
										{
											if (Number_Of_Theme == 8)
											{
												theme = "DYNAMIC MEMORY.";
											}
										}
									}
								}
							}
						}
					}
				}
				do
				{
					cout << " ������� ������ �������� �� ����� �� ���� ";
					cout << theme << " : ";
					cin >> grades[j];
					if ((grades[j] > 5) or (grades[j] < 1)) { cout << " ������� �������� ������. ���������� �����" << endl; }
				} while ((grades[j] > 5) or (grades[j] < 1));
				Number_Of_Theme++;
			}
			cout << " ������� ������ �������� �� �������� ����: ";
			cin >> testGrade;
			students[count].firstName = firstName;
			students[count].lastName = lastName;
			students[count].login = login;
			students[count].password = password;
			for (int j = 0; j < MAX_GRADES; j++)
			{
				students[count].grades[j] = grades[j];
			}
			students[count].testGrade = testGrade;
			count++;

			cout << " ������ �������� ������ ��� ��� ������ ������ ��������? (Y/N): ";
			cin >> choice;
			if (choice == 'N')
			{
				cout << " ����������� �����" << endl;
			}
		}
		cout << "��� ����������� ������� ����� �������: ";
		_getch();
		system("cls");
	} while (choice != 'N');
}

void Edit_Estimation_Of_Students(Student* students, int& count)
{
	char choice = 'N';
	int Break = 1, Number;
	do
	{
		cin.get();
		cout << " �� ������������� ������ �������� ������ ��������? (Y/N): ";
		cin >> choice;
		if (choice == 'N')
		{
			cout << " ����������� �����" << endl;
			cout << "��� ����������� ������� ����� �������: ";
			_getch();
			system("cls");
		}
		else
		{
			string firstName, lastName, theme;
			int grades[MAX_GRADES], Number_Of_Theme = 1, testGrade;
			do
			{
				cin.get();
				cout << " ������� ��� ��������: ";
				cin >> firstName;
				cin.get();
				cout << " ������� ������� ��������: ";
				cin >> lastName;
				for (int i = 0; i < count; i++)
				{
					if ((students[i].firstName == firstName) and (students[i].lastName == lastName))
					{
						Number = i;
						cout << " ������� ������ " << endl;
						Break = 0;
						break;
					}
				}
				if (Break == 1)
				{
					cout << " ������� �� ������. ���������� �����" << endl;
					cout << " ��� ����������� � ������� ���� ������� \" 0 \": ";
					cin >> Break;
					cin.get();
					if ((Break != 0) and (Break != 1)) { Break == 1; }
				}
			} while (Break == 1);
			

			for (int j = 0; j < MAX_GRADES; j++)
			{
				if (Number_Of_Theme == 1)
				{
					theme = "CYCLES.";
				}
				else
				{
					if (Number_Of_Theme == 2)
					{
						theme = "ARRAYS (ONE- AND TWO-DIMENSIONAL).";
					}
					else
					{
						if (Number_Of_Theme == 3)
						{
							theme = "STRINGS.";
						}
						else
						{
							if (Number_Of_Theme == 4)
							{
								theme = "RECURSION.";
							}
							else
							{
								if (Number_Of_Theme == 5)
								{
									theme = "STRUCTURES.";
								}
								else
								{
									if (Number_Of_Theme == 6)
									{
										theme = "FILES.";
									}
									else
									{
										if (Number_Of_Theme == 7)
										{
											theme = "ADDRESSESS AND SIGNS.";
										}
										else
										{
											if (Number_Of_Theme == 8)
											{
												theme = "DYNAMIC MEMORY.";
											}
										}
									}
								}
							}
						}
					}
				}
				do
				{
					cout << " ������� ������ �������� �� ����� �� ���� " << theme << " : ";
					cin >> grades[j];
					if ((grades[j] > 5) or (grades[j] < 1)) { cout << " ������� �������� ������. ���������� �����" << endl; }
				} while ((grades[j] > 5) or (grades[j] < 1));
				Number_Of_Theme++;
			}
			cout << " ������� ������ �������� �� �������� ����: ";
			cin >> testGrade;

			for (int j = 0; j < MAX_GRADES; j++)
			{
				students[Number].grades[j] = grades[j];
			}
			students[Number].testGrade = testGrade;


			cout << " ������ �������� ������ ��� ������ ��������? (Y/N): ";
			cin >> choice;
			if (choice == 'N')
			{
				cout << " ����������� �����" << endl;
				cout << "��� ����������� ������� ����� �������: ";
				_getch();
				system("cls");
			}
		}
	} while (choice != 'N');

}

void Print_List_Of_Students(Teacher Teachers[MAX_TEACHERS], int Pr, int NumberOfTeachers, Student* students, int& NumberOfStudents)
{
	int choice, sort = -1,range_sort, theme_sort = -1, size = 1;
	int* filter = (int*)malloc(sizeof(int) * size);
	filter[0] = -1;
	do
	{
		cout << " " << Teachers[Pr].firstName << " " << Teachers[Pr].lastName << endl;
		cout << " ==========================" << endl;
		cout << " ������ ��������: " << endl;
		cout << " 1. ����� ������ ��������� � ��������" << endl;
		cout << " 2. ����� �������� ��� ������ ������" << endl;
		cout << " 3. ����� ���������� ��� ������ ������" << endl;
		cout << " 0. ��������� �����" << endl;
		cout << endl;
		cout << " �������� ��������: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			Print_List(sort,filter, size,range_sort, theme_sort, students, NumberOfStudents);
			break;
		case 2:
			system("cls");
			Filters(filter, size);
			break;
		case 3:
			system("cls");
			Sort(sort, range_sort, theme_sort);
			break;
		case 0:
			cout << " ����������� �����" << endl;
			cout << "��� ����������� ������� ����� �������: ";
			_getch();
			system("cls");
			break;
		default:
			system("cls");
			cout << " ������: �������� ����� ����. ���������� ��� ���!" << endl << endl;
			break;
		}
	} while (choice != 0);
	free(filter);
}

void Print_List(int &sort, int filter[], int size, int& range_sort, int& theme_sort, Student* students, int& NumberOfStudents)
{
	int choice, theme;
	do
	{
		cout << " ������ ����� ������: " << endl;
		cout << " 1. �� ���� �����" << endl;
		cout << " 2. �� ���������� ����" << endl;
		cout << " 3. ������ �������� ����" << endl;
		cout << " 4. ������ ������� ����" << endl;
		cout << " 0. ��������� �����" << endl;
		cout << endl;
		cout << " �������� ����������: ";
		cin >> choice;
		if ((choice < 1) or (choice > 4)) { cout << " ������ �������� ���. ���������� �����" << endl; }
		switch (choice)
		{
		case 1:
			system("cls");
			Print_List_All(sort, filter, size, range_sort, theme_sort, students, NumberOfStudents);
			break;
		case 2:
			system("cls");
			Print_List_Theme(sort, filter, size, range_sort, theme_sort, students, NumberOfStudents);
			break;
		case 3:
			system("cls");
			Print_List_Test(sort, filter, size, range_sort, theme_sort, students, NumberOfStudents);
			break;
		case 4:
			system("cls");
			Print_List_Average(sort, filter, size, range_sort, theme_sort, students, NumberOfStudents);
			break;
		case 0:
			cout << " ����������� �����" << endl;
			break;
		default:
			system("cls");
			cout << " ������: �������� ����� ����. ���������� ��� ���!" << endl << endl;
			break;
		}
	} while ((choice < 1) or (choice > 4));
}

void Print_List_All(int& sort, int filter[], int size, int& range_sort, int& theme_sort, Student* students, int& count)
{
	int Number_Of_Theme = 1;
	string theme;
	Student students_2[MAX_STUDENTS];
	int Number_Of_Students = count;
	cout << " ������ ��������� " << endl;
	cout << " ====================================================================================================" << endl;
	if (sort == -1)
	{
		if (filter[0] == -1)
		{
			cout << "���  | �������  |";
			for (int j = 0; j < MAX_GRADES; j++)
			{
				if (Number_Of_Theme == 1)
				{
					theme = "CYCLES.";
				}
				else
				{
					if (Number_Of_Theme == 2)
					{
						theme = "ARRAYS (ONE- AND TWO-DIMENSIONAL).";
					}
					else
					{
						if (Number_Of_Theme == 3)
						{
							theme = "STRINGS.";
						}
						else
						{
							if (Number_Of_Theme == 4)
							{
								theme = "RECURSION.";
							}
							else
							{
								if (Number_Of_Theme == 5)
								{
									theme = "STRUCTURES.";
								}
								else
								{
									if (Number_Of_Theme == 6)
									{
										theme = "FILES.";
									}
									else
									{
										if (Number_Of_Theme == 7)
										{
											theme = "ADDRESSESS AND SIGNS.";
										}
										else
										{
											if (Number_Of_Theme == 8)
											{
												theme = "DYNAMIC MEMORY.";
											}
										}
									}
								}
							}
						}
					}
				}
				cout << theme << "  |";
				Number_Of_Theme++;
			}
			cout << "����  | ��. ����  |" << endl;
			cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

			for (int i = 0; i < count; i++)
			{
				cout << students[i].firstName << "  | " << students[i].lastName << "  | ";
				for (int j = 0; j < MAX_GRADES; j++)
				{
					if (students[i].grades[j] != 0)
					{
						cout << students[i].grades[j] << "  | ";
					}
					else
					{
						cout << "No Result  | ";
					}
				}
				cout << students[i].testGrade << "  | " << (students[i].average = calculateAverage(students[i])) << "  | " << endl;
				cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
			}
		}
		else
		{
			cout << "���  | �������  |";
			for (int j = 0; j < MAX_GRADES; j++)
			{
				if (Number_Of_Theme == 1)
				{
					theme = "CYCLES.";
				}
				else
				{
					if (Number_Of_Theme == 2)
					{
						theme = "ARRAYS (ONE- AND TWO-DIMENSIONAL).";
					}
					else
					{
						if (Number_Of_Theme == 3)
						{
							theme = "STRINGS.";
						}
						else
						{
							if (Number_Of_Theme == 4)
							{
								theme = "RECURSION.";
							}
							else
							{
								if (Number_Of_Theme == 5)
								{
									theme = "STRUCTURES.";
								}
								else
								{
									if (Number_Of_Theme == 6)
									{
										theme = "FILES.";
									}
									else
									{
										if (Number_Of_Theme == 7)
										{
											theme = "ADDRESSESS AND SIGNS.";
										}
										else
										{
											if (Number_Of_Theme == 8)
											{
												theme = "DYNAMIC MEMORY.";
											}
										}
									}
								}
							}
						}
					}
				}
				cout << theme << "  |";
				Number_Of_Theme++;
			}
			cout << "����  | ��. ����  |" << endl;
			cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

			for (int i = 0; i < count; i++)
			{	
				int Fl = 0;
				for (int k = 0; k < MAX_GRADES; k++)
				{
					for (int j = 0; j < size; j++)
					{
						if (students[i].grades[k] == filter[j]) { Fl++; break; }
					}
				}
				if (Fl >= size)
				{
					cout << students[i].firstName << "  | " << students[i].lastName << "  | ";
					for (int j = 0; j < MAX_GRADES; j++)
					{
						if (students[i].grades[j] != 0)
						{
							cout << students[i].grades[j] << "  | ";
						}
						else
						{
							cout << "No Result  | ";
						}
					}
					cout << students[i].testGrade << "  | " << (students[i].average = calculateAverage(students[i])) << "  | " << endl;
					cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
				}
			}
		}

	}
	if (sort == 1)
	{
		if (range_sort == 1)
		{
			if (filter[0] == -1)
			{
				cout << "���  | �������  |";
				for (int j = 0; j < MAX_GRADES; j++)
				{
					if (Number_Of_Theme == 1)
					{
						theme = "CYCLES.";
					}
					else
					{
						if (Number_Of_Theme == 2)
						{
							theme = "ARRAYS (ONE- AND TWO-DIMENSIONAL).";
						}
						else
						{
							if (Number_Of_Theme == 3)
							{
								theme = "STRINGS.";
							}
							else
							{
								if (Number_Of_Theme == 4)
								{
									theme = "RECURSION.";
								}
								else
								{
									if (Number_Of_Theme == 5)
									{
										theme = "STRUCTURES.";
									}
									else
									{
										if (Number_Of_Theme == 6)
										{
											theme = "FILES.";
										}
										else
										{
											if (Number_Of_Theme == 7)
											{
												theme = "ADDRESSESS AND SIGNS.";
											}
											else
											{
												if (Number_Of_Theme == 8)
												{
													theme = "DYNAMIC MEMORY.";
												}
											}
										}
									}
								}
							}
						}
					}
					cout << theme << "  |";
					Number_Of_Theme++;
				}
				cout << "����  | ��. ����  |" << endl;
				cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

				for (int i = 0; i < count; i++)
				{
					students_2[i].firstName = students[i].firstName;
					students_2[i].lastName = students[i].lastName;
					students_2[i].login = students[i].login;
					students_2[i].password = students[i].password;
					students_2[i].testGrade = students[i].testGrade;
					for (int j = 0; j < MAX_GRADES; j++)
					{
						students_2[i].grades[j] = students[i].grades[j];
					}
				}

				for (int i = 0; i < count - 1; i++)
				{
					string firstName, lastName, login, password;
					int testGrade, grades[MAX_GRADES];
					if (students_2[i + 1].grades[theme_sort-1] > students_2[i].grades[theme_sort - 1])
					{
						firstName = students_2[i].firstName;
						lastName = students_2[i].lastName;
						login = students_2[i].login;
						password = students_2[i].password;
						testGrade = students_2[i].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							grades[j] = students_2[i].grades[j];
						}

						students_2[i].firstName = students_2[i + 1].firstName;
						students_2[i].lastName = students_2[i + 1].lastName;
						students_2[i].login = students_2[i + 1].login;
						students_2[i].password = students_2[i + 1].password;
						students_2[i].testGrade = students_2[i + 1].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i].grades[j] = students_2[i+1].grades[j];
						}

						students_2[i + 1].firstName = firstName;
						students_2[i + 1].lastName = lastName;
						students_2[i + 1].login = login;
						students_2[i + 1].password = password;
						students_2[i + 1].testGrade = testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i+1].grades[j] = grades[j];
						}

						i = 0;
					}
				}


				for (int i = 0; i < count; i++)
				{
					cout << students_2[i].firstName << "  | " << students_2[i].lastName << "  | ";
					for (int j = 0; j < MAX_GRADES; j++)
					{
						if (students_2[i].grades[j] != 0)
						{
							cout << students_2[i].grades[j] << "  | ";
						}
						else
						{
							cout << "No Result  | ";
						}
					}
					cout << students_2[i].testGrade << "  | " << (students_2[i].average = calculateAverage(students_2[i])) << "  | " << endl;
					cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
				}
			}
			else
			{
				cout << "���  | �������  |";
				for (int j = 0; j < MAX_GRADES; j++)
				{
					if (Number_Of_Theme == 1)
					{
						theme = "CYCLES.";
					}
					else
					{
						if (Number_Of_Theme == 2)
						{
							theme = "ARRAYS (ONE- AND TWO-DIMENSIONAL).";
						}
						else
						{
							if (Number_Of_Theme == 3)
							{
								theme = "STRINGS.";
							}
							else
							{
								if (Number_Of_Theme == 4)
								{
									theme = "RECURSION.";
								}
								else
								{
									if (Number_Of_Theme == 5)
									{
										theme = "STRUCTURES.";
									}
									else
									{
										if (Number_Of_Theme == 6)
										{
											theme = "FILES.";
										}
										else
										{
											if (Number_Of_Theme == 7)
											{
												theme = "ADDRESSESS AND SIGNS.";
											}
											else
											{
												if (Number_Of_Theme == 8)
												{
													theme = "DYNAMIC MEMORY.";
												}
											}
										}
									}
								}
							}
						}
					}
					cout << theme << "  |";
					Number_Of_Theme++;
				}
				cout << "����  | ��. ����  |" << endl;
				cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

				for (int i = 0; i < count; i++)
				{
					students_2[i].firstName = students[i].firstName;
					students_2[i].lastName = students[i].lastName;
					students_2[i].login = students[i].login;
					students_2[i].password = students[i].password;
					students_2[i].testGrade = students[i].testGrade;
					for (int j = 0; j < MAX_GRADES; j++)
					{
						students_2[i].grades[j] = students[i].grades[j];
					}
				}

				for (int i = 0; i < count - 1; i++)
				{
					string firstName, lastName, login, password;
					int testGrade, grades[MAX_GRADES];
					if (students_2[i + 1].grades[theme_sort - 1] > students_2[i].grades[theme_sort - 1])
					{
						firstName = students_2[i].firstName;
						lastName = students_2[i].lastName;
						login = students_2[i].login;
						password = students_2[i].password;
						testGrade = students_2[i].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							grades[j] = students_2[i].grades[j];
						}

						students_2[i].firstName = students_2[i + 1].firstName;
						students_2[i].lastName = students_2[i + 1].lastName;
						students_2[i].login = students_2[i + 1].login;
						students_2[i].password = students_2[i + 1].password;
						students_2[i].testGrade = students_2[i + 1].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i].grades[j] = students_2[i + 1].grades[j];
						}

						students_2[i + 1].firstName = firstName;
						students_2[i + 1].lastName = lastName;
						students_2[i + 1].login = login;
						students_2[i + 1].password = password;
						students_2[i + 1].testGrade = testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i + 1].grades[j] = grades[j];
						}

						i = 0;
					}
				}

				for (int i = 0; i < count; i++)
				{
					int Fl = 0;
					for (int k = 0; k < MAX_GRADES; k++)
					{
						for (int j = 0; j < size; j++)
						{
							if (students_2[i].grades[theme_sort - 1] == filter[j]) { Fl++; break; }
						}
						if (Fl == 1) { break; }
					}
					if (Fl == 1)
					{
						cout << students_2[i].firstName << "  | " << students_2[i].lastName << "  | ";
						for (int j = 0; j < MAX_GRADES; j++)
						{
							if (students_2[i].grades[j] != 0)
							{
								cout << students_2[i].grades[j] << "  | ";
							}
							else
							{
								cout << "No Result  | ";
							}
						}
						cout << students_2[i].testGrade << "  | " << (students_2[i].average = calculateAverage(students_2[i])) << "  | " << endl;
						cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
					}
				}
			}
		}
		if (range_sort == 2)
		{
			if (filter[0] == -1)
			{
				cout << "���  | �������  |";
				for (int j = 0; j < MAX_GRADES; j++)
				{
					if (Number_Of_Theme == 1)
					{
						theme = "CYCLES.";
					}
					else
					{
						if (Number_Of_Theme == 2)
						{
							theme = "ARRAYS (ONE- AND TWO-DIMENSIONAL).";
						}
						else
						{
							if (Number_Of_Theme == 3)
							{
								theme = "STRINGS.";
							}
							else
							{
								if (Number_Of_Theme == 4)
								{
									theme = "RECURSION.";
								}
								else
								{
									if (Number_Of_Theme == 5)
									{
										theme = "STRUCTURES.";
									}
									else
									{
										if (Number_Of_Theme == 6)
										{
											theme = "FILES.";
										}
										else
										{
											if (Number_Of_Theme == 7)
											{
												theme = "ADDRESSESS AND SIGNS.";
											}
											else
											{
												if (Number_Of_Theme == 8)
												{
													theme = "DYNAMIC MEMORY.";
												}
											}
										}
									}
								}
							}
						}
					}
					cout << theme << "  |";
					Number_Of_Theme++;
				}
				cout << "����  | ��. ����  |" << endl;
				cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

				for (int i = 0; i < count; i++)
				{
					students_2[i].firstName = students[i].firstName;
					students_2[i].lastName = students[i].lastName;
					students_2[i].login = students[i].login;
					students_2[i].password = students[i].password;
					students_2[i].testGrade = students[i].testGrade;
					for (int j = 0; j < MAX_GRADES; j++)
					{
						students_2[i].grades[j] = students[i].grades[j];
					}
				}

				for (int i = 0; i < count - 1; i++)
				{
					string firstName, lastName, login, password;
					int testGrade, grades[MAX_GRADES];
					if (students_2[i + 1].grades[theme_sort - 1] < students_2[i].grades[theme_sort - 1])
					{
						firstName = students_2[i].firstName;
						lastName = students_2[i].lastName;
						login = students_2[i].login;
						password = students_2[i].password;
						testGrade = students_2[i].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							grades[j] = students_2[i].grades[j];
						}

						students_2[i].firstName = students_2[i + 1].firstName;
						students_2[i].lastName = students_2[i + 1].lastName;
						students_2[i].login = students_2[i + 1].login;
						students_2[i].password = students_2[i + 1].password;
						students_2[i].testGrade = students_2[i + 1].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i].grades[j] = students_2[i + 1].grades[j];
						}

						students_2[i + 1].firstName = firstName;
						students_2[i + 1].lastName = lastName;
						students_2[i + 1].login = login;
						students_2[i + 1].password = password;
						students_2[i + 1].testGrade = testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i + 1].grades[j] = grades[j];
						}

						i = 0;
					}
				}


				for (int i = 0; i < count; i++)
				{
					cout << students_2[i].firstName << "  | " << students_2[i].lastName << "  | ";
					for (int j = 0; j < MAX_GRADES; j++)
					{
						if (students_2[i].grades[j] != 0)
						{
							cout << students_2[i].grades[j] << "  | ";
						}
						else
						{
							cout << "No Result  | ";
						}
					}
					cout << students_2[i].testGrade << "  | " << (students_2[i].average = calculateAverage(students_2[i])) << "  | " << endl;
					cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
				}
			}
			else
			{
				cout << "���  | �������  |";
				for (int j = 0; j < MAX_GRADES; j++)
				{
					if (Number_Of_Theme == 1)
					{
						theme = "CYCLES.";
					}
					else
					{
						if (Number_Of_Theme == 2)
						{
							theme = "ARRAYS (ONE- AND TWO-DIMENSIONAL).";
						}
						else
						{
							if (Number_Of_Theme == 3)
							{
								theme = "STRINGS.";
							}
							else
							{
								if (Number_Of_Theme == 4)
								{
									theme = "RECURSION.";
								}
								else
								{
									if (Number_Of_Theme == 5)
									{
										theme = "STRUCTURES.";
									}
									else
									{
										if (Number_Of_Theme == 6)
										{
											theme = "FILES.";
										}
										else
										{
											if (Number_Of_Theme == 7)
											{
												theme = "ADDRESSESS AND SIGNS.";
											}
											else
											{
												if (Number_Of_Theme == 8)
												{
													theme = "DYNAMIC MEMORY.";
												}
											}
										}
									}
								}
							}
						}
					}
					cout << theme << "  |";
					Number_Of_Theme++;
				}
				cout << "����  | ��. ����  |" << endl;
				cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

				for (int i = 0; i < count; i++)
				{
					students_2[i].firstName = students[i].firstName;
					students_2[i].lastName = students[i].lastName;
					students_2[i].login = students[i].login;
					students_2[i].password = students[i].password;
					students_2[i].testGrade = students[i].testGrade;
					for (int j = 0; j < MAX_GRADES; j++)
					{
						students_2[i].grades[j] = students[i].grades[j];
					}
				}

				for (int i = 0; i < count - 1; i++)
				{
					string firstName, lastName, login, password;
					int testGrade, grades[MAX_GRADES];
					if (students_2[i + 1].grades[theme_sort - 1] < students_2[i].grades[theme_sort - 1])
					{
						firstName = students_2[i].firstName;
						lastName = students_2[i].lastName;
						login = students_2[i].login;
						password = students_2[i].password;
						testGrade = students_2[i].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							grades[j] = students_2[i].grades[j];
						}

						students_2[i].firstName = students_2[i + 1].firstName;
						students_2[i].lastName = students_2[i + 1].lastName;
						students_2[i].login = students_2[i + 1].login;
						students_2[i].password = students_2[i + 1].password;
						students_2[i].testGrade = students_2[i + 1].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i].grades[j] = students_2[i + 1].grades[j];
						}

						students_2[i + 1].firstName = firstName;
						students_2[i + 1].lastName = lastName;
						students_2[i + 1].login = login;
						students_2[i + 1].password = password;
						students_2[i + 1].testGrade = testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i + 1].grades[j] = grades[j];
						}

						i = 0;
					}
				}

				for (int i = 0; i < count; i++)
				{
					int Fl = 0;
					for (int k = 0; k < MAX_GRADES; k++)
					{
						for (int j = 0; j < size; j++)
						{
							if (students_2[i].grades[theme_sort - 1] == filter[j]) { Fl++; break; }
						}
						if (Fl == 1) { break; }
					}
					if (Fl == 1)
					{
						cout << students_2[i].firstName << "  | " << students_2[i].lastName << "  | ";
						for (int j = 0; j < MAX_GRADES; j++)
						{
							if (students_2[i].grades[j] != 0)
							{
								cout << students_2[i].grades[j] << "  | ";
							}
							else
							{
								cout << "No Result  | ";
							}
						}
						cout << students_2[i].testGrade << "  | " << (students_2[i].average = calculateAverage(students_2[i])) << "  | " << endl;
						cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
					}
				}
			}
		}
	}
	if (sort == 2)
	{
		if (range_sort == 1)
		{
			if (filter[0] == -1)
			{
				cout << "���  | �������  |";
				for (int j = 0; j < MAX_GRADES; j++)
				{
					if (Number_Of_Theme == 1)
					{
						theme = "CYCLES.";
					}
					else
					{
						if (Number_Of_Theme == 2)
						{
							theme = "ARRAYS (ONE- AND TWO-DIMENSIONAL).";
						}
						else
						{
							if (Number_Of_Theme == 3)
							{
								theme = "STRINGS.";
							}
							else
							{
								if (Number_Of_Theme == 4)
								{
									theme = "RECURSION.";
								}
								else
								{
									if (Number_Of_Theme == 5)
									{
										theme = "STRUCTURES.";
									}
									else
									{
										if (Number_Of_Theme == 6)
										{
											theme = "FILES.";
										}
										else
										{
											if (Number_Of_Theme == 7)
											{
												theme = "ADDRESSESS AND SIGNS.";
											}
											else
											{
												if (Number_Of_Theme == 8)
												{
													theme = "DYNAMIC MEMORY.";
												}
											}
										}
									}
								}
							}
						}
					}
					cout << theme << "  |";
					Number_Of_Theme++;
				}
				cout << "����  | ��. ����  |" << endl;
				cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

				for (int i = 0; i < count; i++)
				{
					students_2[i].firstName = students[i].firstName;
					students_2[i].lastName = students[i].lastName;
					students_2[i].login = students[i].login;
					students_2[i].password = students[i].password;
					students_2[i].testGrade = students[i].testGrade;
					for (int j = 0; j < MAX_GRADES; j++)
					{
						students_2[i].grades[j] = students[i].grades[j];
					}
				}

				for (int i = 0; i < count-1; i++)
				{
					string firstName, lastName, login, password;
					int testGrade, grades[MAX_GRADES];
					if (students_2[i + 1].testGrade > students_2[i].testGrade)
					{
						firstName = students_2[i].firstName;
						lastName = students_2[i].lastName;
						login = students_2[i].login;
						password = students_2[i].password;
						testGrade = students_2[i].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							grades[j] = students_2[i].grades[j];
						}

						students_2[i].firstName = students_2[i + 1].firstName;
						students_2[i].lastName = students_2[i + 1].lastName;
						students_2[i].login = students_2[i + 1].login;
						students_2[i].password = students_2[i + 1].password;
						students_2[i].testGrade = students_2[i + 1].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i].grades[j] = students_2[i + 1].grades[j];
						}

						students_2[i + 1].firstName = firstName;
						students_2[i + 1].lastName = lastName;
						students_2[i + 1].login = login;
						students_2[i + 1].password = password;
						students_2[i + 1].testGrade = testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i + 1].grades[j] = grades[j];
						}

						i = 0;
					}
				}


				for (int i = 0; i < count; i++)
				{
					cout << students_2[i].firstName << "  | " << students_2[i].lastName << "  | ";
					for (int j = 0; j < MAX_GRADES; j++)
					{
						if (students_2[i].grades[j] != 0)
						{
							cout << students_2[i].grades[j] << "  | ";
						}
						else
						{
							cout << "No Result  | ";
						}
					}
					cout << students_2[i].testGrade << "  | " << (students_2[i].average = calculateAverage(students_2[i])) << "  | " << endl;
					cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
				}
			}
			else
			{
				cout << "���  | �������  |";
				for (int j = 0; j < MAX_GRADES; j++)
				{
					if (Number_Of_Theme == 1)
					{
						theme = "CYCLES.";
					}
					else
					{
						if (Number_Of_Theme == 2)
						{
							theme = "ARRAYS (ONE- AND TWO-DIMENSIONAL).";
						}
						else
						{
							if (Number_Of_Theme == 3)
							{
								theme = "STRINGS.";
							}
							else
							{
								if (Number_Of_Theme == 4)
								{
									theme = "RECURSION.";
								}
								else
								{
									if (Number_Of_Theme == 5)
									{
										theme = "STRUCTURES.";
									}
									else
									{
										if (Number_Of_Theme == 6)
										{
											theme = "FILES.";
										}
										else
										{
											if (Number_Of_Theme == 7)
											{
												theme = "ADDRESSESS AND SIGNS.";
											}
											else
											{
												if (Number_Of_Theme == 8)
												{
													theme = "DYNAMIC MEMORY.";
												}
											}
										}
									}
								}
							}
						}
					}
					cout << theme << "  |";
					Number_Of_Theme++;
				}
				cout << "����  | ��. ����  |" << endl;
				cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

				for (int i = 0; i < count; i++)
				{
					students_2[i].firstName = students[i].firstName;
					students_2[i].lastName = students[i].lastName;
					students_2[i].login = students[i].login;
					students_2[i].password = students[i].password;
					students_2[i].testGrade = students[i].testGrade;
					for (int j = 0; j < MAX_GRADES; j++)
					{
						students_2[i].grades[j] = students[i].grades[j];
					}
				}

				for (int i = 0; i < count - 1; i++)
				{
					string firstName, lastName, login, password;
					int testGrade, grades[MAX_GRADES];
					if (students_2[i + 1].testGrade > students_2[i].testGrade)
					{
						firstName = students_2[i].firstName;
						lastName = students_2[i].lastName;
						login = students_2[i].login;
						password = students_2[i].password;
						testGrade = students_2[i].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							grades[j] = students_2[i].grades[j];
						}

						students_2[i].firstName = students_2[i + 1].firstName;
						students_2[i].lastName = students_2[i + 1].lastName;
						students_2[i].login = students_2[i + 1].login;
						students_2[i].password = students_2[i + 1].password;
						students_2[i].testGrade = students_2[i + 1].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i].grades[j] = students_2[i + 1].grades[j];
						}

						students_2[i + 1].firstName = firstName;
						students_2[i + 1].lastName = lastName;
						students_2[i + 1].login = login;
						students_2[i + 1].password = password;
						students_2[i + 1].testGrade = testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i + 1].grades[j] = grades[j];
						}

						i = 0;
					}
				}

				for (int i = 0; i < count; i++)
				{
					int Fl = 0;
					for (int k = 0; k < MAX_GRADES; k++)
					{
						for (int j = 0; j < size; j++)
						{
							if (students_2[i].testGrade == filter[j]) { Fl++; break; }
						}
						if (Fl == 1) { break; }
					}
					if (Fl == 1)
					{
						cout << students_2[i].firstName << "  | " << students_2[i].lastName << "  | ";
						for (int j = 0; j < MAX_GRADES; j++)
						{
							if (students_2[i].grades[j] != 0)
							{
								cout << students_2[i].grades[j] << "  | ";
							}
							else
							{
								cout << "No Result  | ";
							}
						}
						cout << students_2[i].testGrade << "  | " << (students_2[i].average = calculateAverage(students_2[i])) << "  | " << endl;
						cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
					}
				}
			}
		}
		if (range_sort == 2)
		{
			if (filter[0] == -1)
			{
				cout << "���  | �������  |";
				for (int j = 0; j < MAX_GRADES; j++)
				{
					if (Number_Of_Theme == 1)
					{
						theme = "CYCLES.";
					}
					else
					{
						if (Number_Of_Theme == 2)
						{
							theme = "ARRAYS (ONE- AND TWO-DIMENSIONAL).";
						}
						else
						{
							if (Number_Of_Theme == 3)
							{
								theme = "STRINGS.";
							}
							else
							{
								if (Number_Of_Theme == 4)
								{
									theme = "RECURSION.";
								}
								else
								{
									if (Number_Of_Theme == 5)
									{
										theme = "STRUCTURES.";
									}
									else
									{
										if (Number_Of_Theme == 6)
										{
											theme = "FILES.";
										}
										else
										{
											if (Number_Of_Theme == 7)
											{
												theme = "ADDRESSESS AND SIGNS.";
											}
											else
											{
												if (Number_Of_Theme == 8)
												{
													theme = "DYNAMIC MEMORY.";
												}
											}
										}
									}
								}
							}
						}
					}
					cout << theme << "  |";
					Number_Of_Theme++;
				}
				cout << "����  | ��. ����  |" << endl;
				cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

				for (int i = 0; i < count; i++)
				{
					students_2[i].firstName = students[i].firstName;
					students_2[i].lastName = students[i].lastName;
					students_2[i].login = students[i].login;
					students_2[i].password = students[i].password;
					students_2[i].testGrade = students[i].testGrade;
					for (int j = 0; j < MAX_GRADES; j++)
					{
						students_2[i].grades[j] = students[i].grades[j];
					}
				}

				for (int i = 0; i < count - 1; i++)
				{
					string firstName, lastName, login, password;
					int testGrade, grades[MAX_GRADES];
					if (students_2[i + 1].testGrade < students_2[i].testGrade)
					{
						firstName = students_2[i].firstName;
						lastName = students_2[i].lastName;
						login = students_2[i].login;
						password = students_2[i].password;
						testGrade = students_2[i].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							grades[j] = students_2[i].grades[j];
						}

						students_2[i].firstName = students_2[i + 1].firstName;
						students_2[i].lastName = students_2[i + 1].lastName;
						students_2[i].login = students_2[i + 1].login;
						students_2[i].password = students_2[i + 1].password;
						students_2[i].testGrade = students_2[i + 1].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i].grades[j] = students_2[i + 1].grades[j];
						}

						students_2[i + 1].firstName = firstName;
						students_2[i + 1].lastName = lastName;
						students_2[i + 1].login = login;
						students_2[i + 1].password = password;
						students_2[i + 1].testGrade = testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i + 1].grades[j] = grades[j];
						}

						i = 0;
					}
				}


				for (int i = 0; i < count; i++)
				{
					cout << students_2[i].firstName << "  | " << students_2[i].lastName << "  | ";
					for (int j = 0; j < MAX_GRADES; j++)
					{
						if (students_2[i].grades[j] != 0)
						{
							cout << students_2[i].grades[j] << "  | ";
						}
						else
						{
							cout << "No Result  | ";
						}
					}
					cout << students_2[i].testGrade << "  | " << (students_2[i].average = calculateAverage(students_2[i])) << "  | " << endl;
					cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
				}
			}
			else
			{
				cout << "���  | �������  |";
				for (int j = 0; j < MAX_GRADES; j++)
				{
					if (Number_Of_Theme == 1)
					{
						theme = "CYCLES.";
					}
					else
					{
						if (Number_Of_Theme == 2)
						{
							theme = "ARRAYS (ONE- AND TWO-DIMENSIONAL).";
						}
						else
						{
							if (Number_Of_Theme == 3)
							{
								theme = "STRINGS.";
							}
							else
							{
								if (Number_Of_Theme == 4)
								{
									theme = "RECURSION.";
								}
								else
								{
									if (Number_Of_Theme == 5)
									{
										theme = "STRUCTURES.";
									}
									else
									{
										if (Number_Of_Theme == 6)
										{
											theme = "FILES.";
										}
										else
										{
											if (Number_Of_Theme == 7)
											{
												theme = "ADDRESSESS AND SIGNS.";
											}
											else
											{
												if (Number_Of_Theme == 8)
												{
													theme = "DYNAMIC MEMORY.";
												}
											}
										}
									}
								}
							}
						}
					}
					cout << theme << "  |";
					Number_Of_Theme++;
				}
				cout << "����  | ��. ����  |" << endl;
				cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

				for (int i = 0; i < count; i++)
				{
					students_2[i].firstName = students[i].firstName;
					students_2[i].lastName = students[i].lastName;
					students_2[i].login = students[i].login;
					students_2[i].password = students[i].password;
					students_2[i].testGrade = students[i].testGrade;
					for (int j = 0; j < MAX_GRADES; j++)
					{
						students_2[i].grades[j] = students[i].grades[j];
					}
				}

				for (int i = 0; i < count - 1; i++)
				{
					string firstName, lastName, login, password;
					int testGrade, grades[MAX_GRADES];
					if (students_2[i + 1].testGrade < students_2[i].testGrade)
					{
						firstName = students_2[i].firstName;
						lastName = students_2[i].lastName;
						login = students_2[i].login;
						password = students_2[i].password;
						testGrade = students_2[i].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							grades[j] = students_2[i].grades[j];
						}

						students_2[i].firstName = students_2[i + 1].firstName;
						students_2[i].lastName = students_2[i + 1].lastName;
						students_2[i].login = students_2[i + 1].login;
						students_2[i].password = students_2[i + 1].password;
						students_2[i].testGrade = students_2[i + 1].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i].grades[j] = students_2[i + 1].grades[j];
						}

						students_2[i + 1].firstName = firstName;
						students_2[i + 1].lastName = lastName;
						students_2[i + 1].login = login;
						students_2[i + 1].password = password;
						students_2[i + 1].testGrade = testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i + 1].grades[j] = grades[j];
						}

						i = 0;
					}
				}

				for (int i = 0; i < count; i++)
				{
					int Fl = 0;
					for (int k = 0; k < MAX_GRADES; k++)
					{
						for (int j = 0; j < size; j++)
						{
							if (students_2[i].testGrade == filter[j]) { Fl++; break; }
						}
						if (Fl == 1) { break; }
					}
					if (Fl == 1)
					{
						cout << students_2[i].firstName << "  | " << students_2[i].lastName << "  | ";
						for (int j = 0; j < MAX_GRADES; j++)
						{
							if (students_2[i].grades[j] != 0)
							{
								cout << students_2[i].grades[j] << "  | ";
							}
							else
							{
								cout << "No Result  | ";
							}
						}
						cout << students_2[i].testGrade << "  | " << (students_2[i].average = calculateAverage(students_2[i])) << "  | " << endl;
						cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
					}
				}
			}
		}
	}
	if (sort == 3)
	{
		if (range_sort == 1)
		{
			if (filter[0] == -1)
			{
				cout << "���  | �������  |";
				for (int j = 0; j < MAX_GRADES; j++)
				{
					if (Number_Of_Theme == 1)
					{
						theme = "CYCLES.";
					}
					else
					{
						if (Number_Of_Theme == 2)
						{
							theme = "ARRAYS (ONE- AND TWO-DIMENSIONAL).";
						}
						else
						{
							if (Number_Of_Theme == 3)
							{
								theme = "STRINGS.";
							}
							else
							{
								if (Number_Of_Theme == 4)
								{
									theme = "RECURSION.";
								}
								else
								{
									if (Number_Of_Theme == 5)
									{
										theme = "STRUCTURES.";
									}
									else
									{
										if (Number_Of_Theme == 6)
										{
											theme = "FILES.";
										}
										else
										{
											if (Number_Of_Theme == 7)
											{
												theme = "ADDRESSESS AND SIGNS.";
											}
											else
											{
												if (Number_Of_Theme == 8)
												{
													theme = "DYNAMIC MEMORY.";
												}
											}
										}
									}
								}
							}
						}
					}
					cout << theme << "  |";
					Number_Of_Theme++;
				}
				cout << "����  | ��. ����  |" << endl;
				cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

				for (int i = 0; i < count; i++)
				{
					students_2[i].firstName = students[i].firstName;
					students_2[i].lastName = students[i].lastName;
					students_2[i].login = students[i].login;
					students_2[i].password = students[i].password;
					students_2[i].testGrade = students[i].testGrade;
					for (int j = 0; j < MAX_GRADES; j++)
					{
						students_2[i].grades[j] = students[i].grades[j];
					}
				}

				for (int i = 0; i < count - 1; i++)
				{
					string firstName, lastName, login, password;
					int testGrade, grades[MAX_GRADES];
					students_2[i].average = calculateAverage(students_2[i]);
					students_2[i+1].average = calculateAverage(students_2[i+1]);
					if (students_2[i + 1].average > students_2[i].average)
					{
						firstName = students_2[i].firstName;
						lastName = students_2[i].lastName;
						login = students_2[i].login;
						password = students_2[i].password;
						testGrade = students_2[i].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							grades[j] = students_2[i].grades[j];
						}

						students_2[i].firstName = students_2[i + 1].firstName;
						students_2[i].lastName = students_2[i + 1].lastName;
						students_2[i].login = students_2[i + 1].login;
						students_2[i].password = students_2[i + 1].password;
						students_2[i].testGrade = students_2[i + 1].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i].grades[j] = students_2[i + 1].grades[j];
						}

						students_2[i + 1].firstName = firstName;
						students_2[i + 1].lastName = lastName;
						students_2[i + 1].login = login;
						students_2[i + 1].password = password;
						students_2[i + 1].testGrade = testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i + 1].grades[j] = grades[j];
						}

						i = 0;
					}
				}


				for (int i = 0; i < count; i++)
				{
					cout << students_2[i].firstName << "  | " << students_2[i].lastName << "  | ";
					for (int j = 0; j < MAX_GRADES; j++)
					{
						if (students_2[i].grades[j] != 0)
						{
							cout << students_2[i].grades[j] << "  | ";
						}
						else
						{
							cout << "No Result  | ";
						}
					}
					cout << students_2[i].testGrade << "  | " << (students_2[i].average = calculateAverage(students_2[i])) << "  | " << endl;
					cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
				}
			}
			else
			{
				cout << "���  | �������  |";
				for (int j = 0; j < MAX_GRADES; j++)
				{
					if (Number_Of_Theme == 1)
					{
						theme = "CYCLES.";
					}
					else
					{
						if (Number_Of_Theme == 2)
						{
							theme = "ARRAYS (ONE- AND TWO-DIMENSIONAL).";
						}
						else
						{
							if (Number_Of_Theme == 3)
							{
								theme = "STRINGS.";
							}
							else
							{
								if (Number_Of_Theme == 4)
								{
									theme = "RECURSION.";
								}
								else
								{
									if (Number_Of_Theme == 5)
									{
										theme = "STRUCTURES.";
									}
									else
									{
										if (Number_Of_Theme == 6)
										{
											theme = "FILES.";
										}
										else
										{
											if (Number_Of_Theme == 7)
											{
												theme = "ADDRESSESS AND SIGNS.";
											}
											else
											{
												if (Number_Of_Theme == 8)
												{
													theme = "DYNAMIC MEMORY.";
												}
											}
										}
									}
								}
							}
						}
					}
					cout << theme << "  |";
					Number_Of_Theme++;
				}
				cout << "����  | ��. ����  |" << endl;
				cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

				for (int i = 0; i < count; i++)
				{
					students_2[i].firstName = students[i].firstName;
					students_2[i].lastName = students[i].lastName;
					students_2[i].login = students[i].login;
					students_2[i].password = students[i].password;
					students_2[i].testGrade = students[i].testGrade;
					for (int j = 0; j < MAX_GRADES; j++)
					{
						students_2[i].grades[j] = students[i].grades[j];
					}
				}

				for (int i = 0; i < count - 1; i++)
				{
					string firstName, lastName, login, password;
					int testGrade, grades[MAX_GRADES];
					students_2[i].average = calculateAverage(students_2[i]);
					students_2[i + 1].average = calculateAverage(students_2[i + 1]);
					if (students_2[i + 1].average > students_2[i].average)
					{
						firstName = students_2[i].firstName;
						lastName = students_2[i].lastName;
						login = students_2[i].login;
						password = students_2[i].password;
						testGrade = students_2[i].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							grades[j] = students_2[i].grades[j];
						}

						students_2[i].firstName = students_2[i + 1].firstName;
						students_2[i].lastName = students_2[i + 1].lastName;
						students_2[i].login = students_2[i + 1].login;
						students_2[i].password = students_2[i + 1].password;
						students_2[i].testGrade = students_2[i + 1].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i].grades[j] = students_2[i + 1].grades[j];
						}

						students_2[i + 1].firstName = firstName;
						students_2[i + 1].lastName = lastName;
						students_2[i + 1].login = login;
						students_2[i + 1].password = password;
						students_2[i + 1].testGrade = testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i + 1].grades[j] = grades[j];
						}

						i = 0;
					}
				}

				for (int i = 0; i < count; i++)
				{
					int Fl = 0;
					for (int k = 0; k < MAX_GRADES; k++)
					{
						for (int j = 0; j < size; j++)
						{
							if (int(students_2[i].average) == filter[j]) { Fl++; break; }
						}
						if (Fl == 1) { break; }
					}
					if (Fl == 1)
					{
						cout << students_2[i].firstName << "  | " << students_2[i].lastName << "  | ";
						for (int j = 0; j < MAX_GRADES; j++)
						{
							if (students_2[i].grades[j] != 0)
							{
								cout << students_2[i].grades[j] << "  | ";
							}
							else
							{
								cout << "No Result  | ";
							}
						}
						cout << students_2[i].testGrade << "  | " << (students_2[i].average = calculateAverage(students_2[i])) << "  | " << endl;
						cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
					}
				}
			}
		}
		if (range_sort == 2)
		{
			if (filter[0] == -1)
			{
				cout << "���  | �������  |";
				for (int j = 0; j < MAX_GRADES; j++)
				{
					if (Number_Of_Theme == 1)
					{
						theme = "CYCLES.";
					}
					else
					{
						if (Number_Of_Theme == 2)
						{
							theme = "ARRAYS (ONE- AND TWO-DIMENSIONAL).";
						}
						else
						{
							if (Number_Of_Theme == 3)
							{
								theme = "STRINGS.";
							}
							else
							{
								if (Number_Of_Theme == 4)
								{
									theme = "RECURSION.";
								}
								else
								{
									if (Number_Of_Theme == 5)
									{
										theme = "STRUCTURES.";
									}
									else
									{
										if (Number_Of_Theme == 6)
										{
											theme = "FILES.";
										}
										else
										{
											if (Number_Of_Theme == 7)
											{
												theme = "ADDRESSESS AND SIGNS.";
											}
											else
											{
												if (Number_Of_Theme == 8)
												{
													theme = "DYNAMIC MEMORY.";
												}
											}
										}
									}
								}
							}
						}
					}
					cout << theme << "  |";
					Number_Of_Theme++;
				}
				cout << "����  | ��. ����  |" << endl;
				cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

				for (int i = 0; i < count; i++)
				{
					students_2[i].firstName = students[i].firstName;
					students_2[i].lastName = students[i].lastName;
					students_2[i].login = students[i].login;
					students_2[i].password = students[i].password;
					students_2[i].testGrade = students[i].testGrade;
					for (int j = 0; j < MAX_GRADES; j++)
					{
						students_2[i].grades[j] = students[i].grades[j];
					}
				}

				for (int i = 0; i < count - 1; i++)
				{
					string firstName, lastName, login, password;
					int testGrade, grades[MAX_GRADES];
					students_2[i].average = calculateAverage(students_2[i]);
					students_2[i + 1].average = calculateAverage(students_2[i + 1]);
					if (students_2[i + 1].average < students_2[i].average)
					{
						firstName = students_2[i].firstName;
						lastName = students_2[i].lastName;
						login = students_2[i].login;
						password = students_2[i].password;
						testGrade = students_2[i].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							grades[j] = students_2[i].grades[j];
						}

						students_2[i].firstName = students_2[i + 1].firstName;
						students_2[i].lastName = students_2[i + 1].lastName;
						students_2[i].login = students_2[i + 1].login;
						students_2[i].password = students_2[i + 1].password;
						students_2[i].testGrade = students_2[i + 1].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i].grades[j] = students_2[i + 1].grades[j];
						}

						students_2[i + 1].firstName = firstName;
						students_2[i + 1].lastName = lastName;
						students_2[i + 1].login = login;
						students_2[i + 1].password = password;
						students_2[i + 1].testGrade = testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i + 1].grades[j] = grades[j];
						}

						i = 0;
					}
				}


				for (int i = 0; i < count; i++)
				{
					cout << students_2[i].firstName << "  | " << students_2[i].lastName << "  | ";
					for (int j = 0; j < MAX_GRADES; j++)
					{
						if (students_2[i].grades[j] != 0)
						{
							cout << students_2[i].grades[j] << "  | ";
						}
						else
						{
							cout << "No Result  | ";
						}
					}
					cout << students_2[i].testGrade << "  | " << (students_2[i].average = calculateAverage(students_2[i])) << "  | " << endl;
					cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
				}
			}
			else
			{
				cout << "���  | �������  |";
				for (int j = 0; j < MAX_GRADES; j++)
				{
					if (Number_Of_Theme == 1)
					{
						theme = "CYCLES.";
					}
					else
					{
						if (Number_Of_Theme == 2)
						{
							theme = "ARRAYS (ONE- AND TWO-DIMENSIONAL).";
						}
						else
						{
							if (Number_Of_Theme == 3)
							{
								theme = "STRINGS.";
							}
							else
							{
								if (Number_Of_Theme == 4)
								{
									theme = "RECURSION.";
								}
								else
								{
									if (Number_Of_Theme == 5)
									{
										theme = "STRUCTURES.";
									}
									else
									{
										if (Number_Of_Theme == 6)
										{
											theme = "FILES.";
										}
										else
										{
											if (Number_Of_Theme == 7)
											{
												theme = "ADDRESSESS AND SIGNS.";
											}
											else
											{
												if (Number_Of_Theme == 8)
												{
													theme = "DYNAMIC MEMORY.";
												}
											}
										}
									}
								}
							}
						}
					}
					cout << theme << "  |";
					Number_Of_Theme++;
				}
				cout << "����  | ��. ����  |" << endl;
				cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

				for (int i = 0; i < count; i++)
				{
					students_2[i].firstName = students[i].firstName;
					students_2[i].lastName = students[i].lastName;
					students_2[i].login = students[i].login;
					students_2[i].password = students[i].password;
					students_2[i].testGrade = students[i].testGrade;
					for (int j = 0; j < MAX_GRADES; j++)
					{
						students_2[i].grades[j] = students[i].grades[j];
					}
				}

				for (int i = 0; i < count - 1; i++)
				{
					string firstName, lastName, login, password;
					int testGrade, grades[MAX_GRADES];
					students_2[i].average = calculateAverage(students_2[i]);
					students_2[i + 1].average = calculateAverage(students_2[i + 1]);
					if (students_2[i + 1].average < students_2[i].average)
					{
						firstName = students_2[i].firstName;
						lastName = students_2[i].lastName;
						login = students_2[i].login;
						password = students_2[i].password;
						testGrade = students_2[i].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							grades[j] = students_2[i].grades[j];
						}

						students_2[i].firstName = students_2[i + 1].firstName;
						students_2[i].lastName = students_2[i + 1].lastName;
						students_2[i].login = students_2[i + 1].login;
						students_2[i].password = students_2[i + 1].password;
						students_2[i].testGrade = students_2[i + 1].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i].grades[j] = students_2[i + 1].grades[j];
						}

						students_2[i + 1].firstName = firstName;
						students_2[i + 1].lastName = lastName;
						students_2[i + 1].login = login;
						students_2[i + 1].password = password;
						students_2[i + 1].testGrade = testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i + 1].grades[j] = grades[j];
						}

						i = 0;
					}
				}

				for (int i = 0; i < count; i++)
				{
					int Fl = 0;
					for (int k = 0; k < MAX_GRADES; k++)
					{
						for (int j = 0; j < size; j++)
						{
							if (int(students_2[i].average) == filter[j]) { Fl++; break; }
						}
						if (Fl == 1) { break; }
					}
					if (Fl == 1)
					{
						cout << students_2[i].firstName << "  | " << students_2[i].lastName << "  | ";
						for (int j = 0; j < MAX_GRADES; j++)
						{
							if (students_2[i].grades[j] != 0)
							{
								cout << students_2[i].grades[j] << "  | ";
							}
							else
							{
								cout << "No Result  | ";
							}
						}
						cout << students_2[i].testGrade << "  | " << (students_2[i].average = calculateAverage(students_2[i])) << "  | " << endl;
						cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
					}
				}
			}
		}
	}
	cout << "��� ����������� ������� ����� �������: ";
	_getch();
	system("cls");
}

void Print_List_Theme(int& sort, int filter[], int size, int& range_sort, int& theme_sort, Student* students, int& count)
{
	int Number_Of_Theme;
	string theme;
	Student students_2[MAX_STUDENTS];
	int Number_Of_Students = count;
	do
	{
		cout << " ������ ��� ��� ������: " << endl;
		cout << " 1. CYCLES" << endl;
		cout << " 2. ARRAYS (ONE- AND TWO-DIMENSIONAL)" << endl;
		cout << " 3. STRINGS" << endl;
		cout << " 4. RECURSION" << endl;
		cout << " 5. STRUCTURES" << endl;
		cout << " 6. FILES" << endl;
		cout << " 7. ADDRESSES AND SIGNS" << endl;
		cout << " 8. DYNAMIC MEMORY" << endl;
		cout << endl;
		cout << " �������� ����: ";
		cin >> Number_Of_Theme;
		if ((Number_Of_Theme < 1) or (Number_Of_Theme > 8)) { cout << " ������� �������� ���� ��� ����������. ���������� �����" << endl; }
	} while ((Number_Of_Theme < 1) or (Number_Of_Theme > 8));
	system("cls");

	cout << " ������ ��������� " << endl;
	cout << " ====================================================================================================" << endl;

	if (sort == -1)
	{
		if (filter[0] == -1)
		{
			cout << "���  | �������  |" << theme << "  |" << endl;
			cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

			for (int i = 0; i < count; i++)
			{
				cout << students[i].firstName << "  | " << students[i].lastName << "  | ";
				if (students[i].grades[Number_Of_Theme-1] != 0)
				{
					cout << students[i].grades[Number_Of_Theme - 1] << "  | " << endl;
				}
				else
				{
					cout << "No Result  | " << endl;
				}
				cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
			}
		}
		else
		{
			cout << "���  | �������  |" << theme << "  |" << endl;
			cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

			for (int i = 0; i < count; i++)
			{
				int Fl = 0;
				for (int j = 0; j < size; j++)
				{
					if (students[i].grades[Number_Of_Theme - 1] == filter[j]) { Fl++; break; }
				}
				if (Fl >= 1)
				{
					cout << students[i].firstName << "  | " << students[i].lastName << "  | ";
					if (students[i].grades[Number_Of_Theme - 1] != 0)
					{
						cout << students[i].grades[Number_Of_Theme - 1] << "  | " << endl;
					}
					else
					{
						cout << "No Result  | " << endl;
					}
					cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
				}
			}
		}

	}
	if (sort == 1)
	{
		if (range_sort == 1)
		{
			if (filter[0] == -1)
			{
				cout << "���  | �������  |" << theme << "  |" << endl;
				cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

				for (int i = 0; i < count; i++)
				{
					students_2[i].firstName = students[i].firstName;
					students_2[i].lastName = students[i].lastName;
					students_2[i].login = students[i].login;
					students_2[i].password = students[i].password;
					students_2[i].testGrade = students[i].testGrade;
					for (int j = 0; j < MAX_GRADES; j++)
					{
						students_2[i].grades[j] = students[i].grades[j];
					}
				}

				for (int i = 0; i < count - 1; i++)
				{
					string firstName, lastName, login, password;
					int testGrade, grades[MAX_GRADES];
					if (students_2[i + 1].grades[Number_Of_Theme - 1] > students_2[i].grades[Number_Of_Theme - 1])
					{
						firstName = students_2[i].firstName;
						lastName = students_2[i].lastName;
						login = students_2[i].login;
						password = students_2[i].password;
						testGrade = students_2[i].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							grades[j] = students_2[i].grades[j];
						}

						students_2[i].firstName = students_2[i + 1].firstName;
						students_2[i].lastName = students_2[i + 1].lastName;
						students_2[i].login = students_2[i + 1].login;
						students_2[i].password = students_2[i + 1].password;
						students_2[i].testGrade = students_2[i + 1].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i].grades[j] = students_2[i + 1].grades[j];
						}

						students_2[i + 1].firstName = firstName;
						students_2[i + 1].lastName = lastName;
						students_2[i + 1].login = login;
						students_2[i + 1].password = password;
						students_2[i + 1].testGrade = testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i + 1].grades[j] = grades[j];
						}

						i = 0;
					}
				}

				for (int i = 0; i < count; i++)
				{
					cout << students_2[i].firstName << "  | " << students_2[i].lastName << "  | ";
					if (students_2[i].grades[Number_Of_Theme - 1] != 0)
					{
						cout << students_2[i].grades[Number_Of_Theme - 1] << "  | " << endl;
					}
					else
					{
						cout << "No Result  | " << endl;
					}
					cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
				}
			}
			else
			{
				cout << "���  | �������  |" << theme << "  |" << endl;
				cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

				for (int i = 0; i < count; i++)
				{
					students_2[i].firstName = students[i].firstName;
					students_2[i].lastName = students[i].lastName;
					students_2[i].login = students[i].login;
					students_2[i].password = students[i].password;
					students_2[i].testGrade = students[i].testGrade;
					for (int j = 0; j < MAX_GRADES; j++)
					{
						students_2[i].grades[j] = students[i].grades[j];
					}
				}

				for (int i = 0; i < count - 1; i++)
				{
					string firstName, lastName, login, password;
					int testGrade, grades[MAX_GRADES];
					if (students_2[i + 1].grades[Number_Of_Theme - 1] > students_2[i].grades[Number_Of_Theme - 1])
					{
						firstName = students_2[i].firstName;
						lastName = students_2[i].lastName;
						login = students_2[i].login;
						password = students_2[i].password;
						testGrade = students_2[i].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							grades[j] = students_2[i].grades[j];
						}

						students_2[i].firstName = students_2[i + 1].firstName;
						students_2[i].lastName = students_2[i + 1].lastName;
						students_2[i].login = students_2[i + 1].login;
						students_2[i].password = students_2[i + 1].password;
						students_2[i].testGrade = students_2[i + 1].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i].grades[j] = students_2[i + 1].grades[j];
						}

						students_2[i + 1].firstName = firstName;
						students_2[i + 1].lastName = lastName;
						students_2[i + 1].login = login;
						students_2[i + 1].password = password;
						students_2[i + 1].testGrade = testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i + 1].grades[j] = grades[j];
						}

						i = 0;
					}
				}

				for (int i = 0; i < count; i++)
				{
					int Fl = 0;
					for (int j = 0; j < size; j++)
					{
						if (students_2[i].grades[Number_Of_Theme - 1] == filter[j]) { Fl++; break; }
					}
					if (Fl >= 1)
					{
						cout << students_2[i].firstName << "  | " << students_2[i].lastName << "  | ";
						if (students_2[i].grades[Number_Of_Theme - 1] != 0)
						{
							cout << students_2[i].grades[Number_Of_Theme - 1] << "  | " << endl;
						}
						else
						{
							cout << "No Result  | " << endl;
						}
						cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
					}
				}
			}
		}
		if (range_sort == 2)
		{
			if (filter[0] == -1)
			{
				cout << "���  | �������  |" << theme << "  |" << endl;
				cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

				for (int i = 0; i < count; i++)
				{
					students_2[i].firstName = students[i].firstName;
					students_2[i].lastName = students[i].lastName;
					students_2[i].login = students[i].login;
					students_2[i].password = students[i].password;
					students_2[i].testGrade = students[i].testGrade;
					for (int j = 0; j < MAX_GRADES; j++)
					{
						students_2[i].grades[j] = students[i].grades[j];
					}
				}

				for (int i = 0; i < count - 1; i++)
				{
					string firstName, lastName, login, password;
					int testGrade, grades[MAX_GRADES];
					if (students_2[i + 1].grades[Number_Of_Theme - 1] < students_2[i].grades[Number_Of_Theme - 1])
					{
						firstName = students_2[i].firstName;
						lastName = students_2[i].lastName;
						login = students_2[i].login;
						password = students_2[i].password;
						testGrade = students_2[i].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							grades[j] = students_2[i].grades[j];
						}

						students_2[i].firstName = students_2[i + 1].firstName;
						students_2[i].lastName = students_2[i + 1].lastName;
						students_2[i].login = students_2[i + 1].login;
						students_2[i].password = students_2[i + 1].password;
						students_2[i].testGrade = students_2[i + 1].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i].grades[j] = students_2[i + 1].grades[j];
						}

						students_2[i + 1].firstName = firstName;
						students_2[i + 1].lastName = lastName;
						students_2[i + 1].login = login;
						students_2[i + 1].password = password;
						students_2[i + 1].testGrade = testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i + 1].grades[j] = grades[j];
						}

						i = 0;
					}
				}


				for (int i = 0; i < count; i++)
				{
					cout << students_2[i].firstName << "  | " << students_2[i].lastName << "  | ";
					if (students_2[i].grades[Number_Of_Theme - 1] != 0)
					{
						cout << students_2[i].grades[Number_Of_Theme - 1] << "  | " << endl;
					}
					else
					{
						cout << "No Result  | " << endl;
					}
					cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
				}
			}
			else
			{
				cout << "���  | �������  |" << theme << "  |" << endl;
				cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

				for (int i = 0; i < count; i++)
				{
					students_2[i].firstName = students[i].firstName;
					students_2[i].lastName = students[i].lastName;
					students_2[i].login = students[i].login;
					students_2[i].password = students[i].password;
					students_2[i].testGrade = students[i].testGrade;
					for (int j = 0; j < MAX_GRADES; j++)
					{
						students_2[i].grades[j] = students[i].grades[j];
					}
				}

				for (int i = 0; i < count - 1; i++)
				{
					string firstName, lastName, login, password;
					int testGrade, grades[MAX_GRADES];
					if (students_2[i + 1].grades[Number_Of_Theme - 1] < students_2[i].grades[Number_Of_Theme - 1])
					{
						firstName = students_2[i].firstName;
						lastName = students_2[i].lastName;
						login = students_2[i].login;
						password = students_2[i].password;
						testGrade = students_2[i].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							grades[j] = students_2[i].grades[j];
						}

						students_2[i].firstName = students_2[i + 1].firstName;
						students_2[i].lastName = students_2[i + 1].lastName;
						students_2[i].login = students_2[i + 1].login;
						students_2[i].password = students_2[i + 1].password;
						students_2[i].testGrade = students_2[i + 1].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i].grades[j] = students_2[i + 1].grades[j];
						}

						students_2[i + 1].firstName = firstName;
						students_2[i + 1].lastName = lastName;
						students_2[i + 1].login = login;
						students_2[i + 1].password = password;
						students_2[i + 1].testGrade = testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i + 1].grades[j] = grades[j];
						}

						i = 0;
					}
				}

				for (int i = 0; i < count; i++)
				{
					int Fl = 0;
					for (int j = 0; j < size; j++)
					{
						if (students_2[i].grades[Number_Of_Theme - 1] == filter[j]) { Fl++; break; }
					}
					if (Fl >= 1)
					{
						cout << students_2[i].firstName << "  | " << students_2[i].lastName << "  | ";
						if (students_2[i].grades[Number_Of_Theme - 1] != 0)
						{
							cout << students_2[i].grades[Number_Of_Theme - 1] << "  | " << endl;
						}
						else
						{
							cout << "No Result  | " << endl;
						}
						cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
					}
				}
			}
		}
	}
	cout << "��� ����������� ������� ����� �������: ";
	_getch();
	system("cls");
}

void Print_List_Test(int& sort, int filter[], int size, int& range_sort, int& theme_sort, Student* students, int& count)
{
	int Number_Of_Theme;
	string theme;
	Student students_2[MAX_STUDENTS];
	int Number_Of_Students = count;
	cout << " ������ ��������� " << endl;
	cout << " ====================================================================================================" << endl;
	if (sort == -1)
	{
		if (filter[0] == -1)
		{
			cout << "���  | �������  | " << "����  |" << endl;
			cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

			for (int i = 0; i < count; i++)
			{
				cout << students[i].firstName << "  | " << students[i].lastName << "  | ";
				cout << students[i].testGrade << "  | " << endl;
				cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
			}
		}
		else
		{
			cout << "���  | �������  | " << "����  |" << endl;
			cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

			for (int i = 0; i < count; i++)
			{
				int Fl = 0;
				for (int k = 0; k < MAX_GRADES; k++)
				{
					for (int j = 0; j < size; j++)
					{
						if (students_2[i].testGrade == filter[j]) { Fl++; break; }
					}
					if (Fl == 1) { break; }
				}
				if (Fl == 1)
				{
					cout << students_2[i].firstName << "  | " << students_2[i].lastName << "  | " << students_2[i].testGrade << "  | " << endl;
					cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
				}
			}
		}
	}
	if (sort == 2)
	{
		if (range_sort == 1)
		{
			if (filter[0] == -1)
			{
				cout << "���  | �������  | " << "����  |" << endl;
				cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

				for (int i = 0; i < count; i++)
				{
					students_2[i].firstName = students[i].firstName;
					students_2[i].lastName = students[i].lastName;
					students_2[i].login = students[i].login;
					students_2[i].password = students[i].password;
					students_2[i].testGrade = students[i].testGrade;
					for (int j = 0; j < MAX_GRADES; j++)
					{
						students_2[i].grades[j] = students[i].grades[j];
					}
				}

				for (int i = 0; i < count - 1; i++)
				{
					string firstName, lastName, login, password;
					int testGrade, grades[MAX_GRADES];
					if (students_2[i + 1].testGrade > students_2[i].testGrade)
					{
						firstName = students_2[i].firstName;
						lastName = students_2[i].lastName;
						login = students_2[i].login;
						password = students_2[i].password;
						testGrade = students_2[i].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							grades[j] = students_2[i].grades[j];
						}

						students_2[i].firstName = students_2[i + 1].firstName;
						students_2[i].lastName = students_2[i + 1].lastName;
						students_2[i].login = students_2[i + 1].login;
						students_2[i].password = students_2[i + 1].password;
						students_2[i].testGrade = students_2[i + 1].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i].grades[j] = students_2[i + 1].grades[j];
						}

						students_2[i + 1].firstName = firstName;
						students_2[i + 1].lastName = lastName;
						students_2[i + 1].login = login;
						students_2[i + 1].password = password;
						students_2[i + 1].testGrade = testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i + 1].grades[j] = grades[j];
						}

						i = 0;
					}
				}
				for (int i = 0; i < count; i++)
				{
					cout << students_2[i].firstName << "  | " << students_2[i].lastName << "  | ";
					cout << students_2[i].testGrade << "  | " << endl;
					cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
				}
			}
			else
			{
				cout << "���  | �������  | " << "����  |" << endl;
				cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

				for (int i = 0; i < count; i++)
				{
					students_2[i].firstName = students[i].firstName;
					students_2[i].lastName = students[i].lastName;
					students_2[i].login = students[i].login;
					students_2[i].password = students[i].password;
					students_2[i].testGrade = students[i].testGrade;
					for (int j = 0; j < MAX_GRADES; j++)
					{
						students_2[i].grades[j] = students[i].grades[j];
					}
				}

				for (int i = 0; i < count - 1; i++)
				{
					string firstName, lastName, login, password;
					int testGrade, grades[MAX_GRADES];
					if (students_2[i + 1].testGrade > students_2[i].testGrade)
					{
						firstName = students_2[i].firstName;
						lastName = students_2[i].lastName;
						login = students_2[i].login;
						password = students_2[i].password;
						testGrade = students_2[i].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							grades[j] = students_2[i].grades[j];
						}

						students_2[i].firstName = students_2[i + 1].firstName;
						students_2[i].lastName = students_2[i + 1].lastName;
						students_2[i].login = students_2[i + 1].login;
						students_2[i].password = students_2[i + 1].password;
						students_2[i].testGrade = students_2[i + 1].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i].grades[j] = students_2[i + 1].grades[j];
						}

						students_2[i + 1].firstName = firstName;
						students_2[i + 1].lastName = lastName;
						students_2[i + 1].login = login;
						students_2[i + 1].password = password;
						students_2[i + 1].testGrade = testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i + 1].grades[j] = grades[j];
						}

						i = 0;
					}
				}

				for (int i = 0; i < count; i++)
				{
					int Fl = 0;
					for (int k = 0; k < MAX_GRADES; k++)
					{
						for (int j = 0; j < size; j++)
						{
							if (students_2[i].testGrade == filter[j]) { Fl++; break; }
						}
						if (Fl == 1) { break; }
					}
					if (Fl == 1)
					{
						cout << students_2[i].firstName << "  | " << students_2[i].lastName << "  | " << students_2[i].testGrade << "  | " << endl;
						cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
					}
				}
			}
		}
		if (range_sort == 2)
		{
			if (filter[0] == -1)
			{
				cout << "���  | �������  | " << "����  |" << endl;
				cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

				for (int i = 0; i < count; i++)
				{
					students_2[i].firstName = students[i].firstName;
					students_2[i].lastName = students[i].lastName;
					students_2[i].login = students[i].login;
					students_2[i].password = students[i].password;
					students_2[i].testGrade = students[i].testGrade;
					for (int j = 0; j < MAX_GRADES; j++)
					{
						students_2[i].grades[j] = students[i].grades[j];
					}
				}

				for (int i = 0; i < count - 1; i++)
				{
					string firstName, lastName, login, password;
					int testGrade, grades[MAX_GRADES];
					if (students_2[i + 1].testGrade < students_2[i].testGrade)
					{
						firstName = students_2[i].firstName;
						lastName = students_2[i].lastName;
						login = students_2[i].login;
						password = students_2[i].password;
						testGrade = students_2[i].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							grades[j] = students_2[i].grades[j];
						}

						students_2[i].firstName = students_2[i + 1].firstName;
						students_2[i].lastName = students_2[i + 1].lastName;
						students_2[i].login = students_2[i + 1].login;
						students_2[i].password = students_2[i + 1].password;
						students_2[i].testGrade = students_2[i + 1].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i].grades[j] = students_2[i + 1].grades[j];
						}

						students_2[i + 1].firstName = firstName;
						students_2[i + 1].lastName = lastName;
						students_2[i + 1].login = login;
						students_2[i + 1].password = password;
						students_2[i + 1].testGrade = testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i + 1].grades[j] = grades[j];
						}

						i = 0;
					}
				}

				for (int i = 0; i < count; i++)
				{
					cout << students_2[i].firstName << "  | " << students_2[i].lastName << "  | ";
					cout << students_2[i].testGrade << "  | " << endl;
					cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
				}
			}
			else
			{
				cout << "���  | �������  | " << "����  |" << endl;
				cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

				for (int i = 0; i < count; i++)
				{
					students_2[i].firstName = students[i].firstName;
					students_2[i].lastName = students[i].lastName;
					students_2[i].login = students[i].login;
					students_2[i].password = students[i].password;
					students_2[i].testGrade = students[i].testGrade;
					for (int j = 0; j < MAX_GRADES; j++)
					{
						students_2[i].grades[j] = students[i].grades[j];
					}
				}

				for (int i = 0; i < count - 1; i++)
				{
					string firstName, lastName, login, password;
					int testGrade, grades[MAX_GRADES];
					if (students_2[i + 1].testGrade < students_2[i].testGrade)
					{
						firstName = students_2[i].firstName;
						lastName = students_2[i].lastName;
						login = students_2[i].login;
						password = students_2[i].password;
						testGrade = students_2[i].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							grades[j] = students_2[i].grades[j];
						}

						students_2[i].firstName = students_2[i + 1].firstName;
						students_2[i].lastName = students_2[i + 1].lastName;
						students_2[i].login = students_2[i + 1].login;
						students_2[i].password = students_2[i + 1].password;
						students_2[i].testGrade = students_2[i + 1].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i].grades[j] = students_2[i + 1].grades[j];
						}

						students_2[i + 1].firstName = firstName;
						students_2[i + 1].lastName = lastName;
						students_2[i + 1].login = login;
						students_2[i + 1].password = password;
						students_2[i + 1].testGrade = testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i + 1].grades[j] = grades[j];
						}

						i = 0;
					}
				}
				for (int i = 0; i < count; i++)
				{
					int Fl = 0;
					for (int k = 0; k < MAX_GRADES; k++)
					{
						for (int j = 0; j < size; j++)
						{
							if (students_2[i].testGrade == filter[j]) { Fl++; break; }
						}
						if (Fl == 1) { break; }
					}
					if (Fl == 1)
					{
						cout << students_2[i].firstName << "  | " << students_2[i].lastName << "  | " << students_2[i].testGrade << "  | " << endl;
						cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
					}
				}
			}
		}
	}
	cout << "��� ����������� ������� ����� �������: ";
	_getch();
	system("cls");
}

void Print_List_Average(int& sort, int filter[], int size, int& range_sort, int& theme_sort, Student* students, int& count)
{
	int Number_Of_Theme;
	string theme;
	Student students_2[MAX_STUDENTS];
	int Number_Of_Students = count;
	cout << " ������ ��������� " << endl;
	cout << " ====================================================================================================" << endl;
	if (sort == -1)
	{

		if (filter[0] == -1)
		{
			cout << "���  | �������  |";
			cout << " ��. ����  |" << endl;
			cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

			for (int i = 0; i < count; i++)
			{
				cout << students[i].firstName << "  | " << students[i].lastName << "  | ";
				cout << (students[i].average = calculateAverage(students[i])) << "  | " << endl;
				cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
			}
		}
		else
		{
			cout << "���  | �������  |";
			cout << " ��. ����  |" << endl;
			cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

			for (int i = 0; i < count; i++)
			{
				int Fl = 0;
				for (int k = 0; k < MAX_GRADES; k++)
				{
					for (int j = 0; j < size; j++)
					{
						if (calculateAverage(students[i]) == filter[j]) { Fl++; break; }
					}
					if (Fl == 1) { break; }
				}
				if (Fl == 1)
				{
					cout << students_2[i].firstName << "  | " << students_2[i].lastName << "  | " << (students[i].average = calculateAverage(students[i])) << "  | " << endl;
					cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
				}
			}
		}
	}
	if (sort == 3)
	{
		if (range_sort == 1)
		{
			if (filter[0] == -1)
			{
				cout << "���  | �������  |";
				cout << " ��. ����  |" << endl;
				cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

				for (int i = 0; i < count; i++)
				{
					students_2[i].firstName = students[i].firstName;
					students_2[i].lastName = students[i].lastName;
					students_2[i].login = students[i].login;
					students_2[i].password = students[i].password;
					students_2[i].testGrade = students[i].testGrade;
					for (int j = 0; j < MAX_GRADES; j++)
					{
						students_2[i].grades[j] = students[i].grades[j];
					}
				}

				for (int i = 0; i < count - 1; i++)
				{
					string firstName, lastName, login, password;
					int testGrade, grades[MAX_GRADES];
					students_2[i].average = calculateAverage(students_2[i]);
					students_2[i + 1].average = calculateAverage(students_2[i + 1]);
					if (students_2[i + 1].average > students_2[i].average)
					{
						firstName = students_2[i].firstName;
						lastName = students_2[i].lastName;
						login = students_2[i].login;
						password = students_2[i].password;
						testGrade = students_2[i].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							grades[j] = students_2[i].grades[j];
						}

						students_2[i].firstName = students_2[i + 1].firstName;
						students_2[i].lastName = students_2[i + 1].lastName;
						students_2[i].login = students_2[i + 1].login;
						students_2[i].password = students_2[i + 1].password;
						students_2[i].testGrade = students_2[i + 1].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i].grades[j] = students_2[i + 1].grades[j];
						}

						students_2[i + 1].firstName = firstName;
						students_2[i + 1].lastName = lastName;
						students_2[i + 1].login = login;
						students_2[i + 1].password = password;
						students_2[i + 1].testGrade = testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i + 1].grades[j] = grades[j];
						}

						i = 0;
					}
				}

				for (int i = 0; i < count; i++)
				{
					cout << students_2[i].firstName << "  | " << students_2[i].lastName << "  | ";
					cout << (students_2[i].average = calculateAverage(students_2[i])) << "  | " << endl;
					cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
				}
			}
			else
			{
				cout << "���  | �������  |";
				cout << " ��. ����  |" << endl;
				cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

				for (int i = 0; i < count; i++)
				{
					students_2[i].firstName = students[i].firstName;
					students_2[i].lastName = students[i].lastName;
					students_2[i].login = students[i].login;
					students_2[i].password = students[i].password;
					students_2[i].testGrade = students[i].testGrade;
					for (int j = 0; j < MAX_GRADES; j++)
					{
						students_2[i].grades[j] = students[i].grades[j];
					}
				}

				for (int i = 0; i < count - 1; i++)
				{
					string firstName, lastName, login, password;
					int testGrade, grades[MAX_GRADES];
					students_2[i].average = calculateAverage(students_2[i]);
					students_2[i + 1].average = calculateAverage(students_2[i + 1]);
					if (students_2[i + 1].average > students_2[i].average)
					{
						firstName = students_2[i].firstName;
						lastName = students_2[i].lastName;
						login = students_2[i].login;
						password = students_2[i].password;
						testGrade = students_2[i].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							grades[j] = students_2[i].grades[j];
						}

						students_2[i].firstName = students_2[i + 1].firstName;
						students_2[i].lastName = students_2[i + 1].lastName;
						students_2[i].login = students_2[i + 1].login;
						students_2[i].password = students_2[i + 1].password;
						students_2[i].testGrade = students_2[i + 1].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i].grades[j] = students_2[i + 1].grades[j];
						}

						students_2[i + 1].firstName = firstName;
						students_2[i + 1].lastName = lastName;
						students_2[i + 1].login = login;
						students_2[i + 1].password = password;
						students_2[i + 1].testGrade = testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i + 1].grades[j] = grades[j];
						}

						i = 0;
					}
				}

				for (int i = 0; i < count; i++)
				{
					int Fl = 0;
					for (int k = 0; k < MAX_GRADES; k++)
					{
						for (int j = 0; j < size; j++)
						{
							if (int(students_2[i].average) == filter[j]) { Fl++; break; }
						}
						if (Fl == 1) { break; }
					}
					if (Fl == 1)
					{
						cout << students_2[i].firstName << "  | " << students_2[i].lastName << "  | ";
						cout << (students_2[i].average = calculateAverage(students_2[i])) << "  | " << endl;
						cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
					}
				}
			}
		}
		if (range_sort == 2)
		{
			if (filter[0] == -1)
			{
				cout << "���  | �������  |";
				cout << " ��. ����  |" << endl;
				cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

				for (int i = 0; i < count; i++)
				{
					students_2[i].firstName = students[i].firstName;
					students_2[i].lastName = students[i].lastName;
					students_2[i].login = students[i].login;
					students_2[i].password = students[i].password;
					students_2[i].testGrade = students[i].testGrade;
					for (int j = 0; j < MAX_GRADES; j++)
					{
						students_2[i].grades[j] = students[i].grades[j];
					}
				}

				for (int i = 0; i < count - 1; i++)
				{
					string firstName, lastName, login, password;
					int testGrade, grades[MAX_GRADES];
					students_2[i].average = calculateAverage(students_2[i]);
					students_2[i + 1].average = calculateAverage(students_2[i + 1]);
					if (students_2[i + 1].average < students_2[i].average)
					{
						firstName = students_2[i].firstName;
						lastName = students_2[i].lastName;
						login = students_2[i].login;
						password = students_2[i].password;
						testGrade = students_2[i].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							grades[j] = students_2[i].grades[j];
						}

						students_2[i].firstName = students_2[i + 1].firstName;
						students_2[i].lastName = students_2[i + 1].lastName;
						students_2[i].login = students_2[i + 1].login;
						students_2[i].password = students_2[i + 1].password;
						students_2[i].testGrade = students_2[i + 1].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i].grades[j] = students_2[i + 1].grades[j];
						}

						students_2[i + 1].firstName = firstName;
						students_2[i + 1].lastName = lastName;
						students_2[i + 1].login = login;
						students_2[i + 1].password = password;
						students_2[i + 1].testGrade = testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i + 1].grades[j] = grades[j];
						}

						i = 0;
					}
				}


				for (int i = 0; i < count; i++)
				{
					cout << students_2[i].firstName << "  | " << students_2[i].lastName << "  | ";
					cout << (students_2[i].average = calculateAverage(students_2[i])) << "  | " << endl;
					cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
				}
			}
			else
			{
				cout << "���  | �������  |";
				cout << " ��. ����  |" << endl;
				cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

				for (int i = 0; i < count; i++)
				{
					students_2[i].firstName = students[i].firstName;
					students_2[i].lastName = students[i].lastName;
					students_2[i].login = students[i].login;
					students_2[i].password = students[i].password;
					students_2[i].testGrade = students[i].testGrade;
					for (int j = 0; j < MAX_GRADES; j++)
					{
						students_2[i].grades[j] = students[i].grades[j];
					}
				}

				for (int i = 0; i < count - 1; i++)
				{
					string firstName, lastName, login, password;
					int testGrade, grades[MAX_GRADES];
					students_2[i].average = calculateAverage(students_2[i]);
					students_2[i + 1].average = calculateAverage(students_2[i + 1]);
					if (students_2[i + 1].average < students_2[i].average)
					{
						firstName = students_2[i].firstName;
						lastName = students_2[i].lastName;
						login = students_2[i].login;
						password = students_2[i].password;
						testGrade = students_2[i].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							grades[j] = students_2[i].grades[j];
						}

						students_2[i].firstName = students_2[i + 1].firstName;
						students_2[i].lastName = students_2[i + 1].lastName;
						students_2[i].login = students_2[i + 1].login;
						students_2[i].password = students_2[i + 1].password;
						students_2[i].testGrade = students_2[i + 1].testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i].grades[j] = students_2[i + 1].grades[j];
						}

						students_2[i + 1].firstName = firstName;
						students_2[i + 1].lastName = lastName;
						students_2[i + 1].login = login;
						students_2[i + 1].password = password;
						students_2[i + 1].testGrade = testGrade;
						for (int j = 0; j < MAX_GRADES; j++)
						{
							students_2[i + 1].grades[j] = grades[j];
						}

						i = 0;
					}
				}

				for (int i = 0; i < count; i++)
				{
					int Fl = 0;
					for (int k = 0; k < MAX_GRADES; k++)
					{
						for (int j = 0; j < size; j++)
						{
							if (int(students_2[i].average) == filter[j]) { Fl++; break; }
						}
						if (Fl == 1) { break; }
					}
					if (Fl == 1)
					{
						cout << students_2[i].firstName << "  | " << students_2[i].lastName << "  | ";
						cout << (students_2[i].average = calculateAverage(students_2[i])) << "  | " << endl;
						cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
					}
				}
			}
		}
	}
	cout << "��� ����������� ������� ����� �������: ";
	_getch();
	system("cls");
}

void Filters(int filter[], int &size)
{
	int choice;
	char Block = 'N';
	do
	{
		do
		{
			cout << " ������� ������ ��� ���������� ��� ������� \"0\" ��� ���������� ����������: ";
			cin >> choice;
			if (choice == 0)
			{
				size = 1;
				filter[0] = -1;
				filter = (int*)realloc(filter, sizeof(int) * size);
				Block = 'N';
				break;
			}
			for (int i = 0; i < size; i++)
			{
				if (choice == filter[i])
				{
					choice == 6;
					cout << " ������ ��� �������� � ����������" << endl;
				}
			}
			if ((choice < 0) or (choice > 6)) { cout << " ������� �������� ������. ���������� �����" << endl; }
		} while ((choice < 0)or(choice > 5));
		if (choice != 0)
		{
			filter[size - 1] = choice;
			cout << " ������ �������� ��� ���� ������ ��� �������? (Y/N): ";
			cin >> Block;
			if (Block == 'N')
			{
				cout << " ����������� �����" << endl;
				cout << "��� ����������� ������� ����� �������: ";
				_getch();
				system("cls");
				break;
			}
			else
			{
				size++;
				filter = (int*)realloc(filter, sizeof(int) * size);
				filter[size - 1] = -1;
			}
		}
		system("cls");
	} while (Block != 'N');
}

void Sort(int &sort, int& range_sort, int& theme_sort)
{
	int choice, theme;
	do
	{
		cout << " ������ ����� ����������: " << endl;
		cout << " 1. ���������� �� ������������ ����" << endl;
		cout << " 2. ���������� �� ��������� �����" << endl;
		cout << " 3. ���������� �� �������� �����" << endl;
		cout << " 0. ��������� ����������" << endl;
		cout << endl;
		cout << " �������� ����������: ";
		cin >> choice;
		if ((choice < 0) or (choice > 3)) { cout << " ������� �������� ����������. ���������� �����" << endl; }
	} while ((choice < 0) or (choice > 3));
	sort = choice;

	if (sort == 1)
	{
		do
		{
			cout << " ������ ��� ��� ����������: " << endl;
			cout << " 1. CYCLES" << endl;
			cout << " 2. ARRAYS (ONE- AND TWO-DIMENSIONAL)" << endl;
			cout << " 3. STRINGS" << endl;
			cout << " 4. RECURSION" << endl;
			cout << " 5. STRUCTURES" << endl;
			cout << " 6. FILES" << endl;
			cout << " 7. ADDRESSES AND SIGNS" << endl;
			cout << " 8. DYNAMIC MEMORY" << endl;
			cout << endl;
			cout << " �������� ����: ";
			cin >> theme;
			if ((theme < 1) or (theme > 8)) { cout << " ������� �������� ���� ��� ����������. ���������� �����" << endl; }
		} while ((theme < 1) or (theme > 8));
		system("cls");
		do
		{
			cout << " ������ �������� ����������: " << endl;
			cout << " 1. ���������� �� ��������" << endl;
			cout << " 2. ���������� �� �����������" << endl;
			cout << endl;
			cout << " �������� ������ ����������: ";
			cin >> choice;
			if ((choice < 1) or (choice > 2)) { cout << " ������ �������� ������ ����������. ���������� �����" << endl; }
		} while ((choice < 1) or (choice > 2));
		sort = 1;
		range_sort = choice;
		theme_sort = theme;
	}
	else
	{
		if (sort == 2)
		{
			do
			{
				cout << " ������ �������� ����������: " << endl;
				cout << " 1. ���������� �� ��������" << endl;
				cout << " 2. ���������� �� �����������" << endl;
				cout << endl;
				cout << " �������� ������ ����������: ";
				cin >> choice;
				if ((choice < 1) or (choice > 2)) { cout << " ������ �������� ������ ����������. ���������� �����" << endl; }
			} while ((choice < 1) or (choice > 2));
			sort = 2;
			range_sort = choice;
			theme_sort = -1;
		}
		else
		{
			if (sort == 3)
			{
				do
				{
					cout << " ������ �������� ����������: " << endl;
					cout << " 1. ���������� �� ��������" << endl;
					cout << " 2. ���������� �� �����������" << endl;
					cout << endl;
					cout << " �������� ������ ����������: ";
					cin >> choice;
					if ((choice < 1) or (choice > 2)) { cout << " ������ �������� ������ ����������. ���������� �����" << endl; }
				} while ((choice < 1) or (choice > 2));
				range_sort = choice;
				sort = 3;
				theme_sort = -1;
			}
			else
			{
				sort = -1;
				range_sort = -1;
				theme_sort = -1;
			}
		}
	}
	system("cls");
}