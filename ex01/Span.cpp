#include "Span.hpp"

Span::Span():maxSize(1), currentIndex(0) {
    array = new int[1]();
}

Span::Span(unsigned int n): maxSize(n), currentIndex(0) {
    array = new int[n]();
}

void Span::addNumber(int num){
    if (currentIndex >= maxSize){throw OutOfRangeException();}
    array[currentIndex] = num;
    currentIndex++;
}

Span::~Span(){
    delete[] array;
}

const char* Span::OutOfRangeException::what() const throw() {
    return "Out of range";
}