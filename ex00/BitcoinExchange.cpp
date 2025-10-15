/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:51:50 by jetan             #+#    #+#             */
/*   Updated: 2025/10/15 15:39:07 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool BitcoinExchange::validFormat(const std::string &line)
{
	if (line.find(" | ") == std::string::npos)
		return false;
	
	return true;
}

void BitcoinExchange::takeInput(const std::string &filename)
{
	std::ifstream ifs(filename.c_str());// input file stream
	
	if (!ifs.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}
	
	std::string line;
	std::getline(ifs, line);// skip the first line

	// Each line
	while (std::getline(ifs, line))
	{
		// std::cout << line << std::endl;
		if (!validFormat(line))
		{
			std::cerr << "Error: bad input => " << std::endl;// hhhhhhhhhhhhhhhhhhhhhhh
			continue;
		}
		std::stringstream ss(line);
		std::string date, value;
		std::getline(ss, date, '|');// extract the date
		// std::cout << "date: " << date << std::endl;
		std::getline(ss, value);// extract the value
		// std::cout << "value: " << value << std::endl;
		std::stringstream convert(value);
		float fvalue;
		convert >> fvalue;
		// _database[date] = fvalue;
		// std::cout << std::fixed << std::setprecision(2) << fvalue;
	}
	// evaluate();
}

void BitcoinExchange::loadDataBasecsv(const std::string &filename)
{
	std::ifstream ifs(filename.c_str());// input file stream
	
	if (!ifs.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}
	
	std::string line;
	std::getline(ifs, line);// skip the first line
	// Each line
	while (std::getline(ifs, line))
	{
		// std::cout << line << std::endl;
		std::stringstream ss(line);
		std::string date, value;
		std::getline(ss, date, ',');// extract the date
		// std::cout << "date: " << date << std::endl;
		std::getline(ss, value);// extract the value
		// std::cout << "value: " << value << std::endl;
		std::stringstream convert(value);
		float fvalue;
		convert >> fvalue;
		_database[date] = fvalue;
		// std::cout << std::fixed << std::setprecision(2) << fvalue;
	}
	// for (std::map<std::string, float>::iterator it = _database.begin(); it != _database.end(); it++)
	// {
	// 	std::cout << "date: " << it->first << " value: " << it->second << std::endl;
	// }
	ifs.close();
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