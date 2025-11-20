/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:51:57 by jetan             #+#    #+#             */
/*   Updated: 2025/10/24 19:31:30 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_HPP
# define PMERGE_HPP

#include <algorithm>
#include <cmath>
#include <utility>
#include <cctype>
#include <cstdlib>
#include <deque>
#include <vector>
#include <iostream>

// counter for number of comparison
static int nbr_of_comps;

template <typename T>
T advanceIt(T it, int n)
{
	// increase operator untill n
	std::advance(it, n);
	return it;
}

template <typename T>
void swap_pair(T it, int pair_lvl)
{
	T start = advanceIt(it, -pair_lvl + 1);
	T end = advanceIt(start, pair_lvl);

	while (start != end)
	{
		std::iter_swap(start, advanceIt(start, pair_lvl));
		start++;
	}
}

template <typename T>
bool elementComp(T a, T b)
{
	nbr_of_comps++;
	return *a < *b;
}

/**
 * why is vector and deque- merge-insert sort repeatedly access elements by index
 */
class PmergeMe
{
	private:
	std::vector<int> _vector;
	std::deque<int> _deque;
	public:
	// Default constructor
	PmergeMe();
	// Copy constructor
	PmergeMe(const PmergeMe &other);
	// Copy assignment operator
	PmergeMe &operator=(const PmergeMe &other);
	// Destructor
	~PmergeMe();
	bool takeInput(int ac, char **av);
	void FordJohnson();
	long jacobsthalNbr(long n);	
	void sortVector(std::vector<int> &arr, int pair_lvl);
};

#endif