/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycontre <ycontre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:20:54 by ycontre           #+#    #+#             */
/*   Updated: 2024/05/15 15:58:49 by ycontre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	try_form(Form &form)
{
	Bureaucrat				big_boss("big_boss", 1);
	Bureaucrat				signing_boss("signing_boss", form.get_grade_signed());
	Bureaucrat				executing_boss("executing_boss", form.get_grade_executed());
	Bureaucrat				little_boss("little_boss", 150);

	try
	{
		big_boss.signForm(form);
		form.setSigned(false);
		little_boss.signForm(form);
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cerr << "ERROR : Caught an exception: " << e.what() << std::endl;
	}
	
	try {
		executing_boss.executeForm(form);
	}
	catch (Form::FormNotSignedException &e)
	{
		std::cerr << "ERROR : Caught an exception: " << e.what() << std::endl;
	}

	try {
		signing_boss.signForm(form);
		form.setSigned(false);
		signing_boss.executeForm(form);
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cerr << "ERROR : Caught an exception: " << e.what() << std::endl;
	}
	executing_boss.signForm(form);
	executing_boss.executeForm(form);
}

int	main(void)
{
	ShrubberyCreationForm	shrubbery("tree");
	RobotomyRequestForm		robotomy("robot_boy");
	PresidentialPardonForm	president("citizen");
	
	std::cout << "----------------------------------------------" << std::endl;
	try_form(shrubbery);
	std::cout << "----------------------------------------------" << std::endl;
	try_form(robotomy);
	std::cout << "----------------------------------------------" << std::endl;
	try_form(president);
	std::cout << "----------------------------------------------" << std::endl;


	return 0;
}