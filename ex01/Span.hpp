#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>

class Span{
    private:
        unsigned int maxSize;
        unsigned int currentIndex;
        int *array;

        class IsAlreadyFullException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

    public:
        Span();
        Span(unsigned int n);
        void addNumber(int num);
        ~Span();
};

#endif