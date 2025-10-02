/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manandre <manandre@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-02 14:43:49 by manandre          #+#    #+#             */
/*   Updated: 2025-10-02 14:43:49 by manandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>

class Form
{
private:
    std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;

public:
    Form();
    Form(std::string name, int gradeToSign, int gradeToExecute);
    Form(const Form &other);
    Form &operator=(const Form &other);
    ~Form();
    std::string const &getName() const;
    bool const &getIsSigned() const;
    int const &getGradeToSign() const;
    int const &getGradeToExecute() const;

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
};

#endif