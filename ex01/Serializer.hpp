/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:27:28 by dolifero          #+#    #+#             */
/*   Updated: 2024/11/13 15:46:23 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include "Data.h"

class Serializer
{
	private:
		Serializer();
		Serializer(Serializer const & other);
		~Serializer();
		Serializer &operator=(const Serializer &other);
	public:
		static uintptr_t serialize(Data* ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif
