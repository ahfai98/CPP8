#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <ctime>   // for clock()

int main()
{
	try
	{
		std::vector<int> v;
		for (int i = 0; i < 100000000; i++) // large vector
			v.push_back(i);

		std::clock_t start = std::clock();
		std::vector<int>::iterator it = easyfind(v, 99999999);
		std::clock_t end = std::clock();

		std::cout << "Found in vector: " << *it << std::endl;
		std::cout << "Vector search took: "
				  << double(end - start) / CLOCKS_PER_SEC
				  << " seconds" << std::endl;

		// Try not found case
		start = std::clock();
		it = easyfind(v, -1);
	}
	catch(std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		std::list<int> l;
		for (int i = 0; i < 100000000; i++) // large list
			l.push_back(i);

		std::clock_t start = std::clock();
		std::list<int>::iterator it = easyfind(l, 99999999);
		std::clock_t end = std::clock();

		std::cout << "Found in list: " << *it << std::endl;
		std::cout << "List search took: "
				  << double(end - start) / CLOCKS_PER_SEC
				  << " seconds" << std::endl;

		// Try not found case
		start = std::clock();
		it = easyfind(l, -1);
	}
	catch(std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return (0);
}
