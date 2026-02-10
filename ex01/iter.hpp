#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T, typename F>
void iter(T *array, const size_t size, F fun)
{
    if (!array){return ;}
    for (size_t i = 0; i < size; i++){fun(array[i]);}
}

#endif