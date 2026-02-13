#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <algorithm>
#include <limits>

class Span{
    private:
        unsigned int maxSize;
        unsigned int currentIndex;
        int *data;

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

    public:
        Span();
        Span(unsigned int n);
        void addNumber(int num);
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;
        ~Span();
};

#endif