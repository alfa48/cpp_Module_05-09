#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include <iostream>
#include "../hpp/AForm.hpp"
class Bureaucrat;

class ShrubberyCreationForm : public AForm
{

private:
    std::string target;
    ShrubberyCreationForm();

public:
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm &sCreationForm);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &sCreationForm);
    ~ShrubberyCreationForm();

    std::string const &getTarget() const;

    virtual void executeAction() const;
};

#endif