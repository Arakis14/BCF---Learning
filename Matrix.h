#pragma once
#include <vector>

class Matrix
{
protected:
	int rowsize;
	int colsize;
	std::vector<std::vector<int>> matrix;
public:
	Matrix(int m_rowsize, int m_colsize, std::vector<std::vector<int>> m_matrix);
};

