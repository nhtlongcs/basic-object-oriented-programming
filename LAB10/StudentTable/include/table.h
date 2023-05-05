#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <string>
#include <memory>
#include "base.h"
#include "row.h"
#include "converter.h"
#include "logger.h"
using namespace std;

class Table : public Object {
private:
    vector<string> headers;
    vector<int> widths;
    vector<shared_ptr<Object>> data;
    shared_ptr<IValueConverter> converter;
public:
    Table(vector<string> headers, vector<int> widths, vector<shared_ptr<Object>> data, shared_ptr<IValueConverter> converter) {
        this->headers = headers;
        this->widths = widths;
        this->data = data;
        this->converter = converter;
    }
    string toString(){
        return "Table";
    }
    void drawLine() {
        string line = "+";
        for (int i = 0; i < widths.size(); i++) {
            for (int j = 0; j < widths[i]; j++) {
                line += "-";
            }
            line += "+";
        }
        cout << line << endl;
    }
    void display() {
        drawLine();
        Row headerRow(headers, widths);
        headerRow.display();
        drawLine();
        for (int i = 0; i < data.size(); i++) {
            converter->convert(data[i]).display();
        }
        drawLine();
    }
    // big 3
    Table(){
        (&Logger::getInstance())->debug("Table constructor");
        this->headers = vector<string>();
        this->widths = vector<int>();
        this->data = vector<shared_ptr<Object>>();
        this->converter = shared_ptr<IValueConverter>();
    }
    Table(const Table &table){
        (&Logger::getInstance())->debug("Table copy constructor");
        this->headers = table.headers;
        this->widths = table.widths;
        this->data = table.data;
        this->converter = table.converter;
    }
    ~Table() {
        (&Logger::getInstance())->debug("Table destructor");
    }
};
#endif