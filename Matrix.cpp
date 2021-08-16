#include "Matrix.h"

Matrix::Matrix(int m_rowsize, int m_colsize, std::vector<std::vector<int>> m_matrix)
{
	rowsize = m_rowsize;
	colsize = m_colsize;
	matrix = m_matrix;
}
