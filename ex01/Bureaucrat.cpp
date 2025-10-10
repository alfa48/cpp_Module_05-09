/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manandre <manandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 08:28:29 by manandre          #+#    #+#             */
/*   Updated: 2025/10/07 21:52:59 by manandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
    std::cout << "Bureaucrat default construtor called, " << this->getName() << " with grade " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name){
    this->grade = grade;
    if (grade < 1)throw Bureaucrat::GradeTooHighException();
    if (grade > 150) throw Bureaucrat::GradeTooLowException();
    std::cout << "Bureaucrat parameterized construtor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &brt) : name(brt.name)
{
    std::cout << "Bureaucrat copy constructor called, " << this->getName() << " with grade " << this->getGrade() << std::endl;
    *this = brt;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &brt)
{
    std::cout << "Bureaucrat Assignation operator called" << std::endl;
    if (this == &brt){return (*this);}
    this->grade = brt.getGrade();
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destrutor called, " << this->getName() << " with grade " << this->getGrade() << std::endl;
}

//    getters and setters
std::string const &Bureaucrat::getName(void) const { return (this->name); }
int const &Bureaucrat::getGrade(void) const { return (this->grade); }

//    insertion operator
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return (out);
}

// exceptions
const char *Bureaucrat::GradeTooHighException::what(void) const throw(){return ("Grade is too high");}

const char *Bureaucrat::GradeTooLowException::what(void) const throw(){return ("Grade is too low");}

//    methods
void Bureaucrat::lowerGrade(void)
{
    if (this->grade + 1 > 150){throw Bureaucrat::GradeTooLowException();}
    this->grade++;
}

void Bureaucrat::increaseGrade(void)
{
    if (this->grade - 1 < 1){throw Bureaucrat::GradeTooHighException();}
    this->grade--;
}

//sign form
void Bureaucrat::signForm(Form &form) const{
    try{
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl; 
    }catch(std::exception &e){
        std::cout << this->getName() << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
}