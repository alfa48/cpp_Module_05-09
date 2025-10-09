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
#include <iostream>

int main(void)
{
    std::cout << "assinatura bem-sucedida" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    {
        Bureaucrat alice("Alice", 6);
        AForm *formA = new PresidentialPardonForm("FormA");
        std::cout << *formA << std::endl;
        std::cout << alice << std::endl;

        std::cout << (*formA).getIsSigned() << std::endl;

        alice.signForm(*formA);
        std::cout << *formA << std::endl;
        std::cout << (*formA).getIsSigned() << std::endl;
        formA->execute(alice);
    }

    return 0;
}