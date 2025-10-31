#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>

enum ScalarType
{
    TYPE_CHAR,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_UNKNOWN
};

class ScalarConverter
{

private:
    ScalarConverter(void);
    ScalarConverter(const ScalarConverter &sc);
    ScalarConverter &operator=(const ScalarConverter &sc);
    ~ScalarConverter(void);

    static ScalarType detectType(const std::string &literal);
    // handles
    static void handleChar(const std::string &literal);
    static void handleInt(const std::string &literal);
    static void handleFloat(const std::string &literal);
    static void handleDouble(const std::string &literal);

    class InvalidTypeException : public std::exception
    {
    public:
        virtual const char *what(void) const throw();
    };
    class OverflowException : public std::exception
    {
    public:
        virtual const char *what(void) const throw();
    };
    class ImpossibleconversionException : std::exception
    {
    public:
        virtual const char *what(void) const throw();
    };

public:
    static void (*handlers[])(const std::string &);
    static bool (*checkerType[])(const std::string &);
    static ScalarType types[];
    static void convert(const std::string &literal);
};

#endif