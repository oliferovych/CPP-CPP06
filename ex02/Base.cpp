/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 22:47:38 by dolifero          #+#    #+#             */
/*   Updated: 2024/11/14 23:23:45 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <random>

Base::~Base()
{
}

Base *generate(void)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 3);

	int random = dis(gen);
	std::cout << "Generated type: " << (char)(random + 'A' - 1) << std::endl;

	switch (random)
	{
	case 1:
		return new A();
	case 2:
		return new B();
	default:
		return new C();
	}
}

void identify(Base *p)
{
	A *a_ptr;
	B *b_ptr;
	C *c_ptr;

	std::cout << "Pointer type: ";
	if ((a_ptr = dynamic_cast<A *>(p)))
		std::cout << "A" << std::endl;
	else if ((b_ptr = dynamic_cast<B *>(p)))
		std::cout << "B" << std::endl;
	else if ((c_ptr = dynamic_cast<C *>(p)))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void identify(Base &p)
{
	std::cout << "Reference type: ";
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}catch (const std::bad_cast &){
		try
		{
			(void)dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
		}catch (const std::bad_cast &){
			try
			{
				(void)dynamic_cast<C &>(p);
				std::cout << "C" << std::endl;
			}catch (const std::bad_cast &){
				std::cout << "Unknown" << std::endl;
			}
		}
	}
}
