/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:38:57 by sokaraku          #+#    #+#             */
/*   Updated: 2025/04/21 19:51:30 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include <map>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include <exception>

#include <cstdlib>
#include <errno.h>
#include <string.h>

#include <algorithm>

using std::map;
using std::string;

# define DATABASE "data.csv"

# define YEAR 1
# define MONTH 2
# define DAY 3

class BitcoinExchange
{
	private:
			
		map<long, float>			_file;
		string						_filename;
	
		void				storeDatabaseIntoMap(string database);
		void				storeOneLine(string line, unsigned int current_line_nb);
		
		void				handleInputFile(string filepath);
		void				handleOneLine(string line, unsigned int current_line_nb);
		void				checkDateValidity(string& date, unsigned int current_line_nb);
		void				findValueAt(string& date, float nb,  unsigned int current_line_nb);

	public:
		
							BitcoinExchange( void );
							BitcoinExchange(const BitcoinExchange& other);
							BitcoinExchange(const string& filepath);
							~BitcoinExchange( void );
		BitcoinExchange& 	operator==(const BitcoinExchange& rhs);

};

class BitcoinException : public std::exception
{
	private:
				string _error_msg;
	public:
				BitcoinException(string error_msg);
				~BitcoinException( void ) throw();
				const virtual char* what() const throw();
};

std::ostream& operator<<(std::ostream& os, const std::map<std::string, float>& map);

string	itostr(unsigned int n);
long	getValueFromDate(string& s, char format, unsigned int current_line_nb);