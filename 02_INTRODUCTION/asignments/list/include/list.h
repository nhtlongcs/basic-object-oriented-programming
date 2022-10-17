#ifndef LIST_H
#define LIST_H

class list
{
private:
	int m_size;
	int *m_a;

public:
	void readData();
	void writeData();
	int getSize();
	int getValueAt(int i);
	void assignAt(int i, int x);
	int Find(int x);
	void sortAscending();
	void sortDescending();
	void clear();
};

#endif