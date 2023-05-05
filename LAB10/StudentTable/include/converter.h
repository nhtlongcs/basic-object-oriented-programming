#ifndef CONVERTER_H
#define CONVERTER_H

#include <memory>
#include <string>
#include <vector>
#include "base.h"
#include "student.h"
#include "logger.h"
using namespace std;

class IValueConverter: public Object { 
public:
    virtual Row convert(shared_ptr<Object>) = 0;
};

class StudentToRowConverter : public IValueConverter {
private:
    vector<int> widths;
public:
    StudentToRowConverter(vector<int> widths) {
        this->widths = widths;
    }
    string toString() {
        return "StudentToRowConverter";
    }
    Row convert(shared_ptr<Object> object) {
        shared_ptr<Student> student = dynamic_pointer_cast<Student>(object);
        string name = student->getName();
        string phone = student->getPhone();
        string address = student->getAddress();
        Row row(vector<string>{name, phone, address}, widths);
        return row;
    }
    // big 3
    StudentToRowConverter() {
        (&Logger::getInstance())->debug("StudentToRowConverter constructor");
        this->widths = vector<int>();
    }
    StudentToRowConverter(const StudentToRowConverter& converter) {
        (&Logger::getInstance())->debug("StudentToRowConverter copy constructor");
        this->widths = converter.widths;
    }
    ~StudentToRowConverter() {
		(&Logger::getInstance())->debug("StudentToRowConverter destructor");
    }
};

#endif