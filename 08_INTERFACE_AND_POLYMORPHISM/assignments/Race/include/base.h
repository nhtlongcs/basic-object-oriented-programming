#ifndef RACER_H
#define RACER_H

#include <string>
#include <iostream>
using namespace std;
class Racer
{
private:
	string m_name;
	int m_veclocity;

public:
	Racer(){};
	virtual ~Racer(){};
	virtual string getName() = 0;
	virtual int getV() = 0;
	static int Compare(Racer *r1, Racer *r2)
	{
		if (r1->getV() < r2->getV())
		{
			cout << r1->getName() << " < " << r2->getName() << "\n";
			return -1;
		}

		if (r1->getV() > r2->getV())
		{
			cout << r1->getName() << " > " << r2->getName() << "\n";
			return 1;
		}

		cout << r1->getName() << " == " << r2->getName() << "\n";
		return 0;
	}
};
#endif