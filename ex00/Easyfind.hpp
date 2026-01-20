#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>



class NotFoundException : public std::exception{
    public:
            virtual const char *what() const throw(){
                return ("not found");
            }
};

template <typename T>
int easyfind(T &container, int target){
    typename T::iterator it;
    it = std::find(container.begin(), container.end(), target);
    if (it == container.end()){throw NotFoundException();}
    return (*it); //encontrado
}

#endif