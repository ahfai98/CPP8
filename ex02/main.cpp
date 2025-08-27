#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	std::cout << "----Test for MutantStack (non-const)----" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(6);

	std::cout << "Top: " << mstack.top() << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl;
	mstack.pop();
	std::cout << "After pop, Top: " << mstack.top() << std::endl;
	std::cout << "After pop, Size: " << mstack.size() << std::endl;

	for (int i = 0; i < 10; i++)
		mstack.push(i);

	std::cout << "Print Elements with iterator: " << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << "Print Elements with reverse iterator: " << std::endl;
	for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
		std::cout << *it << std::endl;

	// -------------------------------
	std::cout << "----Test for MutantStack (const)----" << std::endl;
	const MutantStack<int> constMstack = mstack;

	std::cout << "Print Elements with const_iterator: " << std::endl;
	for (MutantStack<int>::const_iterator it = constMstack.begin(); it != constMstack.end(); ++it)
	{
		//*it += 1; //error here
		std::cout << *it << std::endl;
	}

	std::cout << "Print Elements with const_reverse_iterator: " << std::endl;
	for (MutantStack<int>::const_reverse_iterator rit = constMstack.rbegin(); rit != constMstack.rend(); ++rit)
		std::cout << *rit << std::endl;

	// -------------------------------
	std::cout << "----Test for std::list (const and non-const)----" << std::endl;
	std::list<int> lst;
	for (int i = 0; i < 5; i++)
		lst.push_back(i);

	const std::list<int>& constLst = lst;

	std::cout << "Non-const list iteration:" << std::endl;
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		*it += 1, std::cout << *it << std::endl; // can modify values

	std::cout << "Const list iteration:" << std::endl;
	for (std::list<int>::const_iterator it = constLst.begin(); it != constLst.end(); ++it)
		std::cout << *it << std::endl; // read-only

	return 0;
}
