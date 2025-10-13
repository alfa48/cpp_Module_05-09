#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>

class ScalarConverter
{

private:
public:
    ScalarConverter(void);
    ScalarConverter(const ScalarConverter &sc);
    ScalarConverter &operator=(const ScalarConverter &sc);
    ~ScalarConverter(void);

    static void convert();
};

#endif