#include "nomial.h"

int main()
{
	Nomial f(2, 3);
	Nomial ff(3, 4);
	Nomial g = f + ff;
	Nomial gg = f * ff;
	cout << g;
	cout << gg;
	cout << (!g);
	cout << (g++);
	cout << (g--);

	return 0;
}