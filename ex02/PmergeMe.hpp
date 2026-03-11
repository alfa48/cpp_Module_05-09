#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include<ctime>
#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <sstream>
#include <ctime>


class PmergeMe
{
    private:
        std::vector<int> vec;
        std::deque<int> deq;

        void sortVector();
        void sortDeque();

        void printBefore() const;
        void printAfter() const;
        
        public:
        PmergeMe();
        void run(const std::string &str);
        void parseInputVec(const std::string &str);
        void parseInputDeq(const std::string &str);
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        void process();
};

#endif