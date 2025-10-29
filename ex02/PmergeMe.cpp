/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:51:54 by jetan             #+#    #+#             */
/*   Updated: 2025/10/24 19:37:56 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void PmergeMe::printVector()
{
	for (std::vector<int>::iterator it = this->_vector.begin(); it < this->_vector.end(); it++)
		std::cout << *it << std::endl;
}

int PmergeMe::JacobsthalN(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	
	int a = 0;
	int b = 1;
	int res = 0;

	for (int i = 2; i <= n; ++i)
	{
		res = b + 2 * a;
		a = b;
		b = res;
	}
	return res;
}

void PmergeMe::fordJohnsonVector(std::vector<int> &_vector)
{
	if (_vector.size() < 2)
		return;
	// Divide into pairs, sort pairs
	std::vector<std::pair<int, int> > pairs;
	int leftover = -1;
	for (unsigned int i = 0; i < _vector.size() - 1; i += 2)
	{
		if (i + 1 < _vector.size())
		{
			// first element larger than second element
			if (_vector[i] > _vector[i + 1])
				pairs.push_back(std::make_pair(_vector[i + 1], _vector[i]));// first smaller second larger
			else
				pairs.push_back(std::make_pair(_vector[i], _vector[i + 1]));
		}
		else
			leftover = _vector[i];
	}

	std::vector<int> mainchain;
	std::vector<int> pend;

	// push smaller element to pend
	// push larger element to mainchain
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		pend.push_back(pairs[i].first);
		mainchain.push_back(pairs[i].second);
	}

	fordJohnsonVector(mainchain);

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
		for (unsigned int j = 0; j < arg.size(); j++)
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