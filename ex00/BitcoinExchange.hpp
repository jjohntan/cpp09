/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:51:55 by jetan             #+#    #+#             */
/*   Updated: 2025/10/13 16:49:49 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <fstream>
#include <iostream>

class BitcoinExchange
{
private:
	std::map<std::string, float> _database;
public:
	BitcoinExchange();// Default constructor
	BitcoinExchange(const BitcoinExchange &other);// Copy constructor
	BitcoinExchange &operator=(const BitcoinExchange &other);// Copy assignment operator
	~BitcoinExchange();// Destructor
	void loadDataBase(const std::string &filename);
};

#endif