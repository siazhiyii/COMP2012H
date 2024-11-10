#include <iostream>

using namespace std;

template <typename T>
Column<T>::Column(std::string key, const T &default_value, int capacity)
{
    this->_key = key;
    this->default_value = default_value;
    this->_size = 0;
    this->capacity = capacity;
    this->data = new T[capacity];
}   

template <typename T>
Column<T> &Column<T>::operator=(const Column<T> &other)
{
    if (this == &other)
        return *this;
    delete[] data;
    this->_key = other._key;
    this->default_value = other.default_value;
    this->_size = other._size;
    this->capacity = other.capacity;
    this->data = new T[capacity];
    for (int i = 0; i < _size; i++)
    {
        this->data[i] = other.data[i];
    }
    return *this;
}

template <typename T>
Column<T>::Column(const Column &other)
{
    this->_key = other._key;
    this->default_value = other.default_value;
    this->_size = other._size;
    this->capacity = other.capacity;
    this->data = new T[capacity];
    for (int i = 0; i < _size; i++)
    {
        this->data[i] = other.data[i];
    }
}

template <typename T>
Column<T>::~Column()
{
    delete[] data;
}

template <typename T>
void Column<T>::addEntry(T field)
{
    if (_size == capacity)
    {
        T *new_data = new T[capacity * 2];
        for (int i = 0; i < _size; i++)
        {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity *= 2;
    }
    data[_size++] = field;
}

template <typename T>
void Column<T>::addDefault(int numOfEntry)
{
    for (int i = 0; i < numOfEntry; i++)
    {
        addEntry(default_value);
    }
}

template <typename T>
const T &Column<T>::operator[](int idx) const
{
    if (idx < -_size || idx >= _size)
    {
        throw out_of_range("Index out of range");
    }
    if (idx < 0)
    {
        idx += _size;
    }
    return data[idx];
}

template <typename T>
T &Column<T>::operator[](int idx)
{
    if (idx < -_size || idx >= _size)
    {
        throw out_of_range("Index out of range");
    }
    if (idx < 0)
    {
        idx += _size;
    }
    return data[idx];
}

template <typename T>
void Column<T>::removeEntry(int idx)
{
    if (idx < -_size || idx >= _size)
    {
        return;
    }
    if (idx < 0)
    {
        idx += _size;
    }
    for (int i = idx; i < _size - 1; i++)
    {
        data[i] = data[i + 1];
    }
    _size--;
}

template <typename T>
void Column<T>::updateEntry(int idx, const T &value)
{
    if (idx < -_size || idx >= _size)
    {
        return;
    }
    if (idx < 0)
    {
        idx += _size;
    }
    data[idx] = value;
}

template <typename T>
Column<T> Column<T>::concat(const Column<T> &other) const
{
    Column<T> newColumn(_key, default_value, _size + other._size);
    for (int i = 0; i < _size; i++)
    {
        newColumn.addEntry(data[i]);
    }
    for (int i = 0; i < other._size; i++)
    {
        newColumn.addEntry(other.data[i]);
    }
    return newColumn;
}

template <typename T>
Column<bool> Column<T>::operator==(const T &comp) const
{
    Column<bool> newColumn("Temp Column", false, _size);
    for (int i = 0; i < _size; i++)
    {
        newColumn.addEntry(data[i] == comp);
    }
    return newColumn;
}

template <typename T>
Column<bool> Column<T>::operator!=(const T &comp) const
{
    Column<bool> newColumn("Temp Column", false, _size);
    for (int i = 0; i < _size; i++)
    {
        newColumn.addEntry(data[i] != comp);
    }
    return newColumn;
}

template <typename T>
Column<bool> Column<T>::operator<(const T &comp) const
{
    Column<bool> newColumn("Temp Column", false, _size);
    for (int i = 0; i < _size; i++)
    {
        newColumn.addEntry(data[i] < comp);
    }
    return newColumn;
}

template <typename T>
Column<bool> Column<T>::operator<=(const T &comp) const
{
    Column<bool> newColumn("Temp Column", false, _size);
    for (int i = 0; i < _size; i++)
    {
        newColumn.addEntry(data[i] <= comp);
    }
    return newColumn;
}

template <typename T>
Column<bool> Column<T>::operator>(const T &comp) const
{
    Column<bool> newColumn("Temp Column", false, _size);
    for (int i = 0; i < _size; i++)
    {
        newColumn.addEntry(data[i] > comp);
    }
    return newColumn;
}

template <typename T>
Column<bool> Column<T>::operator>=(const T &comp) const
{
    Column<bool> newColumn("Temp Column", false, _size);
    for (int i = 0; i < _size; i++)
    {
        newColumn.addEntry(data[i] >= comp);
    }
    return newColumn;
}

template <typename T>
Column<bool> Column<T>::operator==(const Column<T> &other) const
{
    if (_size != other._size)
    {
        throw length_error("Different column size while doing indexing!");
    }
    Column<bool> newColumn("Temp Column", false, _size);
    for (int i = 0; i < _size; i++)
    {
        newColumn.addEntry(data[i] == other.data[i]);
    }
    return newColumn;
}

template <typename T>
Column<bool> Column<T>::operator!=(const Column<T> &other) const
{
    if (_size != other._size)
    {
        throw length_error("Different column size while doing indexing!");
    }
    Column<bool> newColumn("Temp Column", false, _size);
    for (int i = 0; i < _size; i++)
    {
        newColumn.addEntry(data[i] != other.data[i]);
    }
    return newColumn;
}

template <typename T>
Column<bool> Column<T>::operator<(const Column<T> &other) const
{
    if (_size != other._size)
    {
        throw length_error("Different column size while doing indexing!");
    }
    Column<bool> newColumn("Temp Column", false, _size);
    for (int i = 0; i < _size; i++)
    {
        newColumn.addEntry(data[i] < other.data[i]);
    }
    return newColumn;
}

template <typename T>
Column<bool> Column<T>::operator<=(const Column<T> &other) const
{
    if (_size != other._size)
    {
        throw length_error("Different column size while doing indexing!");
    }
    Column<bool> newColumn("Temp Column", false, _size);
    for (int i = 0; i < _size; i++)
    {
        newColumn.addEntry(data[i] <= other.data[i]);
    }
    return newColumn;
}

template <typename T>
Column<bool> Column<T>::operator>(const Column<T> &other) const
{
    if (_size != other._size)
    {
        throw length_error("Different column size while doing indexing!");
    }
    Column<bool> newColumn("Temp Column", false, _size);
    for (int i = 0; i < _size; i++)
    {
        newColumn.addEntry(data[i] > other.data[i]);
    }
    return newColumn;
}

template <typename T>
Column<bool> Column<T>::operator>=(const Column<T> &other) const
{
    if (_size != other._size)
    {
        throw length_error("Different column size while doing indexing!");
    }
    Column<bool> newColumn("Temp Column", false, _size);
    for (int i = 0; i < _size; i++)
    {
        newColumn.addEntry(data[i] >= other.data[i]);
    }
    return newColumn;
}

template <typename T>
Column<bool> Column<T>::operator||(const Column<T> &other) const
{
    if (_size != other._size)
    {
        throw length_error("Different column size while doing indexing!");
    }
    Column<bool> newColumn("Temp Column", false, _size);
    for (int i = 0; i < _size; i++)
    {
        newColumn.addEntry(data[i] || other.data[i]);
    }
    return newColumn;
}

template <typename T>
Column<bool> Column<T>::operator&&(const Column<T> &other) const
{
    if (_size != other._size)
    {
        throw length_error("Different column size while doing indexing!");
    }
    Column<bool> newColumn("Temp Column", false, _size);
    for (int i = 0; i < _size; i++)
    {
        newColumn.addEntry(data[i] && other.data[i]);
    }
    return newColumn;
}

template <typename T>
Column<bool> Column<T>::operator!() const
{
    Column<bool> newColumn("Temp Column", false, _size);
    for (int i = 0; i < _size; i++)
    {
        newColumn.addEntry(!data[i]);
    }
    return newColumn;
}

template <typename T>
Column<T> Column<T>::operator[](const Column<bool> &filter) const
{
    if (_size != filter.size())
    {
        throw length_error("Different column size while doing indexing!");
    }
    Column<T> newColumn(_key, default_value, _size);
    for (int i = 0; i < _size; i++)
    {
        if (filter[i])
        {
            newColumn.addEntry(data[i]);
        }
    }
    return newColumn;
}
