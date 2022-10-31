#include <iostream>
#include "RandomlyGeneratedIntegers.h"
using namespace std;
int main()
{
	srand(time(NULL)); // Should only be called once

	RandomlyGeneratedIntegers RandomlyGeneratedIntegers;
	RandomlyGeneratedIntegers.excute();
	return 0;
}