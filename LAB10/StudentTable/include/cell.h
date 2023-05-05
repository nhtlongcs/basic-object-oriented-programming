#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <string>
#include "base.h"


using namespace std;

enum Alignment {
    Left, Right
};

class Cell : public Object {
private:
    string value;
    int width;
    Alignment alignment;
public:
    Cell(string value, int width, Alignment alignment) {
        this->value = value;
        this->width = width;
        this->alignment = alignment;
    }
    Cell(string value, int width) {
        this->value = value;
        this->width = width;
        this->alignment = Alignment::Right;
    }

    string toString() {
        string cell = "";
        if (alignment == Alignment::Left) {
            cell += value;
            for (int i = 0; i < width - value.length(); i++) {
                cell += " ";
            }
        }
        if (alignment == Alignment::Right) {
            for (int i = 0; i < width - value.length(); i++) {
                cell += " ";
            }
            cell += value;
        }
        return cell;
    }
    void display() {
        std::cout << toString();
    }
    // big 3
    Cell() {
        (&Logger::getInstance())->debug("Cell constructor");
        this->value = "";
        this->width = 0;
        this->alignment = Alignment::Right;
    }
    Cell(const Cell& cell) {
        (&Logger::getInstance())->debug("Cell copy constructor");
        this->value = cell.value;
        this->width = cell.width;
        this->alignment = cell.alignment;
    }
    ~Cell() {
		(&Logger::getInstance())->debug("Cell destructor");

    }
};
#endif