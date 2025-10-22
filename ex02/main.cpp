/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:51:52 by jetan             #+#    #+#             */
/*   Updated: 2025/10/22 14:11:07 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	for (int i = 1; i < ac; i++)
	{
		std::string arg = av[i];
		for (unsigned int j = 0; j < arg.size(); j++)
		{
			if (!std::isdigit(arg[j]))// check if is non char
			{
				std::cerr << "Error" << std::endl;
				return 1;
			}
		}
		int n = std::atoi(av[i]);
		if (n < 0)// check if non positive int
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}
		std::cout << n;
	}
}