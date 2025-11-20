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

long PmergeMe::jacobsthalNbr(long n)
{
	return round((pow(2, n + 1) + pow(-1, n)) / 3);
}

void PmergeMe::sortDeque(std::deque<int> &arr, int pair_lvl)
{
	typedef std::deque<int>::iterator deq_it;

	int element_lvl = arr.size() / pair_lvl;
	if (element_lvl < 2)
		return;
	
	bool is_odd = element_lvl % 2 == 1;

	deq_it start = arr.begin();
	deq_it after_pair = advanceIt(arr.begin(), pair_lvl * (element_lvl));
	deq_it last_element = advanceIt(after_pair, -(is_odd * pair_lvl));

	int jump = 2 * pair_lvl;

	for (deq_it it = start; it != last_element; std::advance(it, jump))
	{
		deq_it b = advanceIt(it, pair_lvl - 1);
		deq_it a = advanceIt(it, pair_lvl * 2 - 1);

		if (elementComp(a, b))
		{
			swap_pair(b, pair_lvl);
		}
	}

	sortDeque(arr, pair_lvl * 2);

	std::vector<deq_it> mainchain;
	std::vector<deq_it> pend;
	
	mainchain.insert(mainchain.end(), advanceIt(arr.begin(), pair_lvl - 1));
	mainchain.insert(mainchain.end(), advanceIt(arr.begin(), pair_lvl * 2 - 1));

	for (int i = 4; i <= element_lvl; i += 2)
	{
		pend.insert(pend.end(), advanceIt(arr.begin(), pair_lvl * (i - 1) - 1));
		mainchain.insert(mainchain.end(), advanceIt(arr.begin(), pair_lvl * i - 1));
	}

	if (is_odd)
	{
		pend.insert(pend.end(), advanceIt(last_element, pair_lvl - 1));
	}

	int prev_jacob = jacobsthalNbr(1);
	int inserted_nbr = 0;

	for (int k = 2;; k++)
	{
		int curr_jacob = jacobsthalNbr(k);

		int jacob_diff = curr_jacob - prev_jacob;

		int bound_shift = 0;

		if (jacob_diff > static_cast<int>(pend.size()))
			break;

		int curr_inserted_nbr = jacob_diff;
		std::vector<deq_it>::iterator pend_it = advanceIt(pend.begin(), jacob_diff - 1);
		std::vector<deq_it>::iterator bound_it = advanceIt(mainchain.begin(), curr_jacob + inserted_nbr);

		while (curr_inserted_nbr)
		{
			std::vector<deq_it>::iterator insertion_point =
			 std::upper_bound(mainchain.begin(), bound_it, *pend_it, elementComp<deq_it>);// functor<type>

			std::vector<deq_it>::iterator inserted = mainchain.insert(insertion_point, *pend_it);
			curr_inserted_nbr--;
			pend_it = pend.erase(pend_it);
			std::advance(pend_it, -1);
			
			bound_shift += (inserted - mainchain.begin()) == curr_jacob + inserted_nbr;
			bound_it = advanceIt(mainchain.begin(), curr_jacob + inserted_nbr - bound_shift);
		}
		prev_jacob = curr_jacob;
		inserted_nbr += jacob_diff;
		bound_shift = 0;
	}

	for (int i = pend.size() - 1; i >= 0; i--)
	{
		std::vector<deq_it>::iterator curr_pend = advanceIt(pend.begin(), i);
		std::vector<deq_it>::iterator curr_bound = advanceIt(mainchain.begin(), mainchain.size() - pend.size() + i + is_odd);
		std::vector<deq_it>::iterator insertion_point =
		 std::upper_bound(mainchain.begin(), curr_bound, *curr_pend, elementComp<deq_it>);
		mainchain.insert(insertion_point, *curr_pend);
	}

	std::vector<int> copy;
	copy.reserve(arr.size());
	for (std::vector<deq_it>::iterator it = mainchain.begin(); it != mainchain.end(); it++)
	{
		for (int i = 0; i < pair_lvl; i++)
		{
			deq_it pair_start = *it;
			std::advance(pair_start, -pair_lvl + i + 1);
			copy.insert(copy.end(), *pair_start);
		}
	}
	
	deq_it arr_it = arr.begin();
	std::vector<int>::iterator copy_it = copy.begin();
	while (copy_it != copy.end())
	{
		*arr_it = *copy_it;
		arr_it++;
		copy_it++;
	}
}

