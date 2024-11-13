/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:48:09 by dolifero          #+#    #+#             */
/*   Updated: 2024/11/13 15:51:29 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data data;
	uintptr_t raw;

	data.s1 = "Hello";
	data.n = 42;
	std::cout << "Data address: " << &data << std::endl;
	std::cout << "Data values:" << std::endl;
	std::cout << data.s1 << std::endl;
	std::cout << data.n << std::endl;
	raw = Serializer::serialize(&data);
	std::cout << "Raw pointer value: " << raw << std::endl;
	Data *ptr = Serializer::deserialize(raw);
	std::cout << "Deserialized address: " << ptr << std::endl;
	std::cout << "Deserialized values:\n";
	std::cout << ptr->s1 << std::endl;
	std::cout << ptr->n << std::endl;
	return 0;
}
