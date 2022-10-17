#include "vector.h"
int main()
{
	vector<int> a(10, 2);
	int arr[5] = {1, 2, 3, 4, 5};
	vector<int> b(5, arr);
	vector<int> c(b);
	a.print();
	b.print();
	c.print();
	return 0;
}