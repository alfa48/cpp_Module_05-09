/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manandre <manandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:43:49 by manandre          #+#    #+#             */
/*   Updated: 2025/10/08 00:28:58 by manandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
// #include "Bureaucrat.hpp"
// causa erro de Dependencia circular
class Bureaucrat;

class AForm
{
private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;

public:
    AForm();
    AForm(std::string name, int gradeToSign, int gradeToExecute);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm();
    std::string const &getName(void) const;
    bool const &getIsSigned(void) const;
    int const &getGradeToSign(void) const;
    int const &getGradeToExecute(void) const;

    void beSigned(const Bureaucrat &brt);

    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw();
    };
    class FormIsNotSignedException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    virtual void executeAction() const = 0;
    virtual void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &o, const AForm &form);

#endif