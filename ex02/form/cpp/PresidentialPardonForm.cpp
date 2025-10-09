#include "../hpp/PresidentialPardonForm.hpp"
#include "../../Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("pPerdonForm_default", 25, 5)
{
    std::cout << "pPerdonForm " << this->getName() << " created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm(name, 25, 5)
{
    std::cout << "pPerdonForm_default " << this->getName() << " created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &pPerdonForm):  AForm(pPerdonForm){
    std::cout << "pPerdonForm copy constructor called, " << this->getName() << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &srcForm){
    if (this != &srcForm) {AForm::operator=(srcForm);}
    return (*this);
}

void PresidentialPardonForm::executeAction(Bureaucrat const &executor) const
{
    std::cout << executor.getName() <<" foi perdoado por Zaphod Beeblebrox" << std::endl;
}