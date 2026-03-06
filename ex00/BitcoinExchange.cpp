/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manandre <948manuel@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:17:38 by manandre          #+#    #+#             */
/*   Updated: 2026/03/06 08:36:27 by manandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cfloat>


BitcoinExchange::BitcoinExchange() {loadData("data.csv");}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : exchangeRatesByDate(other.exchangeRatesByDate) {}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {exchangeRatesByDate = other.exchangeRatesByDate;}
    return *this;
}

double BitcoinExchange::getExchangeRateByDate(const std::string& date) const{
    std::map<std::string, double>::const_iterator it = exchangeRatesByDate.find(date);
    if (it != exchangeRatesByDate.end()) {return it->second;}
    return (-1);
    //throw ExchangeRateNotFoundForDateException();
}

//Para cargar os dados do arquivo(db) CSV, o método loadData lee o arquivo linha por linha
void BitcoinExchange::loadData(const std::string& filename) {
    double rate;
    size_t commaPos;
    
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {throw FileException();}
    std::string line;
    while (std::getline(file, line)) {
                 if (line.empty() || line.substr(0,4) == "date") continue;
        commaPos = line.find(',');
        if (commaPos == std::string::npos){throw BadInputException();}
        std::string date = line.substr(0, commaPos);
        std::string rateStr = line.substr(commaPos + 1);
        if (!BitcoinExchange::validarDate(date)){BadInputException();}
        try{rate = strToDouble(rateStr);}
        catch (const std::exception &e){throw BadInputException();}
        if (rate < 0){throw NotPossitiveNumberException();}
        if (rate > DBL_MAX){throw LargeNumberException();}
        BitcoinExchange::rmSpaces(date);
        exchangeRatesByDate[date] = rate;
        //std::cout << line << std::endl;
    }
    file.close();
}

//Para cargar os dados do arquivo(input) CSV
void BitcoinExchange::hendleExchangeRate(const std::string &file){
    double value;
    double exchange;
    size_t pipePos;
    std::string line;
    std::string date;

    std::ifstream inputFile(file.c_str());
    if (!inputFile.is_open()) {throw FileException();}
    while (std::getline(inputFile, line)) {
        if (line.empty() || line.substr(0,4) == "date") {continue;}
        pipePos = line.find('|');
        date = line.substr(0, pipePos);
        if (pipePos == std::string::npos || !BitcoinExchange::validarDate(date)){IO::err("Error: bad input => "+line); continue;}
        exchange = getExchangeRateByDate(date);
        if (exchange < 0) {IO::err("Error: Exchange rate not found for the given date."); continue;}  
        
        try{value = BitcoinExchange::strToDouble(line.substr(pipePos + 1));}
        catch (const std::exception &e){throw BadInputException();}
        if (!checkValue(value)){continue;}
        std::stringstream ss;
        ss << date << " => " << value << " = " << value *   exchange;
        IO::out(ss.str());
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
    if (ss.fail() || !ss.eof()) {throw BadInputException();}
    return value;
}

void BitcoinExchange::rmSpaces(std::string& s)
{
    s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
}

bool BitcoinExchange::isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::validarDate(std::string& date) {
    BitcoinExchange::rmSpaces(date);
    
    if (date.size() != 10){return false;}//tamanho correto
    if (date[4] != '-' || date[7] != '-'){return false;}//verificar posições dos (-)

    //verificar se os outros caracteres são n
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) {continue;}
        if (!isdigit(date[i])){return false;}
    }

    int ano = atoi(date.substr(0,4).c_str());
    int mes = atoi(date.substr(5,2).c_str());
    int dia = atoi(date.substr(8,2).c_str());

    if (mes < 1 || mes > 12){return false;}
    int diasMes[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if (isLeapYear(ano)){diasMes[1] = 29;}
    if (dia < 1 || dia > diasMes[mes-1]){return false;}

    return true;
}

bool BitcoinExchange::checkValue(double value)
{
    if (value < 0)
    {
        IO::err("Error: not a positive number.");
        return false;
    }
    if (value > 1000)
    {
        IO::err("Error: too large a number.");
        return false;
    }
    return true;
}