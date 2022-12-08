#include "hotel.h"
#include <iomanip>
int main()
{
	Hotel h;
	h.readData();
	cout << std::setprecision(3) << std::fixed << h.calcPrice() << "\n";
	return 0;
}