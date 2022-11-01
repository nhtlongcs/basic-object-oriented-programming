#include <iostream>
#include <fstream>
#include <vector>
#include "point.h"
#include "error.h"
#include "logger.h"
#include "pgenerators.h"
#include "igenerators.h"
using namespace std;
// serialize to file
void serializeToFile()
{
    // Random point generator
    RandomIntegerGenerator *generator = RandomIntegerGenerator::getInstance();
    RandomPointGenerator *pgenerator = RandomPointGenerator::getInstance();
    vector<Point> points;
    int N = generator->next(5, 10);
    for (int i = 0; i < 10; i++)
    {
        points.push_back(pgenerator->next(100, 100));
    }
    // serialize to file
    ofstream myfile;
    myfile.open("points.txt");
    myfile << N << endl;

    for (int i = 0; i < points.size(); i++)
    {
        myfile << points[i].toString() << endl;
    }
    myfile.close();
}
int main()
{
    serializeToFile();
    return 0;
}