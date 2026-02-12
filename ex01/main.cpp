#include "Span.hpp"
#include <iostream>


int main(void)
{

    Span sp = Span(2);
    try{

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        //sp.addNumber(9);

    }catch(std::exception& ex){
        std::cout << ex.what() << std::endl;
    }
    //sp.addNumber(11);
   // std::cout << sp.shortestSpan() << std::endl;
    //std::cout << sp.longestSpan() << std::endl;
   
    return 0;
}