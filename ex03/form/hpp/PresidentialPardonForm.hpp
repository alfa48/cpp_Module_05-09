#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include <iostream>
#include "../hpp/AForm.hpp"
class Bureaucrat;

class PresidentialPardonForm : public AForm
{

private:
    std::string target;
    PresidentialPardonForm();

public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm &pPerdonForm);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &pPerdonForm);
    ~PresidentialPardonForm();

    std::string const &getTarget() const;

    virtual void executeAction() const;
};

#endif