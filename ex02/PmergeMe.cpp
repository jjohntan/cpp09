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

void PmergeMe::swap_pair(std::vector<int>::iterator curr_pair, int pair_lvl)
{
	std::vector<int>::iterator start = curr_pair;
	std::advance(start, -pair_lvl + 1);
	std::vector<int>::iterator end = curr_pair;
	std::advance(end, pair_lvl);

	while (start != end)
	{
		std::vector<int>::iterator swap_ = start;
		std::advance(swap_, pair_lvl);
		std::iter_swap(start, swap_);
		start++;
	}
}

bool PmergeMe::larger_comp(std::vector<int>::iterator curr, std::vector<int>::iterator nxt)
{
	nbr_comp++;
	return *nxt < *curr;
}

void PmergeMe::sortVector(std::vector<int> &arr, int pair_lvl)
{
	std::vector<int>::iterator it;

	// calculate how many pair in level
	int pair_per_lvl = arr.size() / pair_lvl;
	if (pair_per_lvl < 2)
		return;
	
	// if is odd
	bool is_odd = pair_per_lvl % 2 == 1;

	// if (is_odd == true)
	// 	std::cout << "is odd" << std::endl;

	// iterator of start of container
	std::vector<int>::iterator start = arr.begin();
	// iterator after completed pair
	std::vector<int>::iterator after_pair = arr.begin();
	std::advance(after_pair, pair_lvl * pair_per_lvl);
	// iterator of last element
	std::vector<int>::iterator last_element = after_pair;

	if (is_odd)
		std::advance(last_element, -pair_lvl);

	int jump = 2 * pair_lvl;
	std::cout << "jump: " << jump << std::endl;

	for (std::vector<int>::iterator it = start; it != last_element; std::advance(it, jump))
	{
		// iterator of last element in current pair
		std::vector<int>::iterator curr_pair = it;
		std::advance(curr_pair, pair_lvl - 1);
		// iterator of last element in next pair
		std::vector<int>::iterator nxt_pair = it;
		std::advance(nxt_pair, pair_lvl * 2 - 1);

		if (larger_comp(curr_pair, nxt_pair))
		{
			swap_pair(curr_pair, pair_lvl);
		}
		// std::cout << "this_pair: " << *curr_pair << "\n";
        // std::cout << "next_pair: " << *nxt_pair << "\n";
	}

	sortVector(arr, pair_lvl * 2);

	
	_vector = arr;
}

void PmergeMe::FordJohnson()
{
	std::cout << "Before:  ";
	for (std::vector<int>::iterator it = this->_vector.begin(); it < this->_vector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	clock_t start_v = clock();
	sortVector(_vector, 1);
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