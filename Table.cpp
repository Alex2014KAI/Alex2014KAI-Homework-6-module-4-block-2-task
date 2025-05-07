#include "Table.h"


#ifdef QUESTION
template<class T>
Table<T>::Table(int rows, int cols) : _rows(rows), _cols(cols)
{
	_data = new T * [_rows];
	for (size_t i = 0; i < _cols; i++)
	{
		_data[i] = new T[_cols];
	}
}

template<class T>
Table<T>::~Table()
{
	for (size_t i = 0; i < _cols; i++)
	{
		delete[] _data[i];
	}
	delete[] _data;
}

template<class T>
T* Table<T>::operator[](size_t row)
{
	return _data[row];
}

template<class T>
const T* Table<T>::operator[](size_t row) const
{
	return _data[row];
}

template<class T>
SizeTable Table<T>::Size() const {
	SizeTable sizeTable(_rows, _cols);
	return sizeTable;
}
#endif
