#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include <climits>

int main()
{
	try
	{
		std::cout << "----Add Range Test----"<< std::endl;
		Span sp(5);

		std::vector<int> values;
		values.push_back(6);
		values.push_back(3);
		values.push_back(17);
		values.push_back(9);
		values.push_back(11);

		sp.addRange(values.begin(), values.end());
		std::cout << "Span: ";
		sp.printElements();
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span : " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "\n----Large Number Test----" << std::endl;
		Span bigSpan(10000);
		std::srand(std::time(NULL));

		std::list<int>l;
		for (int i = 0; i < 10000; i++)
			l.push_back(std::rand());

		bigSpan.addRange(l.begin(), l.end());
		std::cout << "Shortest Span: " << bigSpan.shortestSpan() << std::endl;
		std::cout << "Longest Span : " << bigSpan.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "\n----Exceed Span Size----" << std::endl;
		Span sp2(1);
		std::vector<int> nums;
		nums.push_back(1);
		nums.push_back(2);
		sp2.addRange(nums.begin(), nums.end());
	}
	catch (std::exception &e)
	{
		std::cerr << "Caught Exception: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "\n---- Less than 2 Numbers----" << std::endl;
		Span sp3(1);
		sp3.addNumber(1);
		std::cout << sp3.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Caught Exception: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "\n----Negative Numbers----" << std::endl;
		Span sp4(5);
		int arr[] = {-10, -3, 0, 7, 20};
		sp4.addRange(arr, arr + 5);
		sp4.printElements();
		std::cout << "Shortest Span: " << sp4.shortestSpan() << std::endl;
		std::cout << "Longest Span : " << sp4.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Caught Exception: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "\n----Duplicate Numbers----" << std::endl;
		Span sp5(4);
		sp5.addNumber(42);
		sp5.addNumber(42);
		sp5.addNumber(42);
		sp5.addNumber(100);
		sp5.printElements();
		std::cout << "Shortest Span: " << sp5.shortestSpan() << std::endl; // expect 0
		std::cout << "Longest Span : " << sp5.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Caught Exception: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "\n----INT_MIN/INT_MAX----" << std::endl;
		Span sp6(3);
		sp6.addNumber(INT_MIN);
		sp6.addNumber(0);
		sp6.addNumber(INT_MAX);
		sp6.printElements();
		std::cout << "Shortest Span: " << sp6.shortestSpan() << std::endl;
		std::cout << "Longest Span : " << sp6.longestSpan() << std::endl; // expect INT_MAX - INT_MIN
	}
	catch (std::exception &e)
	{
		std::cerr << "Caught Exception: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "\n----Copy Constructor & Assignment----" << std::endl;
		Span sp7(3);
		sp7.addNumber(5);
		sp7.addNumber(10);
		sp7.addNumber(20);

		Span sp8(sp7);
		Span sp9(1);
		sp9 = sp7; 

		std::cout << "Original: ";
		sp7.printElements();
		std::cout << "Copy (constructor): ";
		sp8.printElements();
		std::cout << "Copy (assign): ";
		sp9.printElements();
	}
	catch (std::exception &e)
	{
		std::cerr << "Caught Exception: " << e.what() << std::endl;
	}
	return (0);
}
