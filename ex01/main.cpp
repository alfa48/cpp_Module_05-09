#include "Span.hpp"
#include <iostream>

    void testBase() {
        std::cout << "--- Teste Base ---" << std::endl;
        try {
            Span sp = Span(5);
            sp.addNumber(6);
            sp.addNumber(3);
            sp.addNumber(17);
            sp.addNumber(9);
            sp.addNumber(11);
            std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl; // R: 2
            std::cout << "longestSpan: "  << sp.longestSpan() << std::endl;  // R: 14
        } catch (std::exception &e) {
            std::cerr << "Erro inesperado: " << e.what() << std::endl;
        }
    }

    void testInsuficienteElements() {
        std::cout << "\n-- Teste (Um elemento) ---" << std::endl;
        try {
            Span sp = Span(5);
            sp.addNumber(10);
            std::cout << sp.longestSpan() << std::endl;
        } catch (std::exception &e) {
            std::cout << "error: " << e.what() << std::endl; // R: insufficient elements
        }
    }

    void testSpanFull() {
        std::cout << "\n--- Teste (Span is already full) ---" << std::endl;
        try {
            Span sp = Span(2);
            sp.addNumber(1);
            sp.addNumber(2);
            sp.addNumber(3); 
        } catch (std::exception &e) {
            std::cout << "error: " << e.what() << std::endl; // R: exception capturada
        }
    }


    void testGrandeQuantidade()
    {
        std::cout << "\n--- Teste (Grande Quantidade) ---\n";

        const int N = 20000;
        Span sp(N);

        std::vector<int> v;
        for (int i = 0; i < N; ++i)
            v.push_back(i * 2);

        sp.addRange(v.begin(), v.end());

        std::cout << "Shortest: " << sp.shortestSpan() << "\n"; // 2
        std::cout << "Longest : " << sp.longestSpan()  << "\n"; // 39998
    }
        

int main(void)
{
    testBase();
    testInsuficienteElements();
    testSpanFull();
    testGrandeQuantidade();

    return 0;
}