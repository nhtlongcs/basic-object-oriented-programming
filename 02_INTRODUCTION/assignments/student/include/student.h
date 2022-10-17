#ifndef STU_H
#define STU_H

#include <iostream>
#include <string>
using namespace std;
class student
{
private:
	string m_name;
	double m_literature, m_math;

public:
	void readData();
	void writeData();
	string getName();
	double getLiterature();
	double getMath();
	void assignName(string s);
	void assignLiterature(double x);
	void assignMath(double x);
	double calMeanScore();
	string getGrade();
};

#endif