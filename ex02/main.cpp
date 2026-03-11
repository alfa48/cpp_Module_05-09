#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error.." << std::endl;
        return 1;
    }
    std::string input;

    for (int i = 1; i < ac; i++)
    {
        input += av[i];
        if (i != ac - 1)
            input += " ";
    }
    try
    {
        PmergeMe sorter;
        sorter.run(input);
    }
    catch (std::exception &e)
    {
        std::cout << "Error" << std::endl;
    }
}
