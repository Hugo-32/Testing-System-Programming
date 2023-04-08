//
// authStudents.h
// Васильев Артём
//

#define MAX_GRADES 8;

struct Student {
	string login;
	string password;
	string firstName;
	string lastName;
	int grades[MAX_GRADES];
	int testGrade;
	float average;
};
int readStudents(Student* students);
double calculateAverage(Student students);
void printStudent(Student& student);