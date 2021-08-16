#include <iostream>
#include <Matrix.h>

int main()
{
	std::cout << "Test" << std::endl;
	std::vector<std::vector<int>> vec = {
	{ 1, 2, 3 },
	{ 4, 5, 6 },
	{ 7, 8, 9 } };
	Matrix *m1 = new Matrix(3, 3, vec);
	delete m1;
};
