#include <iostream>
#include <iterator>
#include <string>
#include "Matrix.h"


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

void printHello()
{
	std::cout << "Welcome to my simple program for creating matrixes and performing simple arithmetic operations on them." << std::endl;
}

void showMenu()
{
	std::cout << "What would you like to do?" << std::endl;
	std::cout << "C - Create a matrix" << std::endl;
	std::cout << "F - Fill the matrix with values" << std::endl;
	std::cout << "P - Print the matrix" << std::endl;
	std::cout << "A - Add values by a number" << std::endl;
	std::cout << "S - Substract values by a number" << std::endl;
	std::cout << "M - Multiply values by a number" << std::endl;
	std::cout << "V - Save matrix to a file" << std::endl;
	std::cout << "Q - Quit the program" << std::endl;
}

int main()
{
	srand(time(NULL));
	printHello();
	char input;
	int rows, columns, number;
	Matrix m(10,10);
	do {
		showMenu();
		std::cin >> input;
		if (toupper(input) == 'C')
		{
			std::cout << "Please state the number of rows." << std::endl;
			std::cin >> rows;
			std::cout << "Please state the number of columns." << std::endl;
			std::cin >> columns;
			if (columns <= 10 || rows <= 10)
			{
				m.setColSize(columns);
				m.setRowSize(rows);
			}
			else 
				std::cout << "Size too big for this program!" << std::endl;


		}
		else if (toupper(input) == 'F')
		{
			std::cout << "\nMatrix filled with random values." << std::endl;
			m.fill();
		}
		else if (toupper(input) == 'P')
		{
			std::cout << "\nMatrix values:" << std::endl;
			m.show();
		}
		else if (toupper(input) == 'A')
		{
			std::cout << "Add values by: " << std::endl;
			std::cin >> number;
			m += number;
			std::cout << "Done! " << std::endl;
		}
		else if (toupper(input) == 'S')
		{
			std::cout << "Substract values by: " << std::endl;
			std::cin >> number;
			m = m - number;
			std::cout << "Done! " << std::endl;
		}
		else if (toupper(input) == 'M')
		{
			std::cout << "Multiply values by: " << std::endl;
			std::cin >> number;
			m = m * number;
			std::cout << "Done! " << std::endl;
		}
		else if (toupper(input) == 'V')
		{
			m.save();
			std::cout << "Matrix saved!" << std::endl;
		}
		else if (toupper(input) == 'Q')
		{
			std::cout << "Goodbye!" << std::endl;
		}
		else
			std::cout << "Invalid button!" << std::endl;
	}
	while (toupper(input) != 'Q');
};
