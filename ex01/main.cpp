#include "Span.hpp"
#include <iostream>

int main(void)
{

    Span sp = Span(5);
    try{

        sp.addNumber(6);
        sp.addNumber(-10);
        sp.addNumber(12);
        sp.addNumber(0);
        sp.addNumber(10);



        //sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

    }catch(std::exception& ex){
        std::cout << "error: " << ex.what() << std::endl;
    }
   
    return 0;
}