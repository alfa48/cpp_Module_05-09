/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manandre <948manuel@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:17:33 by manandre          #+#    #+#             */
/*   Updated: 2026/03/10 19:10:39 by manandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char *av[]) {
    {
        if (ac != 2) {
            std::cerr << "Error: could not open file." << std::endl;
            return 1;
        }
        try {
            BitcoinExchange exchange;
            exchange.hendleExchangeRate(av[1]);
            
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
            return 1;
        }
    }
}
