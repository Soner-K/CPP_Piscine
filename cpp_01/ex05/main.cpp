/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:07:16 by sokaraku          #+#    #+#             */
/*   Updated: 2024/11/25 14:20:02 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl	harlito;

	harlito.complain("DEBUG");
	harlito.complain("INFO");
	harlito.complain("WARNING");
	harlito.complain("ERROR");
	harlito.complain("");
	harlito.complain("OKOKO");
}