#pragma once
#include <memory>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <fstream>

class Matrix
{
protected:
	int rowsize;
	int colsize;
	std::unique_ptr<int[]> ptr;
public:
	Matrix(int m_rowsize, int m_colsize);
	int& elementAt(int x, int y);
	int getRowSize();
	int getColSize();
	void setRowSize(int newRow);
	void setColSize(int newCol);
	void show();
	void fill();
	void save();
	void staticFill(); //debugg
	Matrix operator+(const Matrix& m) const;
	Matrix operator+(const int& rhs);
	Matrix& operator+=(const Matrix& m);
	Matrix& operator+=(const int& rhs);
	Matrix operator-(const Matrix& m) const;
	Matrix operator-(const int& rhs);
	Matrix operator*(const int& rhs);
};

