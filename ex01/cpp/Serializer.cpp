#include "./../hpp/Serializer.hpp"

Serializer::Serializer() {std::cout << "Serializer created" << std::endl;}
Serializer::~Serializer() {std::cout << "Serializer destroyed" << std::endl;}
Serializer::Serializer(const Serializer &) {}
Serializer &Serializer::operator=(const Serializer &) { return *this; }

uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}