#include "list.h"
#include <iostream>
using namespace std;

int main()
{
	list A;
	A.readData();
	A.writeData();
	// Expected output: same as input

	A.assignAt(4, 10);
	A.writeData();
	// Expected output: X X X X 10 X X X ....
	int x = A.getSize();
	int y = A.getValueAt(5);
	cout << "Size of A is: " << x << endl;
	cout << "Value at index 5 is: " << y << endl;
	cout << "Sorted ascending: \n";
	A.sortAscending();
	A.writeData();
	// Expected output: sorted ascending
	cout << "Sorted descending: \n";
	A.sortDescending();
	A.writeData();
	// Expected output: sorted descending
	return 0;
}