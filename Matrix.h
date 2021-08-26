#pragma once
#include <memory>
#include <ctime>
#include <iostream>
#include <algorithm>

class Matrix
{
protected:
	int rowsize;
	int colsize;
	std::unique_ptr<int[]> ptr;
public:
	Matrix(int m_rowsize, int m_colsize);
	int& elementAt(int x, int y);
	void show();
	void fill();
};

