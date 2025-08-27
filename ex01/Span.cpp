#include "Span.hpp"
#include <iostream>

Span::Span():_maxSize(0)
{
}

Span::Span(unsigned int N):_maxSize(N)
{
}

Span::Span(const Span &src):_maxSize(src._maxSize), _numbers(src._numbers)
{
}

Span::~Span()
{
}

Span &Span::operator=(const Span &src)
{
	if (this != &src)
	{
		_maxSize = src._maxSize;
		_numbers = src._numbers;
	}
	return (*this);
}

void Span::addNumber(int num)
{
	if (_numbers.size() >= _maxSize)
		throw std::runtime_error("Span is already full.");
	_numbers.push_back(num);
}

long Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Less than 2 numbers, unable to find Span.");
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	long minSpan = static_cast<long>(sorted[1]) - static_cast<long>(sorted[0]);
	for (size_t i = 2; i < sorted.size(); i++)
		minSpan = std::min(minSpan, static_cast<long>(sorted[i]) - static_cast<long>(sorted[i - 1]));
	return (minSpan);
}

long Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Less than 2 numbers, unable to find Span.");
	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());
	return (static_cast<long>(max) - static_cast<long>(min));
}

void Span::printElements() const
{
	if (_numbers.empty())
	{
		std::cout << "Empty Span" << std::endl;
		return;
	}
	
	std::vector<int>::const_iterator it = _numbers.begin();
	std::cout << *it;
	it++;
	for (; it != _numbers.end(); it++)
		std::cout << ", " << *it;
	std::cout << std::endl;
}
