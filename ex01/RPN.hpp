#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include <exception>

class RPN{

    private:
        std::stack<int> mStack;
        RPN();
        
        public:
            RPN(const std::string &expr);
            RPN(const RPN &rpn);
            RPN &operator=(const RPN &other);
            ~RPN();
            int operate(int a, int b, char oper);
            void handleExpr(const std::string &expr);
            bool isValidOperator(char oper);
        
};

#endif