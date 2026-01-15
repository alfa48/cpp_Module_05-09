#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &src);
        ~Array();
        Array &operator=(const Array &src);
        T &operator[](unsigned int index);
        const T &operator[](unsigned int index) const;
        unsigned int size() const;

    private:
        T *array;
        unsigned int u_size;

        class OutOfRangeException : public std::exception
        {
            public:
                virtual const char *what() const throw(){return "Out of range";}
        };
};

#include "../cpp/Array.tpp"
#endif