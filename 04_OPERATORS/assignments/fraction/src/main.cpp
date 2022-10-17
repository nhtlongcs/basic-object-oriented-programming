#include "fraction.h"
#include <iostream>
using namespace std;

int main()
{
	Fraction p1(2, 3);
	Fraction p2(-5, 4);
	Fraction p3 = p1 * p2;				   // p3 = -10/12
	Fraction p4 = p1 + p2;				   // p4 = -7/12
	cout << (p3 + p4).compress() << endl;  // Expected output: -17/24
	cout << (p3 > Fraction(1, 2)) << endl; // Expected output: 0 (False)
	cout << "Nhap p3 ";					   // Expected input: <Numerator> <Denominator>
	cin >> p3;
	cout << endl;
	cout << p3 << endl;
	// Expected output: <Numerator> <Denominator>
	Fraction p5 = Fraction(1, 1);
	p5++;
	p5--;
	Fraction p6 = ((++p5)++);
	cout << p5 << "\n";
	// Expected output: 3/1
	cout << p6 << "\n";
	// Expected output: 2/1
	cout << ((++p5) + Fraction(3, 1)) << "\n";
	// Expected output: 7/1
	cout << (int)p1 << " " << (double)p2 << "\n";
	// Expected output: 0 -1.25
	return 0;
}