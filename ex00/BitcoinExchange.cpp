#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>


BitcoinExchange::BitcoinExchange() {loadData("data.csv");}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : exchangeRates(other.exchangeRates) {}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {exchangeRates = other.exchangeRates;}
    return *this;
}

double BitcoinExchange::getExchangeRate(const std::string& date) const{
    std::map<std::string, double>::const_iterator it = exchangeRates.find(date);
    if (it != exchangeRates.end()) {return it->second;}
    throw ExchangeRateNotFoundForDateException();
}

//Para cargar os dados do arquivo CSV, o método loadData lee o arquivo linha por linha
void BitcoinExchange::loadData(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {throw FileException();}
    std::string line;
    while (std::getline(file, line)) {
                 if (line.empty() || line.substr(0,4) == "date") continue;
        size_t commaPos = line.find(',');
        if (commaPos == std::string::npos){throw BadInputException();}
        std::string date = line.substr(0, commaPos);
        std::string rateStr = line.substr(commaPos + 1);
        double rate;
        try{rate = strToDouble(rateStr);}
        catch (const std::exception &e){throw BadInputException();}
        if (rate < 0){throw NotPossitiveNumberException();}
        if (rate > 2147483647){throw LargeNumberException();}
        exchangeRates[date] = rate;
    }
    file.close();
}

void BitcoinExchange::hendleExchangeRate(const std::string &file){
    std::ifstream inputFile(file.c_str());
    if (!inputFile.is_open()) {throw FileException();}
    std::string line;
    while (std::getline(inputFile, line)) {
        if (line.empty()) continue;
        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos){throw BadInputException();}
        std::string date = line.substr(0, pipePos);
        std::string valueStr = line.substr(pipePos + 1);
        double value;
        try{value = strToDouble(valueStr);}
        catch (const std::exception &e){throw BadInputException();}
        if (value < 0){std::cout << "Error: not a positive number." << std::endl; continue;}
        if (value > 2147483647){std::cerr << "Error: too large a number." << std::endl; continue;}
        double exchangeRate = getExchangeRate(date);
        std::cout << date << " => " << value << " = " << value * exchangeRate << std::endl;
    }
    inputFile.close();
}

const char *BitcoinExchange::ExchangeRateNotFoundForDateException::what() const throw(){
    return "Error: Exchange rate not found for the given date.";
}

const char *BitcoinExchange::FileException::what() const throw() {
    return "Error: could not open file.";
}

const char *BitcoinExchange::NotPossitiveNumberException::what() const throw() {
    return "Error: not a positive number.";
}

const char *BitcoinExchange::BadInputException::what() const throw() {
    return "Error: bad input";
}

const char *BitcoinExchange::LargeNumberException::what() const throw(){
    return "Error: too large a number.";
}



double BitcoinExchange::strToDouble(const std::string& str) {
    std::stringstream ss(str);
    double value;
    ss >> value;
    if (ss.fail() || !ss.eof()) {
        throw BadInputException();
    }
    return value;
}