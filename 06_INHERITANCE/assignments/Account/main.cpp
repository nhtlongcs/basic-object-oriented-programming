#include <iostream>
#include "Account.h"
int main()
{
	Account BAccount(20000);
	std::cout << BAccount.currBalance() << "\n";
	// Expected output: 20000
	BAccount.deposit(20000);
	// Current balance: 40000
	std::cout << BAccount.withdraw(35000) << "\n";
	// Expected output: 1 (true)
	std::cout << BAccount.currBalance() << "\n";
	// Expected output: 40000 - 35000 = 5000

	SavingAccount SAccount(20000, 3, 0.04, 3);
	// Current balance: 20000, peroid: 3, profit rate: 0.04, months: 3
	SAccount.incMonth();
	SAccount.incMonth();
	// Current balance: 20000, peroid: 3, profit rate: 0.04, months: 5
	std::cout << SAccount.currBalance() << "\n";
	// Expected output: 20000 * (1 + 0.04) ^ 1 = 20800
	SAccount.deposit(10000);
	// Months should be reset to 0 after deposit
	// Current balance: 20800 + 10000 = 30800, peroid: 3, profit rate: 0.04, months: 0
	std::cout << SAccount.currBalance() << "\n";
	// Expected output: 30800
	SAccount.incMonth();
	SAccount.incMonth();
	SAccount.incMonth();
	// Current balance: 30800, peroid: 3, profit rate: 0.04, months: 3
	std::cout << SAccount.withdraw(50000) << "\n";
	// Expected output: 0 (false)
	// Explanation: 30800 * (1 + 0.04) ^ 1 = 32032 < 50000
	std::cout << SAccount.currBalance() << "\n";
	// Expected output: 30800
	SAccount.incMonth();
	SAccount.incMonth();
	SAccount.incMonth();
	// Current balance: 30800, peroid: 3, profit rate: 0.04, months: 6
	std::cout << SAccount.withdraw(31000) << "\n";
	// Expected output: 1 (true)
	// Explanation: 30800 * (1 + 0.04) ^ 2 = 33313.28 > 31000
	std::cout << SAccount.currBalance() << "\n";
	// Expected output: 33313.28 - 31000 = 2313.28
	return 0;
}