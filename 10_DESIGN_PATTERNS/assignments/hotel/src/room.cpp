#include "room.h"

Room::Room()
{
    basePrice = 0;
    numberOfDays = 0;
}

RoomA::RoomA() : Room()
{
    basePrice = 300;
    servicePrice = 0;
}

RoomB::RoomB() : Room()
{
    basePrice = 200;
}

RoomC::RoomC() : Room()
{
    basePrice = 100;
}

void Room::readData()
{
    cout << "Enter number of days: ";
    cin >> numberOfDays;
}

void RoomA::readData()
{
    Room::readData();
    cout << "Enter service price: ";
    cin >> servicePrice;
}

void RoomB::readData()
{
    Room::readData();
}

void RoomC::readData()
{
    Room::readData();
}

double RoomA::calcPrice()
{

    if (basePrice >= 10)
        return (9 * basePrice + (numberOfDays - 9) * 0.9 * basePrice) + servicePrice;
    else
        return numberOfDays * basePrice + servicePrice;
}

double RoomB::calcPrice()
{
    if (basePrice >= 10)
        return (9 * basePrice + (numberOfDays - 9) * 0.9 * basePrice);
    else
        return numberOfDays * basePrice;
}

double RoomC::calcPrice()
{
    return numberOfDays * basePrice;
}
