#include <iostream>
#include "./hpp/Serializer.hpp"

int main()
{
    Data data;
    data.id = 10;
    data.name = "Lucas";

    std::cout << "Original pointer:    " << &data << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized uintptr:  " << raw << std::endl;

    Data* restored = Serializer::deserialize(raw);
    std::cout << "Deserialized pointer:" << restored << std::endl;

    if (restored == &data)
        std::cout << "SUCCESS: pointers are equal" << std::endl;
    else
        std::cout << "ERROR: pointers differ!" << std::endl;

    // Check that data is intact
    std::cout << "Restored->id:   " << restored->id << std::endl;
    std::cout << "Restored->name: " << restored->name << std::endl;

    return 0;
}
