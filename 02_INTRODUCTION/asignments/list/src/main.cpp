#include "list.h"
int main()
{
	list A;
	A.readData();
	A.assignAt(4, 10);
	A.writeData();
	int x = A.getSize();
	int y = A.getValueAt(5);
	A.sortAscending();
	A.writeData();
	A.sortDescending();
	A.writeData();
	return 0;
}