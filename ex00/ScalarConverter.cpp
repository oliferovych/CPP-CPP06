/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:19:39 by dolifero          #+#    #+#             */
/*   Updated: 2024/11/12 17:15:15 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	if(this != &src)
		*this = src;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	if(this != &other)
		*this = other;
	return *this;
}

bool isIntOverflow(std::string str)
{
	if(str.length() > 10)
		return true;
	if(str.length() == 10)
	{
		if(str[0] == '-' && str > "-2147483648")
			return true;
		if(str[0] != '-' && str > "2147483647")
			return true;
	}
	return false;
}

bool isNum(std::string str)
{
	int i = 0;
	bool dot = false;
	if(str[0] == '-' || str[0] == '+')
		i++;
	while(str[i])
	{
		if(str[i] == '.')
		{
			if(dot)
				return false;
			dot = true;
			i++;
		}
		if(i == (int)(str.length() - 1) && str[i] == 'f')
			return true;
		if(!isdigit(str[i]))
			return false;
		i++;
	}
	return true;
}

std::string get_type(std::string str)
{
	if(str == "nanf" || str == "-inff" || str == "+inff" || str == "inff")
		return "float";
	if(str == "nan" || str == "-inf" || str == "+inf" || str == "inf")
		return "double";
	if(str.length() == 1)
	{
		if(std::isdigit(str[0]))
			return "int";
		return "char";
	}
	size_t fPos = str.find('f') == str.length() - 1 ? str.length() - 1 : std::string::npos;
	size_t pPos = str.find('.') == str.length() - 1 || 0 ? std::string::npos : str.find('.');
	if(str.length() > 1 && isNum(str) && fPos == std::string::npos && pPos == std::string::npos)
		return "int";
	if(str.length() > 1 && isNum(str) && pPos != std::string::npos && fPos == std::string::npos)
		return "double";
	if(str.length() > 1 && isNum(str) && pPos != std::string::npos && fPos == str.length() - 1)
		return "float";
	return "invalid";
}

void print_out(std::string c, std::string i, std::string f, std::string d)
{
	if(c[0] < 32 || c[0] > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << std::endl;
	std::cout << "double: " << d << std::endl;
}

void print_converted(std::string str, std::string type)
{
	if(type == "float" && (str == "nanf" || str == "-inff" || str == "+inff" || str == "inff"))
	{
		str.pop_back();
		return print_out("impossible", "impossible", str + "f", str);
	}
	if(type == "double" && (str == "nan" || str == "-inf" || str == "+inf" || str == "inf"))
		return print_out("impossible", "impossible", str + "f", str);
	if(type == "char")
	{
		int i = static_cast<int>(str[0]);
		float f = static_cast<float>(i);
		double d = static_cast<double>(i);
		print_out(str, std::to_string(i), std::to_string(f) + "f", std::to_string(d));
	}
	if(type == "int")
	{
		if(isIntOverflow(str))
			type = "double";
		else
		{
			int i = std::stoi(str);
			char c = static_cast<char>(i);
			float f = static_cast<float>(i);
			double d = static_cast<double>(i);
			print_out( d < 0 || d > 255 ? "Impossible" : std::string(1, c),
				isIntOverflow(str) ? "Impossible" : std::to_string(i), std::to_string(f) + "f", std::to_string(d));
		}
	}
	if(type == "double")
	{
		double d = std::stod(str);
		int i = static_cast<int>(d);
		char c = static_cast<char>(i);
		float f = static_cast<float>(d);
		print_out( d < 0 || d > 255 ? "Impossible" : std::string(1, c),
			isIntOverflow(str) ? "Impossible" : std::to_string(i), std::to_string(f) + "f", std::to_string(d));
	}
	if(type == "float")
	{
		float f = std::stof(str);
		int i = static_cast<int>(f);
		char c = static_cast<char>(i);
		double d = static_cast<double>(f);
		print_out(f < 0 || f > 255 ? "Impossible" : std::string(1, c),
			isIntOverflow(str) ? "Impossible" : std::to_string(i), std::to_string(f) + "f", std::to_string(d));
	}
	if(type == "invalid")
		std::cout << "Invalid input" << std::endl;
}

void ScalarConverter::convert(std::string str)
{
	std::string type = get_type(str);
	std::cout << "Type: " << type << std::endl;
	print_converted(str, type);
}
