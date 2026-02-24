#ifndef BITCOINGEXCHANGE_HPP
#define BITCOINGEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        ~BitcoinExchange();
        void loadData(const std::string& filename);
        double getExchangeRate(const std::string& date) const;

    private:
        std::map<std::string, double> exchangeRates;

        class FileException : public std::exception {
            public:
                const char* what() const throw();
        };
};

#endif