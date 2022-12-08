#include <iostream>
#ifndef ROOM_H
#define ROOM_H

using namespace std;

class Room
{
protected:
    double basePrice;
    int numberOfDays;

public:
    virtual void readData();
    virtual double calcPrice() = 0;
    Room();
    ~Room(){};
};
class RoomA : public Room
{
private:
    double servicePrice;

public:
    void readData();
    double calcPrice();
    RoomA();
    ~RoomA(){};
};

class RoomB : public Room
{
public:
    void readData();
    double calcPrice();
    RoomB();
    ~RoomB(){};
};

class RoomC : public Room
{
public:
    void readData();
    double calcPrice();
    RoomC();
    ~RoomC(){};
};

#endif