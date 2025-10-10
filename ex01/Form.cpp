/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manandre <manandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:55:44 by manandre          #+#    #+#             */
/*   Updated: 2025/10/07 22:17:24 by manandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("defaultForm"),
               isSigned(false),
               gradeToSign(150),
               gradeToExecute(150)
{
    std::cout << "Form " << this->name << " created" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : name(name),
                                                                    isSigned(false),
                                                                    gradeToSign(gradeToSign),
                                                                    gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
    std::cout << "Form " << this->name << " created" << std::endl;
}

Form::~Form(){std::cout << "Form destrutor called, " << this->getName() << std::endl;}

Form::Form(const Form &form) :  name(form.getName()),
                                isSigned(form.isSigned),
                                gradeToSign(form.getGradeToSign()),
                                gradeToExecute(form.getGradeToExecute())
{
    std::cout << "Form copy constructor called, " << this->getName() << std::endl;
}

Form &Form::operator=(const Form &form)
{
    std::cout << "Form Assignation operator called" << std::endl;
    if (this != &form){this->isSigned = form.isSigned;}
    return (*this);
}

//getters and setters

std::string const &Form::getName() const{return (this->name);}

bool const &Form::getIsSigned() const{return (this->isSigned);}

int const &Form::getGradeToExecute() const{return (this->gradeToExecute);}

int const &Form::getGradeToSign() const{return (this->gradeToSign);}

//exceptions
const char *Form::GradeTooHighException::what() const throw(){return("Grade is too high");}
const char *Form::GradeTooLowException::what() const throw(){return("Grade is too low");}

void Form::beSigned(const Bureaucrat &brt){
    if (brt.getGrade() > this->getGradeToSign()){throw Form::GradeTooLowException();}
    this->isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const Form &form){
    out << form.getName() << ", form, "
        << "grade to sign: " << form.getGradeToSign() << ", " 
        << "grade to execute: " << form.getGradeToExecute() << ", "
        << "is signed: " << std::boolalpha << form.getIsSigned();
    return out;
}

