#pragma once
#include <string.h>
#include <iostream>
using namespace std;
template <class T>
class Vector {
private:
	int _size;
	T* _a;
public:
	int size();
	void setSize(int size);
	T* a();
	void setA(T* a);
public:
	Vector();
	Vector(int size,  T* a);
	Vector(const Vector&);
	~Vector();

	Vector& operator = (const Vector&);
    operator T*();
	T& operator [] (const int& i);

	template <class D>
	friend ostream& operator << (ostream&, const Vector<D>& v);

	template <class D>
	friend istream& operator >> (istream&, Vector<D> &v);

};

template <class T>

int Vector<T>::size()
{
	return this->_size;
}

template <class T>
void Vector<T>::setSize(int size)
{
	this->_size = size;
}

template <class T>
T* Vector<T>::a()
{
	return this->_a;
}

template <class T>
void Vector<T>::setA(T* a)
{
	this->_a = a;
}

template <class T>
Vector<T>::Vector()
{
	this->_size = 0;
	this->_a = 0;
}

template <class T>
Vector<T>::Vector(int size,T* a)
{
	this->_size = size;
	cout << sizeof(T)*size << "  ";
	this->_a = (T*)(new char[sizeof(T)*size]);
	memcpy(this->_a, a, sizeof(T)*size);
}

template <class T>
Vector<T>::Vector(const Vector<T> &v) {
	this->_size = v._size;
	this->_a = (T*)(new char[sizeof(T)*v._size]);
	memcpy(this->_a, v._a, sizeof(T)*v._size);
}
template <class T>
Vector<T>::~Vector()
{
	//Code your destructor here! 
	delete[] this->_a;
}
template <class T>
Vector<T>& Vector<T>::operator = (const Vector<T>& v) {
	this->_size = v._size;
	delete [] this->_a;
	this->_a = (T*)(new char[sizeof(T)*v._size]);
	memcpy(this->_a, v._a, sizeof(T)*v._size);
	return (*this);
}


template <class T>
Vector<T>::operator T*() {
	return this->_a;
}


template <class T>
ostream& operator << (ostream& os, const Vector<T>& v)
{
	os << v._size << "\n";
	for (int i = 0; i < v._size; i++)
		os << v._a[i] << " ";
	os << "\n";
	return os;
}

template <class T>
istream& operator >> (istream& is, Vector<T> & v)
{
	is >> v._size;
	delete[] v._a;
	v._a = (T*)(new char[sizeof(T)*v._size]);
	for (int i = 0; i < v.size(); i++)
		is >> v.a()[i];
	return is;
}

template <class T>
T& Vector<T> :: operator [] (const int& i) {
	return this->_a[i];
}
