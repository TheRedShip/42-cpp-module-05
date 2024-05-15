/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:13:49 by ycontre           #+#    #+#             */
/*   Updated: 2024/05/15 16:46:25 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.h"

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs)
{
	o << rhs.get_name() << " form, need " << rhs.get_grade_signed() << " to signed and " << rhs.get_grade_executed() << " to be executed";
	return o;
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return "Grade is too low";
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return "Grade is too high";
}

Form::Form(std::string name, int grade_signed, int grade_executed)
	: _name(name), _grade_signed(grade_signed), _grade_executed(grade_executed), _signed(false)
{
	if (this->_grade_signed < 1 || this->_grade_executed < 1)
		throw Form::GradeTooHighException();
	if (this->_grade_signed > 150 || this->_grade_executed > 150)
		throw Form::GradeTooLowException();
}

Form::~Form(){}

Form::Form(const Form &src) : _name(src._name), _grade_signed(src._grade_signed), _grade_executed(src._grade_executed) {}

Form &Form::operator=(const Form &rhs)
{
	if (this != &rhs)
		this->_signed = rhs._signed;
	return *this;
}

std::string	Form::get_name() const
{
	return this->_name;
}

bool	Form::get_signed() const
{
	return this->_signed;
}

int	Form::get_grade_signed() const
{
	return this->_grade_signed;
}

int	Form::get_grade_executed() const
{
	return this->_grade_executed;
}

void	Form::beSigned(Bureaucrat &b)
{
	if (b.get_grade() > this->_grade_signed)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

