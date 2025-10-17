/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:43:06 by jetan             #+#    #+#             */
/*   Updated: 2025/10/17 16:17:16 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <cctype>
#include <sstream>
#include <stack>
#include <iostream>

class RPN
{
private:
	std::stack<int> _stack;
public:
	RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();
	void process(const std::string &expression);
	void handleOperations();
	
	bool isNumber(const std::string &token);
	bool isOperator(const std::string &token);
	// void printStack(std::stack<int> &_stack);
};

#endif