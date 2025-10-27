/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:51:54 by jetan             #+#    #+#             */
/*   Updated: 2025/10/27 20:28:54 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void PmergeMe::printVector()
{
	for (std::vector<int>::iterator it = this->_vector.begin(); it < this->_vector.end(); it++)
		std::cout << *it << std::endl;
}

void PmergeMe::fordJohnsonVector(std::vector<int> &_vector)
{
	if (_vector.size() < 2)
		return ;
	
	std::vector<std::pair<int, int>> pairs;
	
	for (int i = 0; i < _vector.size(); i += 2)
	{
		if (i + 1 < _vector.size())
		{
			pairs.push_back(std::make_pair(_vector[i], _vector[i + 1]));
		}
		else
		{
			
		}
	}
}

void PmergeMe::sort()
{
	fordJohnsonVector(_vector);
}

bool PmergeMe::takeInput(int ac, char **av)
{
	int n;
	for (int i = 1; i < ac; i++)
	{
		std::string arg = av[i];
		for (size_t j = 0; j < arg.size(); j++)
		{
			if (!std::isdigit(arg[j]))// check if is non char
				return false;
		}
		n = std::atoi(av[i]);
		if (n < 0)// check if non positive int
			return false;
		_vector.push_back(n);
		_deque.push_back(n);
	}
	return true;
}

PmergeMe::PmergeMe(): _vector(0), _deque(0) {}

PmergeMe::PmergeMe(const PmergeMe &other): _vector(other._vector),
_deque(other._deque) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vector = other._vector;
		_deque = other._deque;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}