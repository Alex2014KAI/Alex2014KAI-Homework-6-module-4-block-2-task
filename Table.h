#pragma once
#include <iostream>

// #define QUESTION

class SizeTable {
public:
	int m_rowCount;
	int m_colCount;
	SizeTable(int rowCount, int colCount) : m_rowCount(rowCount), m_colCount(colCount) {};
};


#ifndef QUESTION
template <class T>
class Table
{
public:
	Table(int rows, int cols) : _rows(rows), _cols(cols)
	{
		_data = new T * [_rows];
		for (size_t i = 0; i < _rows; i++)
		{
			_data[i] = new T[_cols];
		}
	};
	~Table() {
		for (size_t i = 0; i < _rows; i++)
		{
			delete[] _data[i];
		}
		delete[] _data;
	};
	T* operator[](size_t row) {
		return _data[row];
	};
	const T* operator[](size_t row) const {
		return _data[row];
	};
	Table(const Table&) = delete;//запрещаем конструктор копирования
	Table& operator= (const Table&) = delete; //запрещаем оператор присваивания

	SizeTable Size() const {
		SizeTable sizeTable(_rows, _cols);  
		return sizeTable;
	}

private:
	T** _data;
	int _rows;
	int _cols;
};
#endif // !QUESTION



#ifdef QUESTION
template <class T>
class Table
{
public:
	Table(int rows, int cols);
	~Table();
	T* operator[](size_t row);
	const T* operator[](size_t row) const;
	Table(const Table&) = delete;//запрещаем конструктор копирования
	Table& operator= (const Table&) = delete; //запрещаем оператор присваивания

	SizeTable Size() const;
private:
	T** _data;
	int _rows;
	int _cols;
};
#endif // DEBUG






