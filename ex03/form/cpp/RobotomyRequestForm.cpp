#include "../hpp/RobotomyRequestForm.hpp"
#include "../../Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("rRequestForm_default", 72, 45),  target("target")
{
    std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
    std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &rRequestForm) : AForm("RobotomyRequestForm", 72, 45), target(rRequestForm.getTarget())
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "RobotomyRequestForm Deconstructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &srcForm)
{
    std::cout << "RobotomyRequestForm Assignation operator called" << std::endl;
    if (this != &srcForm){AForm::operator=(srcForm);}
    return (*this);
}

std::string const &RobotomyRequestForm::getTarget() const {return (this->target);}

void RobotomyRequestForm::executeAction() const
{
    std::cout << "BZZZZZ... KRRR... TCHAK-TCHAK... VRRRRR!" << std::endl;
    std::cout << this->getTarget() << " foi robotomizado com sucesso" << std::endl;
}