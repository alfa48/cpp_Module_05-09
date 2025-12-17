#include "Iter.hpp"
#include <iostream>


void to_upper(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
		{str[i] = std::tolower(str[i]);}
}

void imcrement(int &i){i += 1;}

void print(int const &x){std::cout << x << std::endl;}

int main(void)
{

    { // Test com arrays nao-const
        int arr[] = {1, 2 , 3, 4, 5};
        const size_t size = sizeof(arr) / sizeof(arr[0]);
        ::iter(arr, size, imcrement);
        for (size_t i = 0; i < size; i++){std::cout << arr[i] << " ";}
        std::cout << std::endl;

        std::string strArr[] = {"hello", "world", "this", "is", "iter"};
        const size_t size1 = sizeof(strArr) / sizeof(strArr[0]);
        ::iter(strArr, size1, to_upper);
        for (size_t i = 0; i < size1; i++){std::cout << strArr[i] << " ";}
        std::cout << std::endl;

       // return 0;
    }

    { // Test com arrays consts
        const int constArr[] = {10, 20, 30, 40, 50};
        const size_t size = sizeof(constArr) / sizeof(constArr[0]);
        ::iter(constArr, size, print);
        return 0;
    }


    return 0;
}