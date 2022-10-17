#include "student.h"
#include <iostream>
void student::readData()
{
	getline(cin, this->m_name);
	cin >> this->m_literature >> this->m_math;
}
void student::writeData()
{
	cout << this->m_name << "\n";
	cout << "Van : " << this->m_literature << ". Toan : " << this->m_math;
}
string student::getName()
{
	return this->m_name;
}
double student::getLiterature()
{
	return this->m_literature;
}
double student::getMath()
{
	return this->m_math;
}
double student::calMeanScore()
{
	return 0.5 * (this->m_literature + this->m_math);
}
string student::getGrade()
{
	double score = this->calMeanScore();
	if (score >= 8)
		return "Gioi";
	else if (score >= 7)
		return "Kha";
	else if (score >= 5)
		return "Trung Binh";
	else
		return "Yeu";
}
void student::assignName(string s)
{
	this->m_name = s;
};
void student::assignLiterature(double x)
{
	this->m_literature = x;
};
void student::assignMath(double x)
{
	this->m_math = x;
};