#include <vector>
#include <list>
#include <iostream>
#include "Easyfind.hpp"

int main() {
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    std::list<int> l;
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);

    try {
        std::cout << easyfind(v, 12) << std::endl;   //vector
        std::cout << easyfind(l, 29) << std::endl;  //lista
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

