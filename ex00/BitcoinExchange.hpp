/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:51:55 by jetan             #+#    #+#             */
/*   Updated: 2025/10/16 09:32:48 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <string>
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
	void loadDataBasecsv(const std::string &filename);
	void takeInput(const std::string &filename);
	float exchangeRate(std::map<std::string, float> &_database, const std::string &date);
	
	bool validFormat(const std::string &line, std::string &date, float &fvalue);
	bool validDate(std::string &date);
	bool validValue(float &fvalue);
	
	bool isLeapYear(unsigned int year);
};

#endif