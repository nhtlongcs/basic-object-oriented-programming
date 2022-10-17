#include "poly.h"

int main()
{
    Polynomial p1;
    p1.read();
    p1.print();
    Polynomial p2(p1);
    p2.print();
    return 0;
}