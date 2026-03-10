/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manandre <948manuel@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 19:13:42 by manandre          #+#    #+#             */
/*   Updated: 2026/03/10 20:05:42 by manandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"   

int main(int ac, char *av[]) {
    {
        if (ac != 2) {
            std::cerr << "Error: could not open file." << std::endl;
            return 1;
        }
        try {
            RPN rpn(av[1]);
            
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
            return 1;
        }
    }
}