/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:48:09 by dolifero          #+#    #+#             */
/*   Updated: 2024/11/12 17:22:43 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argv, char **argc)
{
	if(argv != 2)
	{
		std::cout << "Usage: ./convert [string]" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argc[1]);
	return 0;
}
