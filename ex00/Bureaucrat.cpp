/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manandre <manandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 08:28:29 by manandre          #+#    #+#             */
/*   Updated: 2025/09/30 08:28:31 by manandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("default"), grade(150){
    std::cout << "Bureaucrat default construtor called, " << this->getName() << "with grade " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &brt): name(brt.name){
    std::cout << "Bureaucrat copy constructor called, " << this->getName() << "with grade " << this->getGrade() << std::endl;
    *this = brt;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &brt){
    std::cout << "Bureaucrat assignment operator called, " << this->getName() << "with grade " << this->getGrade() << std::endl;
    if (this == &brt){return (*this);}
    this->grade = brt.getGrade();
    return (*this);
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat destrutor called, " << this->getName() << "with grade " << this->getGrade() << std::endl;
}


/*
    getters and setters 
*/

std::string Bureaucrat::getName() const{return (this->name);}
int Bureaucrat::getGrade() const{return (this->grade);}


/*
    insertion operator
*/
std::iostream &operator<<(std::iostream &out, Bureaucrat *bureaucrat){
    out << bureaucrat->getName() << ", bureaucrat grade" << bureaucrat->getGrade() << std::endl;
    return (out);
}
