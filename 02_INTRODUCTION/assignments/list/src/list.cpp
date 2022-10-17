#include "list.h"
#include <iostream>
using namespace std;
void list::readData()
{
	cin >> this->m_size;
	this->m_a = new int[this->m_size];
	for (int i = 0; i < this->m_size; ++i)
		cin >> this->m_a[i];
};
void list::writeData()
{
	cout << this->m_size << "\n";
	for (int i = 0; i < this->m_size; ++i)
		cout << this->m_a[i] << " ";
	cout << "\n";
};
int list::getSize()
{
	return this->m_size;
};
int list::getValueAt(int i)
{
	return this->m_a[i];
};
void list::assignAt(int i, int x)
{
	this->m_a[i] = x;
};
int list::Find(int x)
{
	for (int i = 0; i < this->m_size; ++i)
		if (this->m_a[i] == x)
			return i;
	return -1;
};
void list::sortAscending()
{
	for (int i = 0; i < this->m_size - 1; ++i)
		for (int j = i + 1; j < this->m_size; ++j)
		{
			if (!(this->m_a[i] < this->m_a[j]))
			{
				int temp = this->m_a[i];
				this->m_a[i] = this->m_a[j];
				this->m_a[j] = temp;
			}
		}
};
void list::sortDescending()
{
	for (int i = 0; i < this->m_size - 1; ++i)
		for (int j = i + 1; j < this->m_size; ++j)
		{
			if (!(this->m_a[i] > this->m_a[j]))
			{
				int temp = this->m_a[i];
				this->m_a[i] = this->m_a[j];
				this->m_a[j] = temp;
			}
		}
};
void list::clear()
{
	delete[] this->m_a;
};
