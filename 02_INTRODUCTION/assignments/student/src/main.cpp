#include "student.h"

int main()
{
	student s;
	s.readData();
	s.writeData();
	// Expected output: same as input
	s.assignName("abc def");
	s.writeData();
	// Expected output: student name is "abc def"
	double score = s.calMeanScore();
	string grade = s.getGrade();
	cout << "Mean score is: " << score << endl;
	cout << "Student grade: " << grade << endl;
	return 0;
}