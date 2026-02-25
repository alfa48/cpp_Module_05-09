#ifndef BITCOINGEXCHANGE_HPP
#define BITCOINGEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        ~BitcoinExchange();
        double getExchangeRate(const std::string& date) const;
        BitcoinExchange& operator=(const BitcoinExchange& other);
        void hendleExchangeRate(const std::string &file);



    private:
        void loadData(const std::string& file);
        
        std::map<std::string, double> exchangeRates;

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

        double strToDouble(const std::string& s);
};

#endif