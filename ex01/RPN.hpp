/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:43:06 by jetan             #+#    #+#             */
/*   Updated: 2025/10/17 15:20:51 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

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
	
	bool isNumber(std::string &token);
	bool isOperator(std::string &token);
};

#endif