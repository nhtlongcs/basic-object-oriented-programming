#include <iostream>
#include <vector>
#include "room.h"
#ifndef HOTEL_H
#define HOTEL_H

using namespace std;

class Hotel
{
private:
	vector<Room *> roomList;

public:
	void readData();
	double calcPrice();
	Hotel();
	~Hotel();
};

#endif