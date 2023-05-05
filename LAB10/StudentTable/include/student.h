#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include <string>
#include "base.h"
#include "logger.h"
class Student : public Object {
private:
    string name;
    string phone;
    string address;
public:
    Student(string name, string phone, string address) {
        this->name = name;
        this->phone = phone;
        this->address = address;
    }
    Student(char* name, char* phone, char* address) {
        this->name = name;
        this->phone = phone;
        this->address = address;
        this->name = string(name);
        this->phone = string(phone);
        this->address = string(address);
    }
    string getName() {
        return name;
    }
    string getPhone() {
        return phone;
    }
    string getAddress() {
        return address;
    }
    string toString() {
        return name + " " + phone + " " + address;
    }
    // big 3
    Student() {
        (&Logger::getInstance())->debug("Student constructor");
        this->name = "";
        this->phone = "";
        this->address = "";
    }
    Student(const Student& student) {
        (&Logger::getInstance())->debug("Student copy constructor");
        this->name = student.name;
        this->phone = student.phone;
        this->address = student.address;
    }
    ~Student() {
		(&Logger::getInstance())->debug("Student destructor");
    }
};

#endif