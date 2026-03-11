#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    vec = other.vec;
    deq = other.deq;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        vec = other.vec;
        deq = other.deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parseInputVec(const std::string &str)
{
    std::set<int> seen;
    std::stringstream ss(str);
    std::string token;

    while (ss >> token)
    {
        for (size_t i = 0; i < token.size(); i++)
        {
            if (!std::isdigit(token[i])){throw std::runtime_error("Error");}
        }

        //conversao manual para inteiro
        int n = 0;
        for (size_t i = 0; i < token.size(); i++){n = n * 10 + (token[i] - '0');}

        //checa duplicados
        if (!seen.insert(n).second)
        {
            throw std::runtime_error("Error: duplicate number");
        }

        vec.push_back(n);
    }
}

void PmergeMe::parseInputDeq(const std::string &str)
{
    std::set<int> seen;
    std::stringstream ss(str);
    std::string token;

    while (ss >> token)
    {
        for (size_t i = 0; i < token.size(); i++)
        {
            if (!std::isdigit(token[i])){throw std::runtime_error("Error");}
        }

        //conversao manual para inteiro
        int n = 0;
        for (size_t i = 0; i < token.size(); i++){n = n * 10 + (token[i] - '0');}

        //checa duplicados
        if (!seen.insert(n).second)
        {
            throw std::runtime_error("Error: duplicate number");
        }

        deq.push_back(n);
    }
}

void PmergeMe::printBefore() const
{
    std::cout << "Before: ";

    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";

    std::cout << std::endl;
}

void PmergeMe::printAfter() const
{
    std::cout << "After: ";

    for (size_t i = 0; i < deq.size(); i++)
        std::cout << deq[i] << " ";

    std::cout << std::endl;
}

void PmergeMe::run(const std::string &str)
{
    vec.clear();
    deq.clear();

    parseInputVec(str);
    printBefore();
    vec.clear();

    clock_t startVec = clock();
    parseInputVec(str);
    sortVector();
    clock_t endVec = clock();

    clock_t startDeq = clock();
    parseInputDeq(str);
    sortDeque();
    clock_t endDeq = clock();

    double vecTime = (double)(endVec - startVec) / CLOCKS_PER_SEC * 1e6;
    double deqTime = (double)(endDeq - startDeq) / CLOCKS_PER_SEC * 1e6;

    printAfter();

    std::cout << "Time to process a range of "
              << vec.size()
              << " elements with std::vector : "
              << vecTime << " us" << std::endl;

    std::cout << "Time to process a range of "
              << deq.size()
              << " elements with std::deque : "
              << deqTime << " us" << std::endl;
}

void PmergeMe::sortVector()
{
    if (vec.size() <= 1)
        return;

    std::vector<int> mainChain;
    std::vector<int> pending;

    // passpo 1 — criar pares
    for (size_t i = 0; i + 1 < vec.size(); i += 2)
    {
        int a = vec[i];
        int b = vec[i + 1];

        if (a > b){std::swap(a, b);}

        pending.push_back(a);
        mainChain.push_back(b);
    }

    if (vec.size() % 2 != 0){pending.push_back(vec.back());}

    //passo 2 — ordenar mainChain (insertion sort)
    for (size_t i = 1; i < mainChain.size(); i++)
    {
        int key = mainChain[i];
        int j = i - 1;

        while (j >= 0 && mainChain[j] > key)
        {
            mainChain[j + 1] = mainChain[j];
            j--;
        }
        mainChain[j + 1] = key;
    }

    //passo 3 — inserir pendentes com binary search
    for (size_t i = 0; i < pending.size(); i++)
    {
        int value = pending[i];

        size_t left = 0;
        size_t right = mainChain.size();

        while (left < right)
        {
            size_t mid = (left + right) / 2;

            if (mainChain[mid] < value){left = mid + 1;}
            else{right = mid;}
        }

        mainChain.insert(mainChain.begin() + left, value);
    }

    vec = mainChain;
}

void PmergeMe::sortDeque()
{
    if (deq.size() <= 1){return;}

    std::deque<int> mainChain;
    std::deque<int> pending;

    //passo 1 — criar pares
    for (size_t i = 0; i + 1 < deq.size(); i += 2)
    {
        int a = deq[i];
        int b = deq[i + 1];

        if (a > b){std::swap(a, b);}

        pending.push_back(a);
        mainChain.push_back(b);
    }

    if (deq.size() % 2 != 0){pending.push_back(deq.back());}

    // passo 2 — ordenar mainChain
    for (size_t i = 1; i < mainChain.size(); i++)
    {
        int key = mainChain[i];
        int j = i - 1;

        while (j >= 0 && mainChain[j] > key)
        {
            mainChain[j + 1] = mainChain[j];
            j--;
        }
        mainChain[j + 1] = key;
    }

    //passo 3 — binary insertion
    for (size_t i = 0; i < pending.size(); i++)
    {
        int value = pending[i];

        size_t left = 0;
        size_t right = mainChain.size();

        while (left < right)
        {
            size_t mid = (left + right) / 2;

            if (mainChain[mid] < value){left = mid + 1;}
            else{ right = mid;}
        }

        mainChain.insert(mainChain.begin() + left, value);
    }

    deq = mainChain;
}