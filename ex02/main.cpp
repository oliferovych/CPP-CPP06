/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 23:00:04 by dolifero          #+#    #+#             */
/*   Updated: 2024/11/14 23:12:29 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

int main(void)
{
	Base *base1 = generate();
	Base *base2 = generate();
	Base *base3 = generate();

	std::cout << "Identifying base1:" << std::endl;
	identify(base1);
	identify(*base1);
	std::cout << "Identifying base2:" << std::endl;
	identify(base2);
	identify(*base2);
	std::cout << "Identifying base3:" << std::endl;
	identify(base3);
	identify(*base3);

	delete base1;
	delete base2;
	delete base3;
	return 0;
}
