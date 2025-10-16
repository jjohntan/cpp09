/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:43:09 by jetan             #+#    #+#             */
/*   Updated: 2025/10/16 18:09:10 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void RPN::process(const std::string &expression)
{
	std::istringstream iss(expression);
	std::string token;
	
	while (iss >> token)
	{
		
	}
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		_container = other._container;
	}
	return *this;
}

RPN::RPN(const RPN &other): _container(other._container) {}

RPN::RPN() {}

RPN::~RPN() {}