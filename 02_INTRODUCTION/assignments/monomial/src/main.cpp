#include "monomial.h"

int main()
{
	Monomial f, g;
	f.readData();
	g.readData();
	f.writeData();
	g.writeData();
	cout << endl;
	// Expected output: same as input
	f.assignCoefficent(2.5);
	g.assignExponent(4);
	f.writeData();
	g.writeData();
	cout << endl;
	Monomial D1 = f.getDerivatie();
	Monomial D2 = g.getDerivatie();
	D1.writeData();
	D2.writeData();
	cout << endl;
	// Expected output: 2.5*x^{Exp_1} and {Coef_2}*x^4
	double x = f.calValue(3), y = g.calValue(6);
	cout << "f(3) = " << x << endl;
	cout << "g(6) = " << y << endl;
	// Expected output: f(3) = 18.75 and g(6) = 144
	Monomial F = f.add(g);
	Monomial G = f.multifly(g);
	int z = F.compareTo(G);
	F.writeData();
	G.writeData();
	// Expected output: 2.5*x^2 + 2*x^4 and 5*x^6
	cout << "F.compareTo(G) = " << z << endl;
	// Expected output: F.compareTo(G) = -1
	return 0;
}