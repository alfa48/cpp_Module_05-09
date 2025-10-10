#include "Intern.hpp"
#include "./form/hpp/AForm.hpp"
#include "./form/hpp/PresidentialPardonForm.hpp"
#include "./form/hpp/RobotomyRequestForm.hpp"
#include "./form/hpp/ShrubberyCreationForm.hpp"

Intern::Intern()
{
    std::cout << "Intern contrutor called" << std::endl;
}

Intern::Intern(const Intern &srcIntern)
{
    std::cout << "Intern Copy Constructor called" << std::endl;
    *this = srcIntern;
}

Intern &Intern::operator=(const Intern &srcIntern)
{
    std::cout << "Intern Assignation operator called" << std::endl;
    if (this != &srcIntern)
    {
        return (*this);
    }
    return (*this);
}
Intern::~Intern()
{
    std::cout << "Intern destrutor called" << std::endl;
}

static AForm *makeRobotomyRequestForm(const std::string &target)
{
    return (new RobotomyRequestForm(target));
}
static AForm *makeShrubberyCreationForm(const std::string &target)
{
    return (new ShrubberyCreationForm(target));
}

static AForm *makePresidentialPardonForm(const std::string &target)
{
    return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string &nameForm, const std::string &targetForm) const
{
    AForm *(*makeForms[])(const std::string &) = {&makePresidentialPardonForm, &makeRobotomyRequestForm, &makeShrubberyCreationForm};
    std::string forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
    int size = sizeof(forms) / sizeof(forms[0]);
    for (int i = 0; i < size; i++)
    {
        if (nameForm == forms[i])
        {
            std::cout << "Intern cria " << nameForm << std::endl;
            return (makeForms[i](targetForm));
        }
    }

    std::cout << "Intern não pode criar o formulário " << nameForm << std::endl;
    return (NULL);
}