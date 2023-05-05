#include <iostream>
#include "logger.h"
#include "product.h"
#include "dataset.h"
#include "generators.h"

void task1(){
    // Generate an integer n in the range of [5, 10]
    Logger *logger = &Logger::getInstance();
    logger->info("Task 1: Generate an integer n in the range of [5, 10]");
    int n = rand() % 6 + 5;
    logger->info("n = " + to_string(n));
}
vector<Product> task2(){
    // Generate n products and print out the list to the screen. Each product should have an id (string), a name (string), and a price (int).
    int n;
    Logger *logger = &Logger::getInstance();
    logger->info("Task 2: Generate n products and print out the list to the screen. Each product should have an id (string), a name (string), and a price (int).");
    cout << "Enter n: ";
    cin >> n;
    ProductGenerator pg;
    vector<Product> products;
    for (int i = 0; i < n; i++)
    {
        Product p = pg.next();
        products.push_back(p);
        cout << p.toString() << endl;
    }
    return products;

}
void task3(vector<Product> products_task2){
    // Save n products into n text files, each text file contains all the information of a product.
    // Theses text file should be put inside a folder named “**Product**”
    Logger *logger = &Logger::getInstance();
    logger->info("Task 3: Save n products into n text files, each text file contains all the information of a product. Theses text fileput inside a folder named “Product”");
    ProductDataset ds(products_task2);
    ds.exportFiles("Product");
    logger->info("Saved to folder Product");
}
void task4(){
    Logger *logger = &Logger::getInstance();
    // Read back all your stored products from text files and print out the list to the console
    logger->info("Task 4: Read back all your stored products from text files and print out the list to the console");
    ProductDataset ds("Product", ".txt");
    for (auto &p : ds.products)
    {
        cout << p.second.toString() << endl;
    }
}
int main() {
    // Logger::getInstance().debug();
    task1();
    vector<Product> res;
    res = task2();
    task3(res);
    task4();
    return 0;
}