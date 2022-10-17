#include "student.h"

int main()
{
	student Hs;
	Hs.readData();
	Hs.writeData();
	// Expected output: same as input
	Hs.assignName("abc def");
	Hs.writeData();
	// Expected output: student name is "abc def"
	double score = Hs.calMeanScore();
	string grade = Hs.getGrade();
	cout << "Mean score is: " << score << endl;
	cout << "Student grade: " << grade << endl;
	return 0;
}