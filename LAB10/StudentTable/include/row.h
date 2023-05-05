#ifndef ROW_H
#define ROW_H

#include <vector>
#include <string>
#include <memory>
#include "cell.h"
#include "logger.h"
using namespace std;

class Row : public Object {
private:
    vector<string> values;
    vector<int> widths;
public:
    Row(vector<string> values, vector<int> widths) {
        this->values = values;
        this->widths = widths;
    }
    string toString() {
        string row = "|";
        for (int i = 0; i < values.size(); i++) {
            row += Cell(values[i], widths[i]).toString();
            row += "|";
        }
        return row;
    }
    void display() {
        cout << toString() << endl;
    }
    // big 3
    Row() {
        (&Logger::getInstance())->debug("Row constructor");
        this->values = vector<string>();
        this->widths = vector<int>();
    }
    Row(const Row& row) {
        (&Logger::getInstance())->debug("Row copy constructor");
        this->values = row.values;
        this->widths = row.widths;
    }
    ~Row() {
		(&Logger::getInstance())->debug("Row destructor");
    }
};

#endif