/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:51:52 by jetan             #+#    #+#             */
/*   Updated: 2025/10/24 19:29:24 by jetan            ###   ########.fr       */
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
	PmergeMe pmm;
	if (!pmm.takeInput(ac, av))
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	pmm.sort();
	// pmm.fordJohnsonVector();
}