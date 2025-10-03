/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manandre <manandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:29:45 by manandre          #+#    #+#             */
/*   Updated: 2025/10/03 08:26:28 by manandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
    std::cout << "assinatura bem-sucedida" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    {
        Bureaucrat alice("Alice", 5);
        Form formA("FormA", 10, 3);
        std::cout << formA << std::endl;

        alice.signForm(formA);
        std::cout << formA << std::endl;
    }

    std::cout << "falha ao assinar (grade low)" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    
    {
        Bureaucrat bob("Bob", 50);
        Form formB("FormB", 10, 5);
        std::cout << formB << std::endl;

        bob.signForm(formB);
        std::cout << formB << std::endl;
    }

    std::cout << "tentativa de criar Form com grade invalida" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    
    {
        try
        {
            Form formC("FormC", 0, 5);
            std::cout << formC << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << "exception: " << e.what() << std::endl;
        }

        try
        {
            Form formD("FormD", 10, 151);
            std::cout << formD << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << "exception: " << e.what() << std::endl;
        }
    }

    std::cout << "\n===== TESTE 4: vários Bureaucrats tentando assinar o mesmo Form =====" << std::endl;
    {
        Form formE("FormE", 20, 10);
        Bureaucrat charlie("Charlie", 30); // grade insuficiente
        Bureaucrat diana("Diana", 15);     // grade suficiente

        charlie.signForm(formE); // deve falhar
        diana.signForm(formE);   // deve ter sucesso
        std::cout << formE << std::endl;
    }

    std::cout << "\n===== TESTE 5: assinar um Form já assinado =====" << std::endl;
    {
        Form formF("FormF", 25, 10);
        Bureaucrat eve("Eve", 10); // grade suficiente

        eve.signForm(formF); // primeira assinatura
        eve.signForm(formF); // segunda tentativa, já assinado
        std::cout << formF << std::endl;
    }

    return 0;
}