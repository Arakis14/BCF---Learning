#include "Matrix.h"

Matrix::Matrix(int m_rowsize, int m_colsize)
	: ptr (new int[m_rowsize * m_colsize]), rowsize(m_rowsize), colsize(m_colsize)
{
	//debugg
	//std::cout << "Matrix " << this->getRowSize() << " by " << this->getColSize() << " created." << std::endl;
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

int Matrix::getRowSize()
{
	return this->rowsize;
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

void Matrix::save()
{
	std::fstream my_file;
	my_file.open("Matrix storage.txt", std::ios::out | std::ios::app);
	my_file << "\n";
	for (int i = 0; i < rowsize * colsize; i++) {
		my_file << ptr.get()[i] << " ";
		if ((i + 1) % std::max(rowsize, colsize) == 0 && i != 0)
			my_file << "\n";
	}
	my_file.close();
}

void Matrix::staticFill()
{
	for (int i = 0; i < rowsize * colsize; i++)
	{
		ptr[i] = 1;
	}
	this->show();
}


int Matrix::getColSize()
{
	return this->colsize;
}

void Matrix::setRowSize(int newRow)
{
	this->rowsize = newRow;
}

void Matrix::setColSize(int newCol)
{
	this->colsize = newCol;
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

Matrix Matrix::operator+(const int& rhs)
{
	Matrix result(this->rowsize, this->colsize);
	for (int i = 0; i < rowsize * colsize; i++) {
		result.ptr[i] = this->ptr[i] + rhs;
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

Matrix& Matrix::operator+=(const int& rhs)
{
	for (int i = 0; i < rowsize * colsize; i++) {
		this->ptr[i] = this->ptr[i] + rhs;
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

Matrix Matrix::operator-(const int& rhs)
{
	Matrix result(this->rowsize, this->colsize);
	for (int i = 0; i < rowsize * colsize; i++) {
		result.ptr[i] = this->ptr[i] - rhs;
	}
	return result;
}

Matrix Matrix::operator*(const int& rhs)
{
	Matrix result(this->rowsize, this->colsize);
	for (int i = 0; i < rowsize * colsize; i++) {
		result.ptr[i] = this->ptr[i] * rhs;
	}
	return result;
}

