#ifndef VECTR_H
#define VECTR_H

#include <iostream>
using namespace std;

template <class T>
class vector
{
private:
	int m_size;
	int *m_a;

public:
	vector();
	vector(int n, T element);
	vector(int n, T *a);
	vector(const vector<T> &v);
	void print();
	~vector();
};

template <class T>
vector<T>::vector()
{
	this->m_size = 0;
	this->m_a = 0;
}

template <class T>
vector<T>::~vector()
{
	delete[] this->m_a;
}

template <class T>
vector<T>::vector(int n, T element)
{
	this->m_size = n;
	this->m_a = new T[n];
	for (int i = 0; i < this->m_size; ++i)
		this->m_a[i] = element;
}

template <class T>
vector<T>::vector(int n, T *a)
{
	this->m_size = n;
	this->m_a = new T[n];
	for (int i = 0; i < this->m_size; ++i)
		this->m_a[i] = a[i];
}

template <class T>
vector<T>::vector(const vector<T> &v)
{
	this->m_size = v.m_size;
	this->m_a = new T[v.m_size];
	for (int i = 0; i < this->m_size; ++i)
		this->m_a[i] = v.m_a[i];
}
template <class T>
void vector<T>::print()
{
	for (int i = 0; i < this->m_size; ++i)
		cout << this->m_a[i] << " ";
	cout << "\n";
}

#endif