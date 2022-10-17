#include "monomial.h"
int main()
{
	Monomial f, g;
	f.readData();
	g.readData();
	f.assignCoefficent(2.5);
	g.assignExponent(4);
	double x = f.calValue(3), y = g.calValue(6);
	f.writeData();
	g.writeData();
	Monomial F = f.add(g);
	Monomial G = f.multifly(g);
	int z = F.compareTo(G);
	return 0;
}