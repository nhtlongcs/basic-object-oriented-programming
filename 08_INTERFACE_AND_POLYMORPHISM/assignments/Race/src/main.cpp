#include "human.h"
#include "cheetah.h"
#include "horse.h"
#include "base.h"
int main()
{
	Racer *a = new Human();
	Racer *b = new Cheetah();
	Racer *c = new Horse();
	Racer::Compare(a, b);
	Racer::Compare(a, c);
	Racer::Compare(b, c);
	return 0;
}