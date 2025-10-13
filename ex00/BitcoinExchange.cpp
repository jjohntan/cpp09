/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:51:50 by jetan             #+#    #+#             */
/*   Updated: 2025/10/13 19:22:02 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void BitcoinExchange::loadDataBase(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}
	
	std::string line;
	std::getline(file, line);// skip the first line
	while (std::getline(file, line))
	{
		std::cout << line << std::endl;
	}
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		_database = other._database;
	}
	return *this;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other): _database(other._database)
{
	*this = other;
}

BitcoinExchange::BitcoinExchange(): _database() {}

BitcoinExchange::~BitcoinExchange() {}