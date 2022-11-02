#include <iostream>
#include <string>

template <class T>
class DynamicArray
{
private:
    T *_data;
    int _maxSize;
    int _currentSize;

public:
    DynamicArray()
    {
        _data = new T[1];
        _maxSize = 1;
        _currentSize = 0;
    }
    int size()
    {
        return _currentSize;
    }
    void push_back(T value)
    {
        if (_currentSize == _maxSize)
        {
            _maxSize *= 2;
            T *newData = new T[_maxSize];
            for (int i = 0; i < _currentSize; i++)
            {
                newData[i] = _data[i];
            }
            delete[] _data;
            _data = newData;
        }
        _data[_currentSize] = value;
        _currentSize++;
    }
    T operator[](int i)
    {
        return _data[i];
    }
};