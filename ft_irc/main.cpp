/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lps <lps@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:08:09 by lps               #+#    #+#             */
/*   Updated: 2024/09/23 17:08:10 by lps              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Server.hpp"

int main(int argc, char **argv)
{
    int port;
    
    if (argc != 3)
    {
        std::cout << "Usage: ./irc PORT PASSWORD." << std::endl; 
        return (1);
    }

    port = atoi(argv[1]);
    if (port < 1024 || port > 65535)
    {
        std::cout << "Port number has to be a value from 1024 to 65535." << std::endl; 
        exit(1);
    }

    if (strlen(argv[2]) > 10 || strlen(argv[2]) < 5)
    {
        std::cout << RED << "Server password must contain 5-10 characters." << RESET << std::endl; 
        exit(1);
    }
 
    try
    {
        Server irc(port, argv[2]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}