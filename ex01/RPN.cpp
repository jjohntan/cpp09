/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:43:09 by jetan             #+#    #+#             */
/*   Updated: 2025/10/17 17:31:44 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// void RPN::printStack(std::stack<int> &_stack)
// {
// 	std::stack<int> tmp;
// 	while (!_stack.empty())
// 	{
// 		int element = _stack.top();
// 		std::cout << element << std::endl;
// 		tmp.push(element);
// 		_stack.pop();
// 	}
// }

bool RPN::isOperator(const std::string &token)
{
	return (token == "+" || token == "-" || token == "/" || token == "*");
}

bool RPN::isNumber(const std::string &token)
{
	return (token.size() == 1 && token >= "0" && token <= "9");
}

bool RPN::handleOperations(const std::string &opt)
{
	int b = _stack.top();// Access the top element
	_stack.pop();// Remove the last added element
	int a = _stack.top();
	_stack.pop();
	int res = 0;
	
	if (opt == "+")
		res = a + b;
	else if (opt == "-")
		res = a - b;
	else if (opt == "*")
		res = a * b;
	else if (opt == "/")
	{
		if (b == 0)
			return false;
		res = a / b;
	}
	else
	{
		return false;
	}
		
	_stack.push(res);
	return true;
}

void RPN::process(const std::string &expression)
{
	std::istringstream iss(expression);
	std::string token;
	
	while (iss >> token)
	{
		if (isNumber(token))
		{
			int num = token[0] - '0';// convert string to integer
			_stack.push(num);
		}
		else if (isOperator(token))
		{
			if (_stack.size() < 2)
			{
				std::cerr << "Error" << std::endl;
				return ;
			}
			if (!handleOperations(token))
			{
				std::cerr << "Error" << std::endl;
				return ;
			}
		}
		else
		{
			std::cerr << "Error" << std::endl;
			return ;
		}
	}
	// printStack(_stack);
	// check at least one result
	if (_stack.size() != 1)
	{
		std::cerr << "Error" << std::endl;
		return ;
	}
	// print result
	std::cout << _stack.top() << std::endl;
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