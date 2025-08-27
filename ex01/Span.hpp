#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <stdexcept>
# include <limits>
# include <algorithm>

class Span
{
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &src);
		~Span();
		Span &operator=(const Span &src);
		void addNumber(int num);
		long shortestSpan();
		long longestSpan();
		void printElements();

		template<typename Iter>
		void addRange(Iter begin, Iter end)
		{
			size_t distance = std::distance(begin ,end);
			if (_numbers.size() + distance > _maxSize)
				throw std::runtime_error("Adding this range will exceed Span's Max Size.");
			_numbers.insert(_numbers.end(), begin, end);
		};

	private:
		unsigned int _maxSize;
		std::vector<int> _numbers;
};

#endif
