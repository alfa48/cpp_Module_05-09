#include <iostream>
#include "ScalarConverter.hpp"

int main()
{

    {
        ScalarConverter::convert("a");
        std::cout << "-----------------" << std::endl;
        ScalarConverter::convert("1");
        std::cout << "-----------------" << std::endl;
    }

    return 0;
}