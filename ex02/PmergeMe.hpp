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

#include <utility>
#include <cctype>
#include <cstdlib>
#include <deque>
#include <vector>
#include <iostream>

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
	void printVector();
	void FordJohnson();
	void sortVector(std::vector<int> &arr, int pair_lvl);
};

#endif