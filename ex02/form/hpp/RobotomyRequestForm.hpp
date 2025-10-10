#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include <iostream>
#include "../hpp/AForm.hpp"
class Bureaucrat;

class RobotomyRequestForm : public AForm
{

private:
    std::string target;
    RobotomyRequestForm();

public:
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &rRequestForm);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &rRequestForm);
    ~RobotomyRequestForm();

    std::string const &getTarget() const;

    virtual void executeAction() const;
};

#endif