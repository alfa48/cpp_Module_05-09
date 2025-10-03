/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manandre <manandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 08:28:53 by manandre          #+#    #+#             */
/*   Updated: 2025/10/03 06:15:51 by manandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << "Bloco con exception não tratada" << std::endl;
    std::cout << "---------------------------------" << std::endl;
      {
        Bureaucrat brt;
        std::cout << brt << std::endl;
        // std::terminate();
        // brt.lowerGrade();
        // std::cout << brt << std::endl;
    }

    std::cout << "Bloco com exception tratada grade low" << std::endl;
    std::cout << "---------------------------------" << std::endl;

    {
        Bureaucrat brt;
        std::cout << brt << std::endl;
        try
        {
            brt.lowerGrade();
            std::cout << brt << std::endl;
        }
        catch (std::exception &e)
        {
                std::cout << "exception: "<< e.what() << std::endl;
        }
    }

        std::cout << "Bloco com exception tratada grade high" << std::endl;
        std::cout << "---------------------------------" << std::endl;

        {
            Bureaucrat brt;
            std::cout << brt << std::endl;
            try
            {
                for (int i = 0; i < 151; i++)
                    brt.increaseGrade();
                std::cout << brt << std::endl;
            }
            catch (std::exception &e)
            {
                std::cout << "exception: "<< e.what() << std::endl;
            }
        }

        std::cout << "Bloco com exception tratada grade high na criação" << std::endl;
        std::cout << "---------------------------------" << std::endl;
        {
            try
            {
                Bureaucrat brt("Brt", 0);
                std::cout << brt << std::endl;
            }
            catch (std::exception &e)
            {
                std::cout << "exception: "<< e.what() << std::endl;
            }
        }

        std::cout << "Bloco com exception tratada grade low na criação" << std::endl;
        std::cout << "---------------------------------" << std::endl;
        {
            try{
                Bureaucrat btr("Magnata do petróleo", 151);
                std::cout << btr << std::endl;
            }
            catch(std::exception &e){
                std::cout << "exception: "<< e.what() << std::endl;
            }
        }


    return (0);
}