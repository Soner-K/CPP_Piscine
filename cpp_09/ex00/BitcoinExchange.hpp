/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:38:57 by sokaraku          #+#    #+#             */
/*   Updated: 2025/05/22 20:39:20 by sokaraku         ###   ########.fr       */
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
#include <stdio.h>

#include <algorithm>

using std::map;
using std::string;

# define DATABASE "data.csv"

class BitcoinExchange
{
	private:
			
		map<long, float>			_file;
		string						_filename;
	
		unsigned char						_sep;

		void				storeDatabaseIntoMap(string database);
		void				parseOneLine(string line, unsigned int current_line_nb);
		void				checkBitcoinValidity(string& bitcoin, unsigned int current_line_nb);
		void				checkDateValidity(string& date, unsigned int current_line_nb);
		void				storeLine(string& line, string& date);
	
		void				handleInputFile(string filepath);
		void				handleOneLine(string line, unsigned int current_line_nb);
		void				findValueAt(string& date, float nb,  unsigned int current_line_nb);

		void				getSeparatorFromDatabase(string line);
	public:
		
							BitcoinExchange( void );
							BitcoinExchange(const BitcoinExchange& other);
							BitcoinExchange(const string filepath);
							~BitcoinExchange( void );
		BitcoinExchange& 	operator=(const BitcoinExchange& rhs);

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
void	getValuesFromDate(string& s, unsigned int current_line_nb, long* year, long* month, long* day);