#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(6);
	std::cout << "Top: " << mstack.top() << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl;
	mstack.pop();
	std::cout << "After pop, Top: " << mstack.top() << std::endl;
	std::cout << "After pop, Top: " << mstack.size() << std::endl;

	for (int i = 0; i < 10; i++)
		mstack.push(i);
	std::cout << "Print Elements with iterator: " << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++)
	{
		std::cout << *it << std::endl;
	}
		std::cout << "Print Elements with reverse iterator: " << std::endl;
	for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); it++)
	{
		std::cout << *it << std::endl;
	}
	std::cout << "----Test for List----" << std::endl;
	std::list<int> lst;
	
	// Push elements (push_back for list)
	lst.push_back(5);
	lst.push_back(6);

	std::cout << "Last element (top): " << lst.back() << std::endl;
	std::cout << "Size: " << lst.size() << std::endl;

	// Pop last element
	lst.pop_back();
	std::cout << "After pop, Last element (top): " << lst.back() << std::endl;
	std::cout << "After pop, Size: " << lst.size() << std::endl;

	// Add more elements
	for (int i = 0; i < 10; i++)
		lst.push_back(i);

	// Forward iteration
	std::cout << "Print Elements with iterator: " << std::endl;
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
	{
		std::cout << *it << std::endl;
	}

	// Reverse iteration
	std::cout << "Print Elements with reverse iterator: " << std::endl;
	for (std::list<int>::reverse_iterator rit = lst.rbegin(); rit != lst.rend(); ++rit)
	{
		std::cout << *rit << std::endl;
	}
}
