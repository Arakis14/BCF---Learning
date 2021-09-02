#include <iostream>
#include <iterator>
#include <Matrix.h>

/*
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
*/

int main()
{
	srand(time(NULL));
	Matrix m1(5, 5); 
	m1.fill();
	m1.show();
	//std::cout << m1.elementAt(2, 2) << std::endl;
	//std::cout << m1.elementAt(10, 10);
	Matrix m2(5, 5);
	m2.fill();
	m2.show();
	Matrix m3(5, 5);
	try {
		m3 = m2 + m1;
	}
	catch (std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
	}
	
	m3.show();
	try {
		m3 += m2;
	}
	catch (std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
	}
	m3.show();

	try {
		m3 = m2 - m1;
	}
	catch (std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
	}
	m3.show();
};
