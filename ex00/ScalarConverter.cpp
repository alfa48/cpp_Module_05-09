#include "ScalarConverter.hpp"
#include <cstdlib> // std::strtod, std::strtof, std::atoi
#include <cctype>  // std::isdigit, std::isprint
#include <limits>  // std::numeric_limits
#include <cmath>   // std::isnan, std::isinf
#include <iomanip> // std::fixed, std::setprecision
#include <climits>

static bool isChar(const std::string &str)
{
    return str.length() == 1 &&
           std::isprint(str[0]) &&
           !std::isdigit(str[0]);
}

static bool isInt(const std::string &str)
{
    if (str.empty()){return false;}
    std::size_t i = (str[0] == '+' || str[0] == '-') ? 1 : 0;
    if (i == str.length())
        return false;
    for (; i < str.length(); ++i)
        if (!std::isdigit(str[i]))
            return false;
    return true;
}

static bool isFloat(const std::string &str)
{
    if (str.empty()){return false;}

    // pseudo-literais
    if (str == "-inff" || str == "+inff" || str == "nanf")
        return true;

    std::size_t i = (str[0] == '+' || str[0] == '-') ? 1 : 0;
    bool dot = false;
    bool hasDigit = false;

    for (; i < str.length(); ++i)
    {
        if (std::isdigit(str[i])){hasDigit = true;}
        else if (str[i] == '.' && !dot) {dot = true;}
        else if (str[i] == 'f' && i == str.length() - 1) {return hasDigit;}
        else {return false;}
    }

    return false;
}

static bool isDouble(const std::string &str)
{
    if (str.empty()){return false;}

    // pseudo-literais de double
    if (str == "nan" || str == "+inf" || str == "-inf")
        return true;

    std::size_t i = (str[0] == '+' || str[0] == '-') ? 1 : 0;

    bool dot = false;
    bool hasDigit = false;

    for (; i < str.length(); ++i)
    {
        if (std::isdigit(str[i])){hasDigit = true;}
        else if (str[i] == '.' && !dot){dot = true;}
        else{return false;}
    }
    return hasDigit;
}


// Handlers
void ScalarConverter::handleChar(const std::string &literal)
{
    char value = literal[0];
    if (std::isprint(value))
        std::cout << "char: '" << value << "'" << std::endl;
    else
        std::cout << "char: Não exibível" << std::endl;

    std::cout << "int: " << static_cast<int>(value) << std::endl;
    std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

void ScalarConverter::handleInt(const std::string &literal)
{
    long value = std::strtol(literal.c_str(), NULL, 10);

    if (value < 0 || value > 127)
        std::cout << "char: impossível" << std::endl;
    else if (!std::isprint(static_cast<char>(value)))
        std::cout << "char: Não exibível" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

    if (value < INT_MIN || value > INT_MAX)
        std::cout << "int: impossível" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

void ScalarConverter::handleFloat(const std::string &literal)
{
    float value;

    // Pseudo-literais
    if (literal == "nanf")
        value = std::numeric_limits<float>::quiet_NaN();
    else if (literal == "+inff")
        value = std::numeric_limits<float>::infinity();
    else if (literal == "-inff")
        value = -std::numeric_limits<float>::infinity();
    else
        value = std::strtof(literal.c_str(), NULL);

    // char
    if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
        std::cout << "char: impossível" << std::endl;
    else if (!std::isprint(static_cast<char>(value)))
        std::cout << "char: Não exibível" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

    // int
    if (std::isnan(value) || std::isinf(value) ||
        value < static_cast<float>(INT_MIN) ||
        value > static_cast<float>(INT_MAX))
        std::cout << "int: impossível" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;

    // float
    if (std::isnan(value))
        std::cout << "float: nanf" << std::endl;
    else if (std::isinf(value))
        std::cout << "float: " << (value > 0 ? "+inff" : "-inff") << std::endl;
    else
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;

    // double
    if (std::isnan(value))
        std::cout << "double: nan" << std::endl;
    else if (std::isinf(value))
        std::cout << "double: " << (value > 0 ? "+inf" : "-inf") << std::endl;
    else
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
}

void ScalarConverter::handleDouble(const std::string &literal)
{
    double value;

    //Pseudo-literais
    if (literal == "nan")
        value = std::numeric_limits<double>::quiet_NaN();
    else if (literal == "+inf")
        value = std::numeric_limits<double>::infinity();
    else if (literal == "-inf")
        value = -std::numeric_limits<double>::infinity();
    else
        value = std::strtod(literal.c_str(), NULL);

    //char
    if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
        std::cout << "char: impossível" << std::endl;
    else if (!std::isprint(static_cast<char>(value)))
        std::cout << "char: Não exibível" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

    //int
    if (std::isnan(value) || std::isinf(value) ||
        value < static_cast<double>(INT_MIN) ||
        value > static_cast<double>(INT_MAX))
        std::cout << "int: impossível" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;

    //float
    if (std::isnan(value))
        std::cout << "float: nanf" << std::endl;
    else if (std::isinf(value))
        std::cout << "float: " << (value > 0 ? "+inff" : "-inff") << std::endl;
    else
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;

    //double
    if (std::isnan(value))
        std::cout << "double: nan" << std::endl;
    else if (std::isinf(value))
        std::cout << "double: " << (value > 0 ? "+inf" : "-inf") << std::endl;
    else
        std::cout << "double: " << value << std::endl;
}

void (*ScalarConverter::handlers[])(const std::string &) = {&ScalarConverter::handleChar, &ScalarConverter::handleInt, &ScalarConverter::handleFloat, &ScalarConverter::handleDouble};
ScalarType ScalarConverter::types[] = {TYPE_CHAR, TYPE_INT, TYPE_FLOAT, TYPE_DOUBLE};
bool (*ScalarConverter::checkerType[])(const std::string &) = {&isChar, &isInt, &isFloat, &isDouble};

const char *ScalarConverter::InvalidTypeException::what(void) const throw()
{
    return "Invalid literal type";
}

const char *ScalarConverter::ImpossibleconversionException::what(void) const throw()
{
    return "Imposible conversion literal type";
}

const char *ScalarConverter::OverflowException::what(void) const throw()
{
    return "Overflow during conversion";
}

ScalarType ScalarConverter::detectType(const std::string &literal)
{
    for (size_t i = 0; i < sizeof(types) / sizeof(ScalarType); ++i)
    {
        if (ScalarConverter::checkerType[i](literal))
            return ScalarConverter::types[i];
    }
    return TYPE_UNKNOWN;
}

void ScalarConverter::convert(const std::string &literal)
{
    ScalarType type = detectType(literal);
    if (type == TYPE_UNKNOWN)
        throw InvalidTypeException();
    for (size_t i = 0; i < sizeof(types) / sizeof(ScalarType); i++)
    {
        if (type == ScalarConverter::types[i])
            ScalarConverter::handlers[i](literal);
    }
}