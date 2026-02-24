#include "Span.hpp"

Span::Span(): n(1) {
    container.reserve(n);
}

Span::Span(unsigned int capacity) : n(capacity) {
    if (n == 0 || n > std::numeric_limits<unsigned int>::max()/2) {throw InvalidCapacityException();}
    container.reserve(n);
}

Span::Span(const Span& src) : n(src.n), container(src.container) {
    container.reserve(src.n);
}

Span& Span::operator=(const Span& rs) {
    if (this != &rs) {
        this->n = rs.n;
        this->container = rs.container; // O vector se auto-copia corretamente
    }
    return *this;
}

unsigned int Span::longestSpan() const{
    if (this->container.size() < 2) throw InsufficientElementsException();
    int minValue = *std::min_element(container.begin(), container.end());
    int maxValue = *std::max_element(container.begin(), container.end());
    return (static_cast<unsigned int> (maxValue - minValue));
}

unsigned int Span::shortestSpan() const{
    if (this->container.size() < 2) throw InsufficientElementsException();

    std::vector<int> tmp(container);
    std::sort(tmp.begin(), tmp.end());
    unsigned int mDiff = std::numeric_limits<unsigned int>::max();
    for (size_t i = 1; i < tmp.size(); i++){
        unsigned int diff = static_cast<unsigned int>(
            static_cast<long long>(tmp[i]) - static_cast<long long>(tmp[i - 1]));
        if (diff < mDiff) {mDiff = diff;}
    }

    return (mDiff);
}

void Span::addNumber(int num) {
    if (container.size() >= n) {throw IsAlreadyFullException();}
    container.push_back(num);
}

const char* Span::IsAlreadyFullException::what() const throw() {
    return "Span is already full";
}

const char* Span::InsufficientElementsException::what() const throw() {
    return "insufficient elements";
}

const char* Span::InvalidCapacityException::what() const throw() {
    return "Invalid capacity";
}

Span::~Span(){}
