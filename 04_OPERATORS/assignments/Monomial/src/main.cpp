#include "Nomial.h"
int Cong(const int &a,const  int&b) {
	cout << &a << "\n";
	return a + b;
}
int main() {
	Cong(1, 2);
	int a = 1;
	cout << &a << "\n";
	Cong(a, 2);
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