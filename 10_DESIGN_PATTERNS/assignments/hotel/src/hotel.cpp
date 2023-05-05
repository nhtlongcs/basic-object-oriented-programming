#include "hotel.h"
Hotel::Hotel()
{
}

Hotel::~Hotel()
{
}
void Hotel::readData()
{
	int n;
	cout << "Enter number of rooms: ";
	cin >> n;
	roomList.resize(n);
	cout << "Enter room information: \n";
	for (int i = 0; i < roomList.size(); ++i)
	{
		cout << "Enter room information for room [" << i << "]: \n";
		cout << "Enter type of room (A,B,C): ";
		char c;
		cin >> c;
		if (c == 'A')
			roomList[i] = new RoomA();
		else if (c == 'B')
			roomList[i] = new RoomB();
		else
			roomList[i] = new RoomC();
		roomList[i]->readData();
		cout << "-----------\n";
	}
}
double Hotel::calcPrice()
{
	double Sum = 0;
	for (int i = 0; i < roomList.size(); ++i)
	{
		Sum += roomList[i]->calcPrice();
	}
	return Sum;
}