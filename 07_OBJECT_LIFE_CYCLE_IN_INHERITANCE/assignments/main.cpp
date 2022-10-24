#include <iostream>
#include "cinema.h"
using namespace std;
int main()
{
	Cinema R(10, 10);
	R.Book(1, 1);
	R.Book(2, 2);
	R.Book(3, 3);
	R.Book(4, 4);
	R.Book(5, 5);
	R.Book(6, 6);
	cout << R.Check(1, 1) << " ";
	cout << R.Check(1, 2) << " ";
	cout << R.Cost(7, 2) << "\n";
	cout << R.Profit() << "\n";

	HighClassCinema RC(10, 10, 5);

	RC.Book(5, 5);
	RC.Book(6, 6);
	cout << RC.Check(1, 1) << " ";
	cout << RC.Check(1, 2) << " ";
	cout << RC.Cost(7, 2) << "\n";
	cout << RC.Profit() << "\n";
	return 0;
}