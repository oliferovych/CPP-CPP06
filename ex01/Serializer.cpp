/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:41:39 by dolifero          #+#    #+#             */
/*   Updated: 2024/11/13 15:45:39 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(Serializer const &other)
{
	if(this != &other)
		*this = other;
}

Serializer::~Serializer()
{
}

Serializer &Serializer::operator=(const Serializer &other)
{
	if(this != &other)
		*this = other;
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
	return raw;
}

Data *Serializer::deserialize(uintptr_t raw)
{
	Data *ptr = reinterpret_cast<Data *>(raw);
	return ptr;
}
