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
void calculateAverage(Student& student);
void printStudent(Student& student);