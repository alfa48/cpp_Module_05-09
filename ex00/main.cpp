/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manandre <948manuel@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:17:33 by manandre          #+#    #+#             */
/*   Updated: 2026/03/06 09:48:08 by manandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

int main(int ac, char *av[]) {
    (void)av;
    
    {
        std::map<int, char> m;

        m[10] = 'A';
        m[19] = 'B';
        m[10] = 'C';
        m[22] = 'D';
        m[30] = 'E';

        std::map<int,char>::iterator itUp = m.lower_bound(20);
        std::map<int,char>::iterator itLow = m.upper_bound(20);


        std::cout << (--itUp)->first << " -> " << itUp->second << std::endl;
        std::cout << (--itLow)->first << " -> " << itLow->second << std::endl;
        return 0;
    }
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
