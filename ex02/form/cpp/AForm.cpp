/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manandre <manandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:55:44 by manandre          #+#    #+#             */
/*   Updated: 2025/10/08 00:29:55 by manandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hpp/AForm.hpp"
#include "../../Bureaucrat.hpp"

AForm::AForm() : name("defaultForm"),
                 isSigned(false),
                 gradeToSign(150),
                 gradeToExecute(150)
{
    std::cout << "Form " << this->name << " created" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : name(name),
                                                                      isSigned(false),
                                                                      gradeToSign(gradeToSign),
                                                                      gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
    std::cout << "Form " << this->name << " created" << std::endl;
}

AForm::~AForm() { std::cout << "Form destrutor called, " << this->getName() << std::endl; }

AForm::AForm(const AForm &form) : name(form.getName()),
                                  isSigned(form.isSigned),
                                  gradeToSign(form.getGradeToSign()),
                                  gradeToExecute(form.getGradeToExecute())
{
    std::cout << "Form copy constructor called, " << this->getName() << std::endl;
}

AForm &AForm::operator=(const AForm &form)
{
    if (this != &form)
    {
        this->isSigned = form.isSigned;
    }
    return (*this);
}

// getters and setters

std::string const &AForm::getName() const { return (this->name); }

bool const &AForm::getIsSigned() const { return (this->isSigned); }

int const &AForm::getGradeToExecute() const { return (this->gradeToExecute); }

int const &AForm::getGradeToSign() const { return (this->gradeToSign); }

// exceptions
const char *AForm::GradeTooHighException::what() const throw() { return ("Grade is too high"); }
const char *AForm::GradeTooLowException::what() const throw() { return ("Grade is too low"); }
const char *AForm::FormIsNotSignedException::what() const throw() { return ("form is not signed"); }

void AForm::beSigned(const Bureaucrat &brt)
{
    if (brt.getGrade() > this->getGradeToSign())
    {
        throw AForm::GradeTooLowException();
    }
    this->isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
    out << form.getName() << ", form, "
        << "grade to sign: " << form.getGradeToSign() << ", "
        << "grade to execute: " << form.getGradeToExecute() << ", "
        << "is signed: " << std::boolalpha << form.getIsSigned();
    return out;
}

void AForm::execute(Bureaucrat const &brt) const{
    if (!this->getIsSigned()) {AForm::FormIsNotSignedException();}
    if (brt.getGrade() > this->getGradeToExecute()) {AForm::GradeTooLowException();}
    executeAction();
}
