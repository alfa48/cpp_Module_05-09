#include "../hpp/PresidentialPardonForm.hpp"
#include "../../Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("pPerdonForm_default", 25, 5),  target("target")
{
    std::cout << "PresidentialPardonForm Default Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
    std::cout << "PresidentialPardonForm Default Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &pPerdonForm) : AForm("PresidentialPardonForm", 25, 5), target(pPerdonForm.getTarget())
{
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "PresidentialPardonForm Deconstructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &srcForm)
{
    if (this != &srcForm){AForm::operator=(srcForm);}
    return (*this);
}

std::string const &PresidentialPardonForm::getTarget() const {return (this->target);}

void PresidentialPardonForm::executeAction() const
{
    std::cout << this->getTarget() << " foi perdoado por Zaphod Beeblebrox" << std::endl;
}