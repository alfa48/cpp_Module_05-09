/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manandre <manandre@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-10 12:45:47 by manandre          #+#    #+#             */
/*   Updated: 2025-10-10 12:45:47 by manandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP
#include <iostream>

class AForm;

class Intern
{
private:
public:
    Intern(void);
    Intern(const Intern &intern);
    ~Intern();
    Intern &operator=(const Intern &srcIntern);
    AForm *makeForm(const std::string &nameForm, const std::string &tagetForm) const;
};

#endif