/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:50:42 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/22 09:42:04 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream> 
#include <ctime>

# define BLUE 	 "\033[34m"
# define NEUTRAL "\033[0m"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) :
_amount(initial_deposit)
{
	_displayTimestamp();
	this->_accountIndex = _nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	_nbAccounts++;
	std::cout
	<< "index:" << BLUE << this->_accountIndex << NEUTRAL
	<< ";amount:" << BLUE << _amount << NEUTRAL
	<< ";created\n";
	return ;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout
	<< "index:" << BLUE << this->_accountIndex << NEUTRAL
	<< ";amount:" << BLUE << this->_amount << NEUTRAL
	<< ";closed\n";
	_nbAccounts--;
	if (_nbAccounts == 0)
		std::cout << "\n";
	return ;
}

int		Account::getNbAccounts(void) { return (_nbAccounts); } 

int		Account::getTotalAmount(void) { return (_totalAmount); }

int		Account::getNbDeposits(void) { return (_totalNbDeposits); }

int		Account::getNbWithdrawals(void) { return (_totalNbWithdrawals); }

void 	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	this->_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout
	<< "index:" << BLUE << this->_accountIndex << NEUTRAL
	<< ";p_amount:" << BLUE << this->_amount << NEUTRAL
	<< ";deposit:" << BLUE << deposit << NEUTRAL
	<< ";amount:" << BLUE << this->_amount + deposit << NEUTRAL
	<< ";nb_deposits:" << BLUE << this->_nbDeposits << NEUTRAL
	<< "\n";
	this->_amount += deposit;
	return ;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout
	<< "accounts:" << BLUE << _nbAccounts << NEUTRAL
	<< ";total:" << BLUE << _totalAmount << NEUTRAL
	<< ";deposits:" BLUE << _totalNbDeposits << NEUTRAL
	<< ";withdrawals:" BLUE << _totalNbWithdrawals << NEUTRAL
	<< "\n";
	return ;
}

bool 	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout
	<< "index:" << BLUE << this->_accountIndex << NEUTRAL
	<< ";p_amount:" << BLUE << this->_amount << NEUTRAL;
	if (withdrawal > this->_amount)
	{
		std::cout << ";withdrawal:refused\n";
		return (false);
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout << ";withdrawal:" << BLUE << withdrawal << NEUTRAL
	<< ";amount:" << BLUE << this->_amount << NEUTRAL
	<< ";nb_withdrawals:" << BLUE << this->_nbWithdrawals << NEUTRAL
	<< "\n";
	return (true);
}

int		Account::checkAmount(void) const { return (this->_amount); }

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout
	<< "index:" << BLUE << this->_accountIndex << NEUTRAL
	<< ";amount:" << BLUE << this->_amount << NEUTRAL
	<< ";deposits:" << BLUE << this->_nbDeposits << NEUTRAL
	<< ";withdrawals:" << BLUE << this->_nbWithdrawals << NEUTRAL
	<< "\n";
	return ;
}

void	Account::_displayTimestamp(void)
{
    std::time_t now = std::time(NULL);
    std::tm* local_time = std::localtime(&now);

    char buffer[20];
    std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", local_time);
    std::cout << "[" << buffer << "] ";
}