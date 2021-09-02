#include "Matrix.h"

Matrix::Matrix(int m_rowsize, int m_colsize)
	: ptr (new int[m_rowsize * m_colsize]), rowsize(m_rowsize), colsize(m_colsize)
{

}

int& Matrix::elementAt(int x, int y)
{
	try
	{
		return ptr[((x-1) * std::max(rowsize, colsize) + y) - 1];
	}
	catch (const std::exception& e)
	{
		e.what();
	}
}

void Matrix::fill()
{
	for (int i = 0; i < rowsize * colsize; i++)
	{
		ptr[i] = rand() % 10;
		//Debug
		//std::cout << ptr[i] << " ";
	}
}

void Matrix::show()
{
	for (int i = 0; i < rowsize * colsize; i++)
	{
		std::cout << ptr[i] << " ";
		if ((i+1) % std::max(rowsize, colsize) == 0 && i != 0)
			std::cout << std::endl;
	}
	std::cout << std::endl;
}

Matrix Matrix::operator+(const Matrix& rhs) const
{	
	Matrix result(rowsize, colsize);
	if (rowsize != rhs.rowsize || colsize != rhs.colsize) {
		throw std::invalid_argument("Matrices shapes mismatch");
		return result;
	}
	for (int i = 0; i < rowsize * colsize; i++) {
		result.ptr[i] = this->ptr[i] + rhs.ptr[i];
	}
	return result;
	
}

Matrix& Matrix::operator+=(const Matrix& rhs)
{	
	if (rowsize != rhs.rowsize || colsize != rhs.colsize) {
		throw std::invalid_argument("Matrices shapes mismatch");
		return *this;
	}
	for (int i = 0; i < rowsize * colsize; i++) {
		this->ptr[i] = this->ptr[i] + rhs.ptr[i];
	}
	return *this;
	
}

Matrix Matrix::operator-(const Matrix& rhs) const
{
	Matrix result(rowsize, colsize);
	if (rowsize != rhs.rowsize || colsize != rhs.colsize) {
		throw std::invalid_argument("Matrices shapes mismatch");
		return result;
	}
	for (int i = 0; i < rowsize * colsize; i++) {
		result.ptr[i] = this->ptr[i] - rhs.ptr[i];
	}
	return result;
}

