/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:51:50 by jetan             #+#    #+#             */
/*   Updated: 2025/10/15 19:43:08 by jetan            ###   ########.fr       */
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

bool BitcoinExchange::validDate(std::string &date)
{
	std::string str_year, str_month, str_day;
	std::stringstream ss(date);
	
	if (!std::getline(ss, str_year, '-') || !std::getline(ss, str_month, '-') || !std::getline(ss, str_day, '-'))
		return false;
	
	std::stringstream year_ss(str_year), month_ss(str_month), day_ss(str_day);
	unsigned int year, month, day;
	
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

bool BitcoinExchange::validFormat(const std::string &line, std::string &date)
{	
	std::stringstream ss(line);
	std::getline(ss, date, '|');// extract the date
	// Each line check following format: "date | value"
	if (line.find(" | ") == std::string::npos)
		return false;
	if (!validDate(date))
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
		std::string date, value;
		if (!validFormat(line, date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}
		std::stringstream ss(line);
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