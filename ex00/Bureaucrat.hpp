/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manandre <manandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 08:28:45 by manandre          #+#    #+#             */
/*   Updated: 2025/09/30 08:46:34 by manandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

/*
Excetion é um mecanismo que permite tratar erros no programa
em execusão sem ter que interromper o programa
 */

#include <iostream>

class Bureaucrat
{

private:
    const std::string name;
    int grade; //(ranges 1-150, 1 highest grade)

public:
    Bureaucrat(void);
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &src);
    Bureaucrat &operator=(const Bureaucrat &src);
    ~Bureaucrat();

    std::string const &getName(void) const;
    int const &getGrade(void) const;

    void lowerGrade(void);
    void increaseGrade(void);

    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char *what(void) const throw();
    };

    class GradeTooLowException: public std::exception
    {
        public:
            virtual const char *what(void) const throw();
    };
};

std::ostream &operator<<(std::ostream &o, Bureaucrat &bureaucrat);

#endif