#include <iostream>
#include "Vehicle.h"
int main()
{
	Truck T;
	Bike B;

	T.addGas(10);
	// Current gas: 10
	T.addGood(1000);
	// Current good: 1000
	std::cout << (T.run(10) ? "true" : "false") << std::endl;
	// Current distance: 10
	// N = 10, K = 1000, G = 10
	// N * (20/100 + K * (1 / 100 / 1000))
	// Expected: true,
	std::cout << T.getGas() << "\n";
	// Expected output: 10 - (10 * (20/100 + 1000 * (1 / 100 / 1000))) = 7.9
	B.addGas(1);
	// Current gas: 1
	B.addGood(100);
	// Current good: 100
	std::cout << (B.run(100000) ? "true" : "false") << std::endl;
	// Current distance: 100000
	// N * (gallons per km) = N * (2/100 + K * (0.1 / 100 / 10))
	// Expected: false, 1 - (100000 * (2/100 + 100 * (0.1 / 100 / 10))) < 0
	std::cout << B.getGas() << "\n";
	// Expected output: 1
	B.run(20);
	// Current distance: 100000
	std::cout << B.getGas() << "\n";
	// Expected output: 0.4
	return 0;
}