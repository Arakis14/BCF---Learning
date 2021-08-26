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
}

