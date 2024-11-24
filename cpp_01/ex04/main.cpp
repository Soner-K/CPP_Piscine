/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:11:58 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/24 18:40:40 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

static void	replaceInLine(std::string& line, char *argv[])
{
	size_t	i = 0;

	while (i < line.length() && i != std::string::npos)
	{
		i = line.find(argv[2], i);
		if (i != std::string::npos)
		{
			line.erase(i, strlen(argv[2]));
			line.insert(i, argv[3]);
		}
	}
	return ;
}

bool	mySed(char *argv[])
{
	std::string		line;
	std::ifstream	inFile(argv[1]);
	if (!inFile.is_open())
	{
		std::cout << INPUT_FILE_FAIL;
		return (false);
	}
	std::ofstream	outFile((std::string(argv[1]) + ".replace").c_str());
	if (!outFile.is_open())
	{
		std::cout << OUTPUT_FILE_FAIL;
		return (false);
	}
	if (strlen(argv[2]) == 0)
	{
		std::cout << EMPTY_STRING;
		return (false);
	}
	while (std::getline(inFile, line))
	{
		if (!inFile.eof())
			line += '\n';
		replaceInLine(line, argv);
		outFile << line;
	}
	return (true);
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << WRONG_PARAMETERS;
		return (1);
	}
	mySed(argv);
	return (0);
}