void PmergeMe::sortVector(std::vector<int> &arr, int pair_lvl)
{
	// pointing to int inside arr
	typedef std::vector<int>::iterator vec_it;

	// calculate how many element in the level
	int element_lvl = arr.size() / pair_lvl;
	// std::cout << "array size: " << arr.size() << " / pair level: "<< pair_lvl << " element in the level: " << element_lvl << std::endl;
	if (element_lvl < 2)
		return;
	
	// if is total odd elements
	bool is_odd = element_lvl % 2 == 1;
	// if (is_odd == true)
	// 	std::cout << "is odd" << std::endl;

	// iterator of start of container
	vec_it start = arr.begin();
	// std::cout << "start: " << *start << std::endl;

	// iterator after completed pair
	vec_it after_pair = advanceIt(arr.begin(), pair_lvl * (element_lvl));
	// std::cout << "after pair: " << *after_pair << std::endl;

	// iterator of last element
	vec_it last_element = advanceIt(after_pair, -(is_odd * pair_lvl));
	// std::cout << "last element: " << *last_element << std::endl;

	int jump = 2 * pair_lvl;
	// std::cout << "jump: " << jump << std::endl;

	// loop through each pair element
	for (vec_it it = start; it != last_element; std::advance(it, jump))
	{
		// (1-1=0), (2-1=1), (4-1=3)
		vec_it b = advanceIt(it, pair_lvl - 1);
		// std::cout << "b: " << *b << std::endl;
		
		// (1*2-1=1), (2*2-1=3), (4*2-1=7)
		vec_it a = advanceIt(it, pair_lvl * 2 - 1);
		// std::cout << "a: " << *a << std::endl;

		// if a is smaller than b
		if (elementComp(a, b))
		{
			swap_pair(b, pair_lvl);
		}
		// std::cout << "after swap b: " << *b << std::endl;
        // std::cout << "after swap a: " << *a << std::endl;
	}

	sortVector(arr, pair_lvl * 2);

	// std::cout << "after finished pair and swap: ";
	// for (std::vector<int>::iterator it = arr.begin(); it < arr.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;

	std::vector<vec_it> mainchain;
	std::vector<vec_it> pend;
	
	// initialize mainchain the last element of pair
	mainchain.insert(mainchain.end(), advanceIt(arr.begin(), pair_lvl - 1));
	mainchain.insert(mainchain.end(), advanceIt(arr.begin(), pair_lvl * 2 - 1));

	// std::cout << "init mainchain: ";
	// for (std::vector<vec_it>::iterator it = mainchain.begin(); it < mainchain.end(); it++)
	// 	std::cout << **it << " ";
	// std::cout << std::endl;

	// insert rest of b into pend, a into mainchain
	for (int i = 4; i <= element_lvl; i += 2)
	{
		pend.insert(pend.end(), advanceIt(arr.begin(), pair_lvl * (i - 1) - 1));
		mainchain.insert(mainchain.end(), advanceIt(arr.begin(), pair_lvl * i - 1));
	}

	// insert leftover odd element to the end of pend
	if (is_odd)
	{
		pend.insert(pend.end(), advanceIt(last_element, pair_lvl - 1));
		// std::cout << "is odd pend: ";
		// for (std::vector<std::vector<int>::iterator>::iterator it = pend.begin(); it != pend.end(); ++it)
	    // 	std::cout << **it << " ";
		// std::cout << std::endl;
	}

	// start from jacobsthal J(1)
	int prev_jacob = jacobsthalNbr(1);
	// std::cout << "prev_jacob: " << prev_jacob << std::endl;

	// how many elements inserted
	int inserted_nbr = 0;

	// ;; infinite loop
	// insert pend using jacobsthal
	for (int k = 2;; k++)
	{
		// next jacobsthal number J(k)
		int curr_jacob = jacobsthalNbr(k);
		// std::cout << "current jacob: " << curr_jacob << std::endl;

		// how many new elements insert in this loop J(k) - J(k-1)
		int jacob_diff = curr_jacob - prev_jacob;
		// std::cout << "jacob difference: " << jacob_diff << std::endl;

		int bound_shift = 0;

		// break if not enough element in pend for current jacobsthal number
		if (jacob_diff > static_cast<int>(pend.size()))
			break;

		// how many will be inserted in this loop
		int curr_inserted_nbr = jacob_diff;
		// std::cout << "current inserted number: " << curr_inserted_nbr << std::endl;

		// the last element of the current Jacobsthal group inside pend
		//  2 , 1  e.g.jacob_diff=2
		// [B1, B2, B3, B4]
		std::vector<vec_it>::iterator pend_it = advanceIt(pend.begin(), jacob_diff - 1);

		// sets the upper search boundary for binary search
		std::vector<vec_it>::iterator bound_it = advanceIt(mainchain.begin(), curr_jacob + inserted_nbr);

		while (curr_inserted_nbr)
		{
			// binary search insertion point for current pend element
			std::vector<vec_it>::iterator insertion_point =
			 std::upper_bound(mainchain.begin(), bound_it, *pend_it, elementComp<vec_it>);// functor<type>
			// std::cout << "insertion point: " << **insertion_point << std::endl;

			// insert element into mainchain
			std::vector<vec_it>::iterator inserted = mainchain.insert(insertion_point, *pend_it);
			curr_inserted_nbr--;
			// remove the element from pend
			pend_it = pend.erase(pend_it);
			// move back one position to get the next element
			std::advance(pend_it, -1);
			
			bound_shift += (inserted - mainchain.begin()) == curr_jacob + inserted_nbr;
			// std::cout << "bound_shift: " << bound_shift << std::endl;

			bound_it = advanceIt(mainchain.begin(), curr_jacob + inserted_nbr - bound_shift);
			// std::cout << "bound_it: " << **bound_it << std::endl;
		}
		// after finishing the group shift previous jacob forward
		prev_jacob = curr_jacob;
		// std::cout << "after finishing previous jacob: " << prev_jacob << std::endl;
		// how many pend element inserted
		inserted_nbr += jacob_diff;
		// std::cout << "inserted_nbr: " << inserted_nbr << std::endl;
		bound_shift = 0;
	}

	// insert the elements that left after insertion of Jacobsthal sequence
	for (int i = pend.size() - 1; i >= 0; i--)
	{
		std::vector<vec_it>::iterator curr_pend = advanceIt(pend.begin(), i);
		std::vector<vec_it>::iterator curr_bound = advanceIt(mainchain.begin(), mainchain.size() - pend.size() + i + is_odd);
		std::vector<vec_it>::iterator insertion_point =
		 std::upper_bound(mainchain.begin(), curr_bound, *curr_pend, elementComp<vec_it>);
		// insert the element from pend to mainchain
		mainchain.insert(insertion_point, *curr_pend);
	}

	// right now mainchain only contain iterator pointing to element
	// use copy vector to store value of iterator
	std::vector<int> copy;
	// allocate memory size same as arr(pre-malloc)
	copy.reserve(arr.size());
	for (std::vector<vec_it>::iterator it = mainchain.begin(); it != mainchain.end(); it++)
	{
		for (int i = 0; i < pair_lvl; i++)
		{
			vec_it pair_start = *it;// iterator to the element of mainchain
			std::advance(pair_start, -pair_lvl + i + 1);// (,move to the start of the pair)
			copy.insert(copy.end(), *pair_start);
		}
	}
	
	// overwrite the value in container
	vec_it arr_it = arr.begin();
	std::vector<int>::iterator copy_it = copy.begin();
	while (copy_it != copy.end())
	{
		*arr_it = *copy_it;
		arr_it++;
		copy_it++;
	}
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
	double time_v = (double)(end_v - start_v) / CLOCKS_PER_SEC;

	nbr_of_comps = 0;
	clock_t start_d = clock();
	sortDeque(_deque, 1);
	clock_t end_d = clock();
	double time_d = (double)(end_d - start_d) / CLOCKS_PER_SEC;

	std::cout << "After:   ";
	for (std::vector<int>::iterator it = this->_vector.begin(); it < this->_vector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : "
	 << std::fixed << std::setprecision(5) << time_v << " us" << std::endl;

	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque  : "
	 << std::fixed << std::setprecision(5) << time_d << " us" << std::endl;
	std::cout << "number of comparison: " << nbr_of_comps << std::endl;
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
