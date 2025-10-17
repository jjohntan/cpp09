/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:43:09 by jetan             #+#    #+#             */
/*   Updated: 2025/10/17 15:24:34 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool RPN::isOperator(std::string &token)
{
	return (token == "+" || token == "-" || token == "/" || token == "*");
}

// bool isNumber(std::string &token)
// {
	
// }

void RPN::process(const std::string &expression)
{
	std::istringstream iss(expression);
	std::string token;
	
	while (iss >> token)
	{
		// if (isNumber(token))
		
		if (isOperator(token))
		{
			std::cout << "isOperator" << std::endl;
		}
	}
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		_stack = other._stack;
	}
	return *this;
}

RPN::RPN(const RPN &other): _stack(other._stack) {}

RPN::RPN() {}

RPN::~RPN() {}