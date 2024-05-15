/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:23:16 by ycontre           #+#    #+#             */
/*   Updated: 2024/05/15 16:28:04 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	this->_name = name;
	this->_grade = grade;
	if (this->_grade < 1 || this->_grade > 150)
		throw std::invalid_argument("Grade must be between 1 and 150");
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	*this = src;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_grade = rhs._grade;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs)
{
	o << rhs.get_name() << ", bureaucrat grade " << rhs.get_grade();
	return o;
}

std::string	Bureaucrat::get_name() const
{
	return this->_name;
}

int	Bureaucrat::get_grade() const
{
	return this->_grade;
}

void	Bureaucrat::increment_grade()
{
	if (this->_grade == 1)
		throw std::out_of_range("Grade cannot be incremented");
	this->_grade--;
}

void	Bureaucrat::decrement_grade()
{
	if (this->_grade == 150)
		throw std::out_of_range("Grade cannot be decremented");
	this->_grade++;
}