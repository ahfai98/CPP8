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
	typedef typename Container::const_iterator const_iterator;
	typedef typename Container::const_reverse_iterator const_reverse_iterator;


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

	const_iterator begin() const
	{
		return this->c.begin();
	};
	const_iterator end() const
	{
		return this->c.end();
	};
	const_reverse_iterator rbegin() const
	{
		return this->c.rbegin();
	};
	const_reverse_iterator rend() const
	{
		return this->c.rend();
	};
};

#endif
