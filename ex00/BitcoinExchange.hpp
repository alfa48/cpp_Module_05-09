/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manandre <948manuel@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:17:42 by manandre          #+#    #+#             */
/*   Updated: 2026/03/06 08:30:06 by manandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINGEXCHANGE_HPP
#define BITCOINGEXCHANGE_HPP

#include <map>
#include <string>

#include <iostream>
#include <algorithm>
#include <string>

struct IO {
    static void out(const std::string& msg) {std::cout << msg << std::endl;}
    static void err(const std::string& msg) {std::cerr << msg << std::endl;}
};

class BitcoinExchange {
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        ~BitcoinExchange();
        double getExchangeRateByDate(const std::string& date) const;
        BitcoinExchange& operator=(const BitcoinExchange& other);
        void hendleExchangeRate(const std::string &file);



    private:
        void loadData(const std::string& file);
        
        std::map<std::string, double> exchangeRatesByDate;

        class FileException : public std::exception {
            public:
                const char* what() const throw();
        };

        class NotPossitiveNumberException : public std::exception {
            public:
                const char *what() const throw();
        };

        class BadInputException : public std::exception {
            public:
                const char *what() const throw();
        };

        class ExchangeRateNotFoundForDateException : public std::exception {
            public:
                const char *what() const throw();
        };

        class LargeNumberException : public std::exception {
            public:
                const char *what() const throw();
        };

        static double strToDouble(const std::string& s);

        static bool validarDate(std::string& data);
        
        static void rmSpaces(std::string& s);
        
        static bool isLeapYear(int year);

        bool checkValue(double value);
};

#endif