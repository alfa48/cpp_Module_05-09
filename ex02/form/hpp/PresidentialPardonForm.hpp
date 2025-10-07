#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include <iostream>
#include "../hpp/AForm.hpp"
class Bureaucrat;

class PresidentialPardonForm : public AForm{

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string name);
        PresidentialPardonForm(const PresidentialPardonForm &pPerdonForm);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &pPerdonForm);
        virtual void executeAction() const;
};

#endif