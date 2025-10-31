#include "ScalarConverter.hpp"
#include <cstdlib>      // std::strtod, std::strtof, std::atoi
#include <cctype>       // std::isdigit, std::isprint
#include <limits>       // std::numeric_limits
#include <cmath>        // std::isnan, std::isinf
#include <iomanip>      // std::fixed, std::setprecision

static bool isChar(const std::string &str)
{
    return str.length() == 1 && !std::isdigit(str[0]);
}

static bool isInt(const std::string &s)
{
    size_t i = (s[0] == '+' || s[0] == '-') ? 1 : 0;
    if (i == s.length())
        return false;
    for (; i < s.length(); ++i)
        if (!std::isdigit(s[i]))
            return false;
    return true;
}

static bool isFloat(const std::string &str) {
    if (str == "-inff" || str == "+inff" || str == "nanf")
        return true;
    bool dot = false;
    size_t i = (str[0] == '+' || str[0] == '-') ? 1 : 0;
    for (; i < str.length(); ++i) {
        if (str[i] == '.' && !dot) dot = true;
        else if (str[i] == 'f' && i == str.length() - 1) return dot;
        else if (!std::isdigit(str[i])) return false;
    }
    return false;
}

// Handlers
void ScalarConverter::handleChar(const std::string &literal){
    char c = literal[0];
    std::cout << "char: '" << c << "'" << std::endl;
}

void ScalarConverter::handleInt(const std::string &literal){
    long l = std::strtol(literal.c_str(), NULL, 10);
    if (l < std::numeric_limits<int>::min() || l > std::numeric_limits<int>::max())
        throw OverflowException();
    int i = static_cast<int>(l);
    std::cout << "int: " << i << std::endl;
}

void ScalarConverter::handleFloat(const std::string &literal){
    float f = std::strtof(literal.c_str(), NULL);
    double d = static_cast<double>(f);
    int i = static_cast<int>(f);
    char c = static_cast<char>(i);

    // char
    if (std::isnan(f) || std::isinf(f) || i < 0 || i > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(c))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;

    // int
    if (std::isnan(f) || std::isinf(f) || f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;

    // float
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;

    // double
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}


void (*ScalarConverter::handlers[])(const std::string &) = {&ScalarConverter::handleChar, &ScalarConverter::handleInt, &ScalarConverter::handleFloat};
ScalarType ScalarConverter::types[] = {TYPE_CHAR, TYPE_INT, TYPE_FLOAT};
bool (*ScalarConverter::checkerType[])(const std::string &) = {&isChar, &isInt, &isFloat};


const char *ScalarConverter::InvalidTypeException::what(void) const throw(){
    return "Invalid literal type";
}

const char *ScalarConverter::ImpossibleconversionException::what(void) const throw(){
    return "Imposible conversion literal type";
}

const char *ScalarConverter::OverflowException::what(void) const throw(){
    return "Overflow during conversion";
}

ScalarType ScalarConverter::detectType(const std::string &literal)
{
    for (size_t i = 0; i < sizeof(types) / sizeof(ScalarType); ++i)
    {if (ScalarConverter::checkerType[i](literal)) return ScalarConverter::types[i];}
    return TYPE_UNKNOWN;
}

void ScalarConverter::convert(const std::string &literal){
    ScalarType type = detectType(literal);
    if (type == TYPE_UNKNOWN) throw InvalidTypeException();
    for (size_t i = 0; i < sizeof(types) / sizeof(ScalarType); i ++){
        if (type == ScalarConverter::types[i]) ScalarConverter::handlers[i](literal);
    }
}