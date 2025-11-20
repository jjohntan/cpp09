/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:51:50 by jetan             #+#    #+#             */
/*   Updated: 2025/10/16 14:43:39 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool BitcoinExchange::isLeapYear(unsigned int year)
{
	if (year % 400)
		return true;
	if (year % 100)
		return false;
	if (year % 4)
		return true;
	return false;
}

float BitcoinExchange::exchangeRate(std::map<std::string, float> &_database, const std::string &date)
{
	// Returns an iterator to the element with greater than or equal to date
	std::map<std::string, float>::iterator it = _database.lower_bound(date);
	// date is later than any key or no exact match found
	if (it == _database.end() || it->first != date)
	{
		// if not found, step one backward
		if (it == _database.begin())
			return -1;
		--it;
	}
	// return value
	return it->second;
}

bool BitcoinExchange::validValue(float &fvalue)
{
	if (fvalue < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	if (fvalue > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}

bool BitcoinExchange::validDate(std::string &date)
{
	std::string str_year, str_month, str_day;
	std::stringstream ss(date);
	
	// extract year, month, and day
	if (!std::getline(ss, str_year, '-') || !std::getline(ss, str_month, '-') || !std::getline(ss, str_day, '-'))
		return false;
	
	std::stringstream year_ss(str_year), month_ss(str_month), day_ss(str_day);
	unsigned int year, month, day;
	
	// convert to unsigned int
	year_ss >> year;
	month_ss >> month;
	day_ss >> day;
	
	unsigned int monthlen[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	
	if (!year || !month || !day || month > 12)
		return false;
	if (isLeapYear(year) || month == 2)
		monthlen[1]++;
	if (day > monthlen[month - 1])
		return false;
	return true;
}

/**
 * Each line in this file must use the following format: "date | value".
 * A valid date will always be in the following format: Year-Month-Day.
 * A valid value must be either a float or a positive integer, between 0 and 1000.
 */
bool BitcoinExchange::validFormat(const std::string &line, std::string &date, float &fvalue)
{
	if (line.find(" | ") == std::string::npos)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return false;
	}
	std::string value;
	std::stringstream ss(line);
	std::getline(ss, date, '|');// extract the date
	std::getline(ss, value);// extract the value
	
	if (date.empty() || value.empty())
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return false;
	}
	
	std::stringstream convert(value);
	
	if (!(convert >> fvalue))
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return false;
	}
	
	if (!validDate(date))
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return false;
	}
	
	if (!validValue(fvalue))
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
	if (!std::getline(ifs, line))// skip the first line
	{
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}
	
	if (line != "date | value")
	{
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}

	// Each line
	while (std::getline(ifs, line))
	{
		// std::cout << line << std::endl;
		std::string date;
		float fvalue;
		if (!validFormat(line, date, fvalue))
			continue;
		float rate = exchangeRate(_database, date);
		if (rate < 0)
			continue;
		// print result
		std::cout << date << " => " << fvalue << " = " << fvalue * rate << std::endl;
	}
	ifs.close();
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
		std::getline(ss, value);// extract the value
		std::stringstream convert(value);
		float fvalue;
		convert >> fvalue;
		_database[date] = fvalue;
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