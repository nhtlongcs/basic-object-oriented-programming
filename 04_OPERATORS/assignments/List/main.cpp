#include "Vector.h"
#include <iostream>
using namespace std;
int main() {
	int a[4] = { 1,2,3,4 };
	Vector<int> v(4, a);
	cout << v.a()[0];
	Vector<int> s = v;
	cout << v[3];
	cout << s[2];
	cout << ((int*)s)[0];
	cout << s;
	cin >> v;
	cout << v;
	cout << v.size();
	return 0;
}