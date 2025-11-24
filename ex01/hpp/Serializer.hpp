#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <string>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
private:
    Serializer(void);
    Serializer(const Serializer &src);
    Serializer &operator=(const Serializer &src);

public:
    ~Serializer();

    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);
};

#endif