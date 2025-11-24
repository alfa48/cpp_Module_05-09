#include <iostream>
#include "./hpp/Serializer.hpp"

int main()
{
    Data data;
    data.id = 10;
    data.name = "alfa48";

    std::cout << "Ponteiro original:    " << &data << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serializado em uintptr:  " << raw << std::endl;

    Data* restored = Serializer::deserialize(raw);
    std::cout << "Deserializado em ponteiro:" << restored << std::endl;

    if (restored == &data)
        std::cout << "SUCCESS: ponteiros iguais" << std::endl;
    else
        std::cout << "ERROR: ponteiros diferentes" << std::endl;

    std::cout << "Restored->id:   " << restored->id << std::endl;
    std::cout << "Restored->name: " << restored->name << std::endl;

    return 0;
}
