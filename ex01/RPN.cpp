#include "RPN.hpp"

RPN::RPN(){};
RPN::RPN(const std::string &expr){handleExpr(expr);};

void RPN::handleExpr(const std::string &expr){
    std::stringstream ss(expr);
    std::string token;

    while(ss >> token){
        if (token.size() != 1){throw std::runtime_error("Error");}
        
        if (std::isdigit(token[0])){mStack.push(token[0] - '0'); continue;}
        if (!isValidOperator(token[0])){throw std::runtime_error("Error");}
        if (mStack.size() < 2){throw std::runtime_error("Error");}
        int b = mStack.top();
        mStack.pop();

        int a = mStack.top();
        mStack.pop();
        
        int rt = operate(a, b, token[0]);
        mStack.push(rt);
        
    }
    if (mStack.size() != 1){throw std::runtime_error("Error");}
    std::cout << mStack.top() << std::endl;

}

bool RPN::isValidOperator(char oper){
    return (oper == '+' || oper == '-' || oper == '*' || oper == '/');
}

int RPN::operate(int a, int b, char oper){
    switch (oper)
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0){throw std::runtime_error("Error");}
            return a / b;
        default: throw std::runtime_error("Error");
        }
}

RPN::RPN(const RPN &other) {*this = other;}

RPN &RPN::operator=(const RPN &other) {
    if (this != &other) {this->mStack = other.mStack;}
    return *this;
}

RPN::~RPN() {}