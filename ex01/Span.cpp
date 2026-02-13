#include "Span.hpp"

Span::Span():maxSize(1), currentIndex(0) {
    data = new int[1]();
}

Span::Span(unsigned int n): maxSize(n), currentIndex(0) {
    data = new int[n]();
}

void Span::addNumber(int num){
    if (currentIndex >= maxSize){throw IsAlreadyFullException();}
    data[currentIndex] = num;
    currentIndex++;
}

unsigned int Span::longestSpan() const{
    if (currentIndex < 2) throw InsufficientElementsException();
    int minValue = *std::min_element(data, data + currentIndex);
    int maxValue = *std::max_element(data, data + currentIndex);
    return (static_cast<unsigned int> (maxValue - minValue));
}

unsigned int Span::shortestSpan() const{
    if (currentIndex < 2) throw InsufficientElementsException();
    
    int *tmp = new int[currentIndex];
    for (unsigned int i = 0; i < currentIndex; i++){tmp[i] = data[i];}

    unsigned int mDiff = std::numeric_limits<unsigned int>::max();
    for (unsigned int i = 1; i < currentIndex; i++){
        unsigned int diff = static_cast<unsigned int>(tmp[i] - tmp[i - 1]);
        if (diff < mDiff) {mDiff = diff;}
    }

    delete[] tmp;
    return (mDiff);
}

Span::~Span(){
    delete[] data;
}

const char* Span::IsAlreadyFullException::what() const throw() {
    return "Span is already full";
}

const char* Span::InsufficientElementsException::what() const throw() {
    return "insufficient elements";
}