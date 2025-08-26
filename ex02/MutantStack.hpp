#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <stack>
# include <deque>

template<typename T, typename Container = std::deque<T> >
class MutantStack:public std::stack<T, Container>
{
public:
	typedef typename Container::iterator iterator;
	typedef typename Container::reverse_iterator reverse_iterator;
	MutantStack()
	{
	};
	
	MutantStack(const MutantStack &src): std::stack<T, Container>(src)
	{
	};
	
	~MutantStack()
	{
	};
	
	MutantStack &operator=(const MutantStack &src)
	{
		std::stack<T, Container>::operator=(src);
		return (*this);
	};
	iterator begin()
	{
		return this->c.begin();
	};
	iterator end()
	{
		return this->c.end();
	};
	reverse_iterator rbegin()
	{
		return this->c.rbegin();
	};
	reverse_iterator rend()
	{
		return this->c.rend();
	};
};

#endif
