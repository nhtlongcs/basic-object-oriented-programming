#include <iostream>
#include <string>
#include <vector>
#include "logger.h"
#include "shop.h"

using namespace std;

void example()
{
    string product_path = "data/products.txt";
    string category_path = "data/categories.txt";
    Logger *e = &Logger::getInstance();
    e->debug();
    Shop shop = Shop(category_path, product_path);
    shop.run();
}
int main()
{
    example();
    return 0;
}