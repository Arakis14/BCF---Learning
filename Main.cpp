#include <iostream>
#include <iterator>
#include <Matrix.h>

void printMatrix(const std::vector<std::vector<int>>& x)
{
	for (int i = 0; i < x.size(); i++)
	{
		for (auto itr = x[i].begin(); itr != x[i].end(); itr++)
		{
			std::cout << *itr << " ";
		}
		std::cout << std::endl;
	}
};

int main()
{
	std::vector<std::vector<int>> vec = {
	{ 1, 2, 3 },
	{ 4, 5, 6 },
	{ 7, 8, 9 } };
	printMatrix(vec);
	Matrix *m1 = new Matrix(3, 3, vec);
	delete m1;
};
