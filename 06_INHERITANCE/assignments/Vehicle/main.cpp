#include <iostream>
#include "Vehicle.h"
using namespace std;
int main()
{
	Car C;
	Motor M;

	C.addGas(10);
	C.addGood(1000);
	C.run(10);
	cout << C.getGas() << "\n";

	M.addGas(1);
	M.addGood(100);
	M.run(100000);
	cout << M.getGas() << "\n";
	M.run(20);
	cout << M.getGas() << "\n";
	return 0;
}