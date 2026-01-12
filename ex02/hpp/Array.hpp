#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &copy);
        ~Array();
        Array &operator=(const Array &copy);
        T &operator[](unsigned int index);
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

template <typename T>
Array<T>::Array()
{
    array = NULL;
    u_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
    array = new T[n];
    u_size = n;
}

template <typename T>
Array<T>::Array(const Array &copy)
{
    array = new T[copy.u_size];
    u_size = copy.u_size;
    for (unsigned int i = 0; i < size; i++)
        {array[i] = copy.array[i];}
}

template <typename T>
Array<T>::~Array()
{
    if (array)
        {delete[] array;}
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &copy)
{
    if (array)
        {delete[] array;}
    array = new T[copy.u_size];
    u_size = copy.u_size;
    for (unsigned int i = 0; i < u_size; i++)
        {array[i] = copy.array[i];}
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= u_size)
        {throw OutOfRangeException();}
    return array[index];
}

template<typename T>
unsigned int Array<T>::size() const {
	return u_size;
}

#endif