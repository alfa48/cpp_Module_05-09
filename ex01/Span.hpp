#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <algorithm>
#include <limits>
#include<vector>
#include <iterator>


class Span{
   private:
        unsigned int n;
        std::vector<int> container;

        class IsAlreadyFullException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class InsufficientElementsException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

         class InvalidCapacityException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

    public:

    Span();
    Span(unsigned int n);
    Span(const Span& src);
    Span& operator=(const Span &rhs);
    ~Span();

    void addNumber(int n);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    template<typename Iter>
    void addRange(Iter begin, Iter end){
        size_t rangeSize = std::distance(begin, end);
        if (container.size() + rangeSize > n) {throw IsAlreadyFullException();}
        container.insert(container.end(), begin, end);
    }

};

#endif