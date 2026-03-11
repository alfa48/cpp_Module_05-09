#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include<ctime>

template <typename Container>
class PmergeMe
{
    private:
        Container container;
        time_t start;
        time_t end;
        
    public:
        typedef typename Container::value_type ValueType;
        typedef typename Container::iterador Iterator;
        typename Container::iterator begin();
        typename Container::iterator end();
        void sort_time();
        void sort();

        PmergeMe();
        PmergeMe(const std::string &av);
        ~PmergeMe();
};
#include "PmergeMe.tpp"

#endif