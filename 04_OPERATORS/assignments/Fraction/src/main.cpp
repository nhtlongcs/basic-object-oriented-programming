#include "Fraction.h"
int main()
{
	Fraction p1(2, 3);
	Fraction p2(-5, 4);
	Fraction p3 = p1 * p2;
	Fraction p4 = p1 + p2;
	cout << (p3 + p4);
	cout << (p3 > Fraction(1, 2));
	cout << "Nhap";
	cin >> p3;
	cout << p3;
	Fraction p5 = Fraction(1, 1);
	p5++;
	p5--;
	Fraction p6 = ((++p5)++);
	cout << p5 << "\n";
	cout << p6 << " " << ((++p5) + Fraction(3, 1));
	cout << (int)p1;
	cout << double(p2);
	return 0;
}