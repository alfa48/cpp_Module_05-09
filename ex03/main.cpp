/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manandre <manandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:29:45 by manandre          #+#    #+#             */
/*   Updated: 2025/10/08 00:37:16 by manandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "form/hpp/AForm.hpp"
#include "form/hpp/PresidentialPardonForm.hpp"
#include "form/hpp/ShrubberyCreationForm.hpp"
#include "form/hpp/RobotomyRequestForm.hpp"

#include <iostream>

int main(void)
{
    std::cout << "===== ShrubberyCreationForm =====" << std::endl;
    {
        Bureaucrat low("Joao", 150);
        Bureaucrat mid("Maria", 140);
        Bureaucrat high("Ana", 1);
        AForm *form = new ShrubberyCreationForm("garden");

        std::cout << *form << std::endl;

        try { form->execute(high); }
        catch (std::exception &e) { std::cout << "Erro: " << e.what() << std::endl; }

        try { low.signForm(*form); }
        catch (std::exception &e) { std::cout << "Erro: " << e.what() << std::endl; }

        mid.signForm(*form);
        std::cout << "Assinado? " << form->getIsSigned() << std::endl;

        try { high.executeForm(*form); }
        catch (std::exception &e) { std::cout << "Erro: " << e.what() << std::endl; }

        delete form;
    }

    std::cout << "\n===== RobotomyRequestForm =====" << std::endl;
    {
        Bureaucrat tech("Bob", 50);
        Bureaucrat chief("Carlos", 1);
        AForm *form = new RobotomyRequestForm("Mando");

        std::cout << *form << std::endl;

        try { form->execute(tech); }
        catch (std::exception &e) { std::cout << "Erro: " << e.what() << std::endl; }

        tech.signForm(*form);
        std::cout << "Assinado? " << form->getIsSigned() << std::endl;

        try { chief.executeForm(*form); }
        catch (std::exception &e) { std::cout << "Erro: " << e.what() << std::endl; }

        delete form;
    }

    std::cout << "\n===== PresidentialPardonForm =====" << std::endl;
    {
        Bureaucrat intern("Lucas", 50);
        Bureaucrat president("Alice", 1);
        AForm *form = new PresidentialPardonForm("Manuel Andre");

        std::cout << *form << std::endl;

        try { intern.signForm(*form); }
        catch (std::exception &e) { std::cout << "Erro: " << e.what() << std::endl; }

        president.signForm(*form);
        std::cout << "Assinado? " << form->getIsSigned() << std::endl;

        try { intern.executeForm(*form); }
        catch (std::exception &e) { std::cout << "Erro: " << e.what() << std::endl; }

        try { president.executeForm(*form); }
        catch (std::exception &e) { std::cout << "Erro: " << e.what() << std::endl; }

        delete form;
    }

    return 0;
}