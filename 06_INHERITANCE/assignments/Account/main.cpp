#include <iostream>
#include "Account.h"
using namespace std;
int main()
{
	Account TK(20000);
	cout << TK.baoSoDu() << "\n";
	TK.napTien(20000);
	cout << TK.rutTien(35000) << "\n";
	cout << TK.baoSoDu() << "\n";

	SavingAccount TKTK(20000, 3, 0.04, 3);
	TKTK.tangThang();
	TKTK.tangThang();
	cout << TKTK.baoSoDu() << "\n";
	TKTK.napTien(10000);
	cout << TKTK.baoSoDu() << "\n";
	TKTK.tangThang();
	TKTK.tangThang();
	TKTK.tangThang();
	cout << TKTK.rutTien(50000) << "\n";
	cout << TKTK.rutTien(31000) << "\n";
	cout << TKTK.baoSoDu() << "\n";
	return 0;
}