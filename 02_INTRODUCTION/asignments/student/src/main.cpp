#include "student.h"
int main()
{
	student Hs;
	Hs.readData();
	string s = Hs.getName();
	Hs.assignName("abc def");
	double score = Hs.calMeanScore();
	string grade = Hs.getGrade();

	return 0;
}