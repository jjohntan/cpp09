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

// std::vector<int> PmergeMe::JacobsthalNbr(int n)
// {
// 	std::vector<int> res;

// 	if (n == 0)
// 		return res;
// 	res.push_back(1);
// 	if (n == 1)
// 		return res;
	
// 	int a = 1, b = 1;

// 	while (b < n)
// 	{
// 		int buff = b;
// 		b = b + 2 * a;
// 		a = buff;
// 		if (b > n)// stop if exceed n
// 			break;
// 		res.push_back(b);// add to sequence
// 	}
// 	return res;
// }

// void PmergeMe::sortVector(std::vector<int> &arr)
// {
// 	if (arr.size() < 2)
// 		return;
// 	// Divide into pairs, sort pairs
// 	std::vector<std::pair<int, int> > pairs;
// 	int leftover = -1;
// 	bool hasleftover = false;

// 	for (unsigned int i = 0; i < arr.size() - 1; i += 2)
// 	{
// 		if (i + 1 < arr.size())
// 		{
// 			// first element larger than second element
// 			if (arr[i] > arr[i + 1])
// 			{
// 				// first element smaller second element larger
// 				pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
// 			}
// 			else
// 			{
// 				pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
// 			}
// 		}
// 		else
// 		{
// 			hasleftover = true;
// 			leftover = arr[i];
// 		}
// 	}

// 	std::vector<int> mainchain;
// 	std::vector<int> pend;

// 	// push smaller element to pend
// 	// push larger element to mainchain
// 	for (size_t i = 0; i < pairs.size(); ++i)
// 	{
// 		pend.push_back(pairs[i].first);
// 		mainchain.push_back(pairs[i].second);
// 	}

// 	// recursive
// 	sortVector(mainchain);

// 	// generate Jacobsthal number
// 	std::vector<int> insert = JacobsthalNbr(pend.size());

// 	for ()
// 	{

// 	}
	
// 	if (hasleftover)
// 	{

// 	}

// 	// add sorted number in mainchain to container
// 	_vector = mainchain;
// }

void PmergeMe::FordJohnson()
{
	std::cout << "Before:  ";
	for (std::vector<int>::iterator it = this->_vector.begin(); it < this->_vector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	clock_t start_v = clock();
	// sortVector(_vector);
	clock_t end_v = clock();
	double time_v = (double)(end_v - start_v) / CLOCKS_PER_SEC * 1000000;

	clock_t start_d = clock();
	
	clock_t end_d = clock();
	double time_d = (double)(end_d - start_d) / CLOCKS_PER_SEC * 1000000;
	std::cout << "After:   ";
	for (std::vector<int>::iterator it = this->_vector.begin(); it < this->_vector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << 5 << " elements with std::vector : "
	 << time_v << " us" << std::endl;
	std::cout << "Time to process a range of " << 5 << " elements with std::deque  : "
	 << time_d << " us" << std::endl;
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